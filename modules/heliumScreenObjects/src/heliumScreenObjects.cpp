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

ScreenObject::ScreenObject( Polycode::ScreenEntity* _model )
    :   model(_model) {}

ScreenObject::~ScreenObject() {
    delete model;
}

Polycode::ScreenEntity* ScreenObject::getModel() {
    return model;
}

AlifeScreenObject::AlifeScreenObject( Polycode::ScreenEntity* _model )
    : ScreenObject(_model) {}

ScreenObjectsWorld::ScreenObjectsWorld ()
    : engineScreen(new Polycode::PhysicsScreen()) {
}

ScreenObjectsWorld::~ScreenObjectsWorld () {
    engineScreen->Shutdown();
    
    for ( std::set< ScreenObject* >::iterator it = objects.begin();
            it != objects.end(); ++it ) {
        delete reinterpret_cast<P::ScreenEntity*>(*it);
    }
    for ( std::map< AlifeScreenObject* >::iterator itl = aliveObjects.begin();
            itl != aliveObjects.end(); ++itl ) {
        delete reinterpret_cast<P::ScreenEntity*>(*itl->first);
        delete itl->second;
    }
}

void ScreenObjectsWorld::lifeStep() {
    for ( AlifeIterator it = aliveObjects.begin();
            it != aliveObjects.end(); ++it ) {
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

ScreenObjectsWorld::HeliumObjectsIdType 
ScreenObjectsWorld::addObject( PackagedScreenObject& obj ) {
    engineScreen->addChild( obj.getModel() );
    objects.push_back( obj.getId() );
}

void ScreenObjectsWorld::signOutObject( HeliumObjectsIdType id ) {
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
            objects.erase(ait);
        }
}

void ScreenObjectsWorld::addAlifeObject( PackagedAlifeScreenObject& obj ) {
    engineScreen->addCollisionChild( obj.getModel(), obj.getEntityType() );
    aliveObjects.push_back( obj.getAlifePair() );
}

//AlifeScreenObject* ScreenObjectsWorld::getAlifeObject( P::ScreenEntity* entity ) {
//    using std::list;
//    
//    for ( set< AlifeScreenObject* >::iterator itl = aliveObjects.begin();
//            itl != aliveObjects.end(); ++itl ) {
//        if ( (*itl)->getModel() == entity ) {
//            return *itl;
//        }
//    }
//    return NULL;
//}

