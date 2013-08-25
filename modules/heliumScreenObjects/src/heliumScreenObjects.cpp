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

FlatLifelessObject::FlatLifelessObject( Polycode::ScreenEntity* _model )
    :   model(_model) {}

Polycode::ScreenEntity* FlatLifelessObject::getModel() {
    return model;
}

FlatAlifeObject::FlatAlifeObject( Polycode::ScreenEntity* _model )
    :   FlatLifelessObject(_model) {}

ScreenObjects::ScreenObjects ()
    : engineScreen(new Polycode::Screen()) {
    std::cout << "engineScreen->enabled: " << engineScreen->enabled << '\n';
}

ScreenObjects::~ScreenObjects () {
    engineScreen->Shutdown();
}

void ScreenObjects::lifeStep() {
    using std::list;
    for ( list< FlatAlifeObject* >::iterator it = aliveObjects.begin();
            it != aliveObjects.end(); ++it )
    {
        (*it)->lifeStep();
    }
}

void ScreenObjects::addLifelessObject( FlatLifelessObject* obj ) {
    engineScreen->addEntity( obj->getModel() );
    lifelessObjects.push_back(obj);
}

void ScreenObjects::addAlifeObject( FlatAlifeObject* obj ) {
    engineScreen->addEntity( obj->getModel() );
    aliveObjects.push_back(obj);
}
