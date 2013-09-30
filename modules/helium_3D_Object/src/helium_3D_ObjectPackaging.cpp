/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  helium_3D_ObjectPackaging.cpp
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <iostream>
//#include <cmath>

#include "Polycode.h"
#include "helium_3D_ObjectPackaging.h"

namespace P = Polycode;

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
    
//SceneObjectsWorld::AlifePairType PackagedSceneObject::getAlifePair()const {
//    return SceneObjectsWorld::AlifePairType (
//            reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(heliumObject->getModel()),
//            heliumObject );
//}
    
IHeliumObjectsWorld::ObjectsIdType PackagedSceneObject::getId()const {
    return heliumObject->getId();
}
    
Polycode::SceneEntity* PackagedSceneObject::getModel()const {
    return heliumObject->getModel();
}

bool PackagedSceneObject::getToMousePointQueue()const {
    return addToMousePointQueue;
}

