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

AlifeScreenObject::AlifeScreenObject( Polycode::ScreenEntity* _model )
{}

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
ScreenObjectsWorld::addObject( PackagedScreenObject& obj ) {
    engineScreen->addChild( obj.getModel() );
    objects.insert( obj.getId() );
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
            alifeObjects.erase(ait);
        }
    }
}

IHeliumObjectsWorld::ObjectsIdType 
ScreenObjectsWorld::addAlifeObject( PackagedAlifeScreenObject& obj ) {
    engineScreen->addCollisionChild( obj.getModel(), obj.getEntityType() );
    alifeObjects.insert( obj.getAlifePair() );
}

//AlifeScreenObject* ScreenObjectsWorld::getAlifeObject( P::ScreenEntity* entity ) {
//    using std::list;
//    
//    for ( set< AlifeScreenObject* >::iterator itl = alifeObjects.begin();
//            itl != alifeObjects.end(); ++itl ) {
//        if ( (*itl)->getModel() == entity ) {
//            return *itl;
//        }
//    }
//    return NULL;
//}

