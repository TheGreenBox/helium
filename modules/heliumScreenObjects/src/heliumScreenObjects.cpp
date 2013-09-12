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

// --------------- screen obj world implementation --------
ScreenObjectsWorld::ScreenObjectsWorld ()
    : engineScreen(new Polycode::PhysicsScreen()) {
}

ScreenObjectsWorld::~ScreenObjectsWorld () {
    engineScreen->Shutdown();
    
    for ( ObjectIterator it = objects.begin();
            it != objects.end(); ++it ) {
        delete reinterpret_cast<P::ScreenEntity*>(*it);
    }
    for ( AlifeIterator itl = alifeObjects.begin();
            itl != alifeObjects.end(); ++itl ) {
        delete reinterpret_cast<P::ScreenEntity*>(itl->first);
        delete itl->second;
    }
}

void ScreenObjectsWorld::lifeStep() {
    for ( AlifeIterator it = alifeObjects.begin();
            it != alifeObjects.end(); ++it ) {
        it->second->lifeStep();
    }
}

bool ScreenObjectsWorld::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
	P::ScreenEntity* entity = engineScreen->getEntityAtPosition(mouse.x, mouse.y);
    
    // TODO !! wrap it to inline function!
    IHeliumObjectsWorld::ObjectsIdType id = 
        reinterpret_cast< IHeliumObjectsWorld::ObjectsIdType >(entity);

    AlifeIterator ait = alifeObjects.find(id);
    if (ait != alifeObjects.end() ) {
        ait->second->mouseClick(upDown);
        return true;
    }
    return false;
}
    
void ScreenObjectsWorld::setPause(bool set) {
    engineScreen->enabled = set;
}

bool ScreenObjectsWorld::getPause() {
    return engineScreen->enabled;
}

IHeliumObjectsWorld::ObjectsIdType 
ScreenObjectsWorld::addObject( PackagedScreenObject* obj ) {
    switch( obj->getEntityType() ) {
    case PackagedScreenObject::ENTITY_IMMATERIAL:
        engineScreen->addChild( obj->getModel() );
    break;
    case PackagedScreenObject::ENTITY_COLLISION_ONLY:
        engineScreen->addCollisionChild( obj->getModel(), obj->getShapeType() );
    break;
    case PackagedScreenObject::ENTITY_PHYSICAL:
        engineScreen->addPhysicsChild( obj->getModel(), obj->getShapeType(), false );
    break;
    default:
        throw "Create correct exeption class!";
    }
    
    if ( obj->isAlife() != 0 ) {
        alifeObjects.insert( obj->getAlifePair() );
    }
    else {
        objects.insert( obj->getId() );
    }
    return obj->getId();
}

void ScreenObjectsWorld::signOutObject( IHeliumObjectsWorld::ObjectsIdType id ) {
    ObjectIterator it = objects.find(id);
    if ( it != objects.end() ) {
        P::ScreenEntity* pObj = reinterpret_cast<P::ScreenEntity*>(id);
            
        engineScreen->removeChild( pObj );
        delete pObj;
        objects.erase(it);
    }
    else {
        AlifeIterator ait = alifeObjects.find(id);
        if (ait != alifeObjects.end() ) {
            P::ScreenEntity* pObj = reinterpret_cast<P::ScreenEntity*>(id);
                
            engineScreen->removeChild( pObj );
            delete pObj;
            delete ait->second;
            alifeObjects.erase(ait);
        }
    }
}

