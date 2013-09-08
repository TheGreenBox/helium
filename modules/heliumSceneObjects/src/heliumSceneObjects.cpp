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

#include <Polycode.h>
#include "heliumSceneObjects.h"

namespace P = Polycode;

SceneObjectsWorld::SceneObjectsWorld()
    : engineScene(new Polycode::PhysicsScene()) {
    engineScene->clearColor = Polycode::Color(1,1,1,1);
    engineScene->useClearColor = true;
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
    for ( AlifeIterator it = alifeObjects.begin();
            it != alifeObjects.end(); ++it ) {
        it->second->lifeStep();
    }
}

bool SceneObjectsWorld::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
//	P::SceneEntity* entity = engineScene->getEntityAtPosition(mouse.x, mouse.y);
//    
//    // TODO !! wrap it to inline function!
//    IHeliumObjectsWorld::ObjectsIdType id = 
//        reinterpret_cast< IHeliumObjectsWorld::ObjectsIdType >(entity);
//
//    SceneObjectsWorld::AlifeIterator ait = alifeObjects.find(id);
//    if (ait != alifeObjects.end() ) {
//        ait->second->mouseClick(upDown);
//        return true;
//    }
    return false;
}

IHeliumObjectsWorld::ObjectsIdType 
SceneObjectsWorld::addObject( PackagedSceneObject* obj ) { 
    switch ( obj->getShapeType() ) {
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
                                          obj->getRestitution(), 
                                          obj->getCompoundChildren());
        
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
            alifeObjects.erase(ait);
            delete ait->second;
        }
    }
}

int PackagedSceneObject::isAlife()const {
    return alife;
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

