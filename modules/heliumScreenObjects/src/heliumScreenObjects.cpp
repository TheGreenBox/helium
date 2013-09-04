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
    :   ScreenObject(_model) {}

ScreenObjectsWorld::ScreenObjectsWorld ()
    : engineScreen(new Polycode::PhysicsScreen()) {
}

ScreenObjectsWorld::~ScreenObjectsWorld () {
    for ( std::list< ScreenObject* >::iterator it = objects.begin();
            it != objects.end(); ++it ) {
        delete *it;
    }
    for ( std::list< AlifeScreenObject* >::iterator itl = aliveObjects.begin();
            itl != aliveObjects.end(); ++itl ) {
        delete *itl;
    }
    engineScreen->Shutdown();
}

void ScreenObjectsWorld::lifeStep() {
    for ( std::list< AlifeScreenObject* >::iterator it = aliveObjects.begin();
            it != aliveObjects.end(); ++it ) {
        (*it)->lifeStep();
    }
}

bool ScreenObjectsWorld::mouseClick( int button, bool upDown, P::Vector2 mouse ) {
	P::ScreenEntity* entity = engineScreen->getEntityAtPosition(mouse.x, mouse.y);
    if ( entity == NULL ) {
        return false;
    }

    if ( button == 0 ) {
        AlifeScreenObject* obj = this->getAlifeObject(entity);
        if ( obj != NULL ) {
            obj->mouseClick(upDown);
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}
    
void ScreenObjectsWorld::setPause(bool set) {
    engineScreen->enabled = set;
}

bool ScreenObjectsWorld::getPause() {
    return engineScreen->enabled;
}

void ScreenObjectsWorld::addObject( ScreenObject* obj ) {
    engineScreen->addEntity( obj->getModel() );
    objects.push_back(obj);
}

void ScreenObjectsWorld::signOutObject( ScreenObject* obj) {
    // FIXME !!!
    using std::list;
    for ( list< ScreenObject* >::iterator it = objects.begin();
            it != objects.end(); ++it ) {
        if ( (*it) == obj ) {
            engineScreen->removeChild( (*it)->getModel() );
            objects.erase(it);
            return;
        }
    }
    for ( list< AlifeScreenObject* >::iterator itl = aliveObjects.begin();
            itl != aliveObjects.end(); ++itl ) {
        if ( (*itl) == obj ) {
            engineScreen->removeChild( (*itl)->getModel() );
            aliveObjects.erase(itl);
            return;
        }
    }
}

void ScreenObjectsWorld::addAlifeObject( AlifeScreenObject* obj ) {
    engineScreen->addCollisionChild( obj->getModel(), P::PhysicsScreenEntity::ENTITY_RECT );
    aliveObjects.push_back(obj);
}

AlifeScreenObject* ScreenObjectsWorld::getAlifeObject( P::ScreenEntity* entity ) {
    using std::list;
    for ( list< AlifeScreenObject* >::iterator itl = aliveObjects.begin();
            itl != aliveObjects.end(); ++itl ) {
        if ( (*itl)->getModel() == entity ) {
            return *itl;
        }
    }
    return NULL;
}
