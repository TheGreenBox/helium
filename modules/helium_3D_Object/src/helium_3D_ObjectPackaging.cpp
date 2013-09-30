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

Packaged_3D_Object::Packaged_3D_Object()
    :   character(NULL),
        mass(0),  friction(1),
        restitution(0),  group(1),
        compoundChildren(false) 
{}

IHeliumPackaging::ObjectEntityType Packaged_3D_Object::getEntityType()const {
    return entityType;
}

int Packaged_3D_Object::getShapeType () {
    return shapeType;
}
    
Number Packaged_3D_Object::getMass () {
    return mass;
}
    
Number Packaged_3D_Object::getFriction () {
    return friction;
}
    
Number Packaged_3D_Object::getRestitution () {
    return restitution;
}

int Packaged_3D_Object::getGroup () {
    return group;
}

bool Packaged_3D_Object::getCompoundChildren () {
    return compoundChildren;
}
    
Polycode::SceneEntity* Packaged_3D_Object::getModel() {
    return character->getModel();
}

