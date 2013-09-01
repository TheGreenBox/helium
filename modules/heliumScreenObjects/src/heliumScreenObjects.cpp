/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumScreenObjects.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include <Polycode.h>
#include "heliumScreenObjects.h"

ScreenObject::ScreenObject( Polycode::ScreenEntity* _model )
    :   model(_model) {}

Polycode::ScreenEntity* ScreenObject::getModel() {
    return model;
}

AlifeScreenObject::AlifeScreenObject( Polycode::ScreenEntity* _model )
    :   ScreenObject(_model) {}

ScreenObjectsWorld::ScreenObjectsWorld ()
    : engineScreen(new Polycode::Screen()) {
}

ScreenObjectsWorld::~ScreenObjectsWorld () {
    engineScreen->Shutdown();
}

void ScreenObjectsWorld::lifeStep() {
    using std::list;
    for ( list< AlifeScreenObject* >::iterator it = aliveObjects.begin();
            it != aliveObjects.end(); ++it ) {
        (*it)->lifeStep();
    }
}

bool ScreenObjectsWorld::mouseLeftClick(Polycode::Vector2 position) {

}

bool ScreenObjectsWorld::mouseRightClick(Polycode::Vector2 position) {

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
    engineScreen->addEntity( obj->getModel() );
    aliveObjects.push_back(obj);
}

