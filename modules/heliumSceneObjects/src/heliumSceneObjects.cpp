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
    
    P::Quaternion quat = engineScene->getDefaultCamera()->getRotationQuat();
    std::cout << "q: " << quat.w << " : " << quat.x << " : " << quat.y << " : " << quat.z << " : " << "\n";
    P::Vector3 vx(1,0,0);
    P::Vector3 vy(0,1,0);
    P::Vector3 vz(0,0,1);
    P::Vector3 v (1,1,1);
    
    vx = quat.applyTo(vx);   
    vy = quat.applyTo(vy);
    vz = quat.applyTo(vz);
    v  = quat.applyTo(v );

    std::cout << "vx: " << vx.x << ' ' << vx.y << ' ' << vx.z << '\n';
    std::cout << "vy: " << vy.x << ' ' << vy.y << ' ' << vy.z << '\n';
    std::cout << "vz: " << vz.x << ' ' << vz.y << ' ' << vz.z << '\n';
    std::cout << "v : " << v.x  << ' ' << v.y  << ' ' << v.z << "\n\n";
    
    //engineScene->getDefaultCamera()->setRotationQuat(quat.w+0.1, quat.x, quat.y, quat.z);
    static double angle = 0; 
    P::Vector3 pos = engineScene->getDefaultCamera()->getPosition();
    pos.x = 20 * std::sin(angle);
    pos.z = 20 * std::cos(angle);
    angle += 0.001;
    engineScene->getDefaultCamera()->setPosition(pos);
    //engineScene->getDefaultCamera()->lookAt(P::Vector3(0,0,0));
     
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

bool SceneObjectsWorld::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
    
    P::RayTestResult res = SceneObjectsWorld::rayTest(mouse);
    if (res.entity) {
        std::cout << "yes! ";
    }
    IHeliumObjectsWorld::ObjectsIdType id = 
        reinterpret_cast< IHeliumObjectsWorld::ObjectsIdType >(res.entity);
    std::cout << id << ' ';
    SceneObjectsWorld::AlifeIterator ait = alifeObjects.find(id);
    if (ait != alifeObjects.end() ) {
        //ait->second->mouseClick(upDown);
        std::cout << "Hit it!\n";
        return true;
    }
    std::cout << "You miss! Keep to try!\n";
    return false;
}

IHeliumObjectsWorld::ObjectsIdType 
SceneObjectsWorld::addObject( PackagedSceneObject* obj ) { 
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
        break;
    }
    
    if ( obj->isAlife() != 0 ) {
        alifeObjects.insert( obj->getAlifePair() );
    }
    else {
        objects.insert( obj->getId() );
    }
    return obj->getId();
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

void SceneObjectsWorld::setCameraMovingDirection(Polycode::Vector2 dir) {
    //engineScene->getDefaultCamera()->getTransformMatrix();
    //engineScene->getDefaultCamera()->setPosition(17,17,17);
    //engineScene->getDefaultCamera()->getPosition(17,17,17);
    //engineScene->getDefaultCamera()->setPosition(17,17,17);
    //horisontalVectorMove = dir;
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
            reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(heliumAlife->getModel()),
            heliumAlife );
}
    
IHeliumObjectsWorld::ObjectsIdType PackagedSceneObject::getId()const {
    return reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(heliumAlife->getModel());
}
    
Polycode::SceneEntity* PackagedSceneObject::getModel()const {
    return heliumAlife->getModel();
}

