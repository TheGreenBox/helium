/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumSceneObjects.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <iostream>
#include <cmath>
#include <Polycode.h>
#include "heliumSceneObjects.h"

namespace P = Polycode;

SceneObject::SceneObject( P::SceneEntity* _model ) 
    : model(_model) {}

IHeliumObjectsWorld::ObjectsIdType SceneObject::getId() const {
    return reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(model);
}

SceneObjectsWorld::SceneObjectsWorld()
    : engineScene(new P::PhysicsScene()) {
    engineScene->clearColor = P::Color(1,1,1,1);
    engineScene->useClearColor = true;
    engineScene->getDefaultCamera()->setPosition(17,17,17);
    engineScene->getDefaultCamera()->lookAt(P::Vector3(0,0,0));
}

SceneObjectsWorld::~SceneObjectsWorld() {
    for ( ObjectIterator it = objects.begin();
            it != objects.end(); ++it ) {
        P::SceneEntity* entity = reinterpret_cast<P::SceneEntity*>(*it);
        engineScene->removeEntity(entity);
        delete entity;
    }
    for ( AlifeIterator itl = alifeObjects.begin();
            itl != alifeObjects.end(); ++itl ) {
        P::SceneEntity* entity = reinterpret_cast<P::SceneEntity*>(itl->first);
        engineScene->removeEntity(entity);
        delete entity;
        delete itl->second;
    }
}

void SceneObjectsWorld::lifeStep() {
    checkDelayedSignOutObject();
    P::Vector3 pos = engineScene->getDefaultCamera()->getPosition();
    pos.x += horisontalVectorMove.x;
    pos.z += horisontalVectorMove.y;
    engineScene->getDefaultCamera()->setPosition(pos);
     
    for ( AlifeIterator it = alifeObjects.begin();
            it != alifeObjects.end(); ++it ) {
        it->second->lifeStep();
    }
}


P::RayTestResult SceneObjectsWorld::rayTest(P::Vector2 mouse) {
    P::Vector3 dir = 
    P::CoreServices::getInstance()->getRenderer()->projectRayFrom2DCoordinate( 
                         mouse.x, mouse.y,
                         P::CoreServices::getInstance()->getRenderer()->getCameraMatrix(),
                         engineScene->getDefaultCamera()->getProjectionMatrix() );
    return engineScene->getFirstEntityInRay(engineScene->getDefaultCamera()->getPosition(), dir * 100);               
}

IHeliumObjectsWorld::ObjectsIdType
SceneObjectsWorld::getObjectIdByEntity(P::SceneEntity* entity)const { 
    return reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(entity);
}

void SceneObjectsWorld::addObjectToMousePointQueue(IHeliumObjectsWorld::ObjectsIdType id) {
    if ( id != 0 ) {
        queueToMousePoint.insert(id);
    }
}  

bool SceneObjectsWorld::checkQueueToMousePointClick( int button, bool upDown, P::Vector2 mouse ) {
    if ( ! queueToMousePoint.empty() ) {
        for ( ObjectIterator it = queueToMousePoint.begin();
                it != queueToMousePoint.end(); ++it ) {
            AlifeIterator ait = alifeObjects.find(*it);
            if (ait != alifeObjects.end() ) {
                ait->second->mousePoint( button, upDown, mouse );
            }
            queueToMousePoint.erase(it);
        }
        return true;
    }
    else {
        return false;
    }
}

bool SceneObjectsWorld::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
    if ( checkQueueToMousePointClick(button, upDown, mouse) ) {
        return true;
    }
    
    P::RayTestResult res = SceneObjectsWorld::rayTest(mouse);
    if (res.entity) {
        std::cout << "yes!\n";
    }
    IHeliumObjectsWorld::ObjectsIdType id = 
        reinterpret_cast< IHeliumObjectsWorld::ObjectsIdType >(res.entity);
    std::cout << id << ' ';
    AlifeIterator ait = alifeObjects.find(id);
    if (ait != alifeObjects.end() ) {
        ait->second->mouseClick(button, upDown);
        return true;
    }
    std::cout << "You miss! Keep to try!\n";
    return false;
}

void SceneObjectsWorld::addPackagedToEngineScene( PackagedSceneObject* obj ) {
    if( obj->getModel() ) { 
        switch ( obj->getEntityType() ) {
        case PackagedSceneObject::POLY_ENTITY_IMMATERIAL:
            engineScene->addChild(obj->getModel());
        break;

        case PackagedSceneObject::POLY_ENTITY_COLLISION_ONLY:
            engineScene->addCollisionChild( obj->getModel(),   
                                            obj->getShapeType() ); 
        break;

        case PackagedSceneObject::POLY_ENTITY_PHYSICAL:
            engineScene->addPhysicsChild( obj->getModel(), obj->getShapeType(),
                                          obj->getMass(), obj->getFriction(),
                                          obj->getRestitution() );
        break;

        default:
            throw "Addition secene child without idetificator";
        }
    }   
}

IHeliumObjectsWorld::ObjectsIdType SceneObjectsWorld::addObject( PackagedSceneObject* obj ) { 
    
    addPackagedToEngineScene(obj);
    
    if ( obj->isAlife() != 0 ) {
        alifeObjects.insert(obj->getAlifePair());
    }
    else {
        objects.insert(obj->getId());
    }
    if ( obj->getToMousePointQueue() ) {
        addObjectToMousePointQueue(obj->getId());  
    }
    
    IHeliumObjectsWorld::ObjectsIdType id = obj->getId();
    delete obj;
    obj = NULL;
    
    return id;
}

void SceneObjectsWorld::setPause(bool set) {
    engineScene->setEnabled(set);
}

bool SceneObjectsWorld::getPause() {
    return engineScene->isEnabled();
}

void SceneObjectsWorld::signOutObject( IHeliumObjectsWorld::ObjectsIdType id ) {
    ObjectIterator it = objects.find(id);
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
    }
}

void SceneObjectsWorld::delayedSignOut( IHeliumObjectsWorld::ObjectsIdType id ) {
    delayedSignOutObjects.push_back(id);
}

void SceneObjectsWorld::checkDelayedSignOutObject() {
    if ( !delayedSignOutObjects.empty() ) {
        for ( std::list< IHeliumObjectsWorld::ObjectsIdType >::iterator it =
               delayedSignOutObjects.begin(); it != delayedSignOutObjects.end(); ++it ) {
            signOutObject( *it );
        }
    }
}

void SceneObjectsWorld::cameraHorizonMovingDirection(Polycode::Vector2 dir) {
    P::Vector3 spaceMove(dir.x, 0, dir.y);
    P::Quaternion quat = engineScene->getDefaultCamera()->getRotationQuat();
    spaceMove = quat.applyTo(spaceMove);
    horisontalVectorMove.x = spaceMove.x;
    horisontalVectorMove.y = spaceMove.z;
}

void SceneObjectsWorld::warpTo( IHeliumObjectsWorld::ObjectsIdType id, Polycode::Vector3 point, bool resetRotation) {
    P::SceneEntity* pObj = NULL;
    
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
    engineSceneWarpTo(pObj, point, resetRotation);
}

void SceneObjectsWorld::engineSceneWarpTo( P::SceneEntity* obj, Polycode::Vector3 point, bool resetRotation ) {
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

PackagedSceneObject::PackagedSceneObject()
    :   heliumObject(NULL),  alife(0),
        mass(0),  friction(1),
        restitution(0),  group(1),
        compoundChildren(false),
        addToMousePointQueue(false) {
}

int PackagedSceneObject::isAlife()const {
    return alife;
}

PackagedSceneObject::PolySceneEntityType PackagedSceneObject::getEntityType()const {
    return entityType;
}

int PackagedSceneObject::getShapeType () {
    return shapeType;
}
    
Number PackagedSceneObject::getMass () {
    return mass;
}
    
Number PackagedSceneObject::getFriction () {
    return friction;
}
    
Number PackagedSceneObject::getRestitution () {
    return restitution;
}

int PackagedSceneObject::getGroup () {
    return group;
}

bool PackagedSceneObject::getCompoundChildren () {
    return compoundChildren;
}
    
SceneObjectsWorld::AlifePairType PackagedSceneObject::getAlifePair()const {
    return SceneObjectsWorld::AlifePairType (
            reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(heliumObject->getModel()),
            heliumObject );
}
    
IHeliumObjectsWorld::ObjectsIdType PackagedSceneObject::getId()const {
    return heliumObject->getId();
}
    
Polycode::SceneEntity* PackagedSceneObject::getModel()const {
    return heliumObject->getModel();
}

bool PackagedSceneObject::getToMousePointQueue()const {
    return addToMousePointQueue;
}

