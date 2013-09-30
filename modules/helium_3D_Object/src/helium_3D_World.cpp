/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_3D_World.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include <iostream> 
#include "helium_3D_World.h"

namespace P = Polycode;

Helium_3D_World::Helium_3D_World()
    : engineScene(new P::PhysicsScene()) {
    engineScene->clearColor = P::Color(1,1,1,1);
    engineScene->useClearColor = true;
    engineScene->getDefaultCamera()->setPosition(17,17,17);
    engineScene->getDefaultCamera()->lookAt(P::Vector3(0,0,0));
}

Helium_3D_World::~Helium_3D_World() {
    delete engineScene;
}

void Helium_3D_World::cameraStep() {
    P::Vector3 pos = engineScene->getDefaultCamera()->getPosition();
    pos.x += horisontalVectorMove.x;
    pos.z += horisontalVectorMove.y;
    engineScene->getDefaultCamera()->setPosition(pos);
}

void Helium_3D_World::lifeStep() {
    cameraStep();
    characters.lifeStep();
}

P::RayTestResult Helium_3D_World::rayTest(P::Vector2 mouse) {
    P::Vector3 dir = 
    P::CoreServices::getInstance()->getRenderer()->projectRayFrom2DCoordinate( 
                         mouse.x, mouse.y,
                         P::CoreServices::getInstance()->getRenderer()->getCameraMatrix(),
                         engineScene->getDefaultCamera()->getProjectionMatrix() );
    return engineScene->getFirstEntityInRay(engineScene->getDefaultCamera()->getPosition(), dir * 100);               
}

bool Helium_3D_World::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
    
    P::RayTestResult res = Helium_3D_World::rayTest(mouse);
    if (res.entity) {
        std::cout << "yes!\n";
    }
    //IHeliumObjectsWorld::ObjectsIdType id = 
    //    reinterpret_cast< IHeliumObjectsWorld::ObjectsIdType >(res.entity);
    //std::cout << id << ' ';
    //AlifeIterator ait = alifeObjects.find(id);
    //if (ait != alifeObjects.end() ) {
    //    ait->second->mouseClick(button, upDown);
    //    return true;
    //}
    //std::cout << "You miss! Keep to try!\n";
    return false;
}

void Helium_3D_World::addPackagedToEngineScene( Packaged_3D_Object* obj ) {
    if( obj->getModel() ) { 
        switch ( obj->getEntityType() ) {
        case IHeliumPackaging::ENTITY_IMMATERIAL:
            engineScene->addChild(obj->getModel());
        break;

        case IHeliumPackaging::ENTITY_COLLISION_ONLY:
            engineScene->addCollisionChild( obj->getModel(),   
                                            obj->getShapeType() ); 
        break;

        case IHeliumPackaging::ENTITY_PHYSICAL:
            engineScene->addPhysicsChild( obj->getModel(), obj->getShapeType(),
                                          obj->getMass(), obj->getFriction(),
                                          obj->getRestitution() );
        break;

        default:
            throw "Addition secene child without idetificator";
        }
    }   
}

Polycode::SceneEntity* Helium_3D_World::addObject( Packaged_3D_Object* obj ) { 
    
    addPackagedToEngineScene(obj);
    
   // if ( obj->isAlife() != 0 ) {
   //     alifeObjects.insert(obj->getAlifePair());
   // }
   // else {
   //     objects.insert(obj->getId());
   // }
    #warning fix me //FIXME
    return obj->getModel();
}

void Helium_3D_World::setPause(bool set) {
    engineScene->setEnabled(set);
}

bool Helium_3D_World::getPause() {
    return engineScene->isEnabled();
}

void Helium_3D_World::signOutObject( Polycode::SceneEntity* id ) {
/*    ObjectIterator it = objects.find(id);
    if ( it != objects.end() ) {
        P::SceneEntity* pObj = reinterpret_cast<P::SceneEntity*>(id);
            
        engineScene->removeEntity( pObj );
        delete pObj;
        objects.erase(it);
    }
    else {
        AlifeIterator ait = alifeObjects.find(id);
        if (ait != alifeObjects.end() ) {
            P::SceneEntity* pObj = reinterpret_cast<P::SceneEntity*>(id);
                
            engineScene->removeEntity( pObj );
            delete pObj;
            delete ait->second;
            alifeObjects.erase(ait);
        }
    }*/
}

void Helium_3D_World::setCameraHorizonMoving( const Polycode::Vector2& dir ) {
    P::Vector3 spaceMove(dir.x, 0, dir.y);
    P::Quaternion quat = engineScene->getDefaultCamera()->getRotationQuat();
    spaceMove = quat.applyTo(spaceMove);
    horisontalVectorMove.x = spaceMove.x;
    horisontalVectorMove.y = spaceMove.z;
}

void Helium_3D_World::warpTo( Polycode::SceneEntity* entity, Polycode::Vector3 point, bool resetRotation) {
    /*P::SceneEntity* pObj = NULL;
    
    ObjectIterator it = objects.find(id);
    if ( it != objects.end() ) {
        pObj = reinterpret_cast<P::SceneEntity*>(id);
    }
    else {
        AlifeIterator ait = alifeObjects.find(id);
        if (ait != alifeObjects.end() ) {
            pObj = reinterpret_cast<P::SceneEntity*>(id);
        }
    }
    engineSceneWarpTo(pObj, point, resetRotation);*/
    #warning fix me //FIXME
}

void Helium_3D_World::engineSceneWarpTo( P::SceneEntity* obj, Polycode::Vector3 point, bool resetRotation ) {
    if( obj ) {
        P::PhysicsSceneEntity *physicsEntity = engineScene->getPhysicsEntityBySceneEntity(obj);
        
        if(physicsEntity) {
            physicsEntity->rigidBody->setActivationState(DISABLE_DEACTIVATION); 
            physicsEntity->warpTo(point, resetRotation);
        }
        else {
            obj->setPosition(point);
        }
    }
}
