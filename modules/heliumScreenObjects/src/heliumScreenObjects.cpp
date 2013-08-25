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
    std::cout << "engineScreen->enabled: " << engineScreen->enabled << '\n';
}

ScreenObjectsWorld::~ScreenObjectsWorld () {
    engineScreen->Shutdown();
}

void ScreenObjectsWorld::lifeStep() {
    using std::list;
    for ( list< AlifeScreenObject* >::iterator it = aliveObjects.begin();
            it != aliveObjects.end(); ++it )
    {
        (*it)->lifeStep();
    }
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

void ScreenObjectsWorld::addAlifeObject( AlifeScreenObject* obj ) {
    engineScreen->addEntity( obj->getModel() );
    aliveObjects.push_back(obj);
}
