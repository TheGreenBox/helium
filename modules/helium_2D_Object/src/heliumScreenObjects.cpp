/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumScreenObjects.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#include <iostream>
#include <algorithm>

#include <Polycode.h>
#include <Polycode2DPhysics.h>
#include "heliumScreenObjects.h"

namespace P = Polycode;

// --------------- Screen Object implementation --------
ScreenObject::ScreenObject( Polycode::ScreenEntity* _model )
    : model (_model)
{}

// --------------- Packaged Screen Object implementation --------
Polycode::ScreenEntity* PackagedScreenObject::getModel()const {
    return heliumAlife->getModel();
}

ScreenObjectsWorld::AlifePairType PackagedScreenObject::getAlifePair()const {
    return ScreenObjectsWorld::AlifePairType(
            reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(this->getModel()),
            heliumAlife );
}

IHeliumObjectsWorld::ObjectsIdType PackagedScreenObject::getId()const {
    return reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(this->getModel());
}

PackagedScreenObject::ScreenEntityType
PackagedScreenObject::getEntityType()const {
    return entityType;
}

int PackagedScreenObject::getShapeType()const {
    return entityShapeType;
}

int PackagedScreenObject::isAlife ()const {
    return alife;
}

