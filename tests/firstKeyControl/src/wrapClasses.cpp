/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  wrapClasses.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include "wrapClasses.h"

namespace P = Polycode;

ListOfAllObjects::~ListOfAllObjects() {
    std::list< Polycode::ScenePrimitive* >::iterator 
                    grIt = graphObj.begin();;
    for (; grIt != graphObj.end(); ++grIt ) {
        delete *grIt;
    }
    
    std::list< Polycode::PhysicsSceneEntity* >::iterator 
                    phIt = phObj.begin();
    for (; phIt != phObj.end(); ++phIt ) {
        delete *phIt;
    }
}

void ListOfAllObjects::addCommon(P::PhysicsSceneEntity* physEnt) {

}

void ListOfAllObjects::addChar(P::PhysicsCharacter* physChar){

}

void ListOfAllObjects::addGraphObj(P::ScenePrimitive* primitive) {

}

KeyboardUserInput::KeyboardUserInput( Polycode::Core *engCore,
                   ListOfAllObjects*   pallObj,
                   ProHeliumGameState* pGameState )
        : core(engCore),
          worldObjects(pallObj),
          gameState(pGameState) {}
 
void KeyboardUserInput::handleEvent(Polycode::Event *e) {
    if(e->getDispatcher() == core->getInput()) {
        switch(e->getEventCode()) {
            case P::InputEvent::EVENT_MOUSEDOWN:
                this->mouseKeyDOWN( (P::InputEvent*)e );
            break;
            
            case P::InputEvent::EVENT_MOUSEUP:
                this->mouseKeyUP( (P::InputEvent*)e );
            break;
			
            case P::InputEvent::EVENT_KEYDOWN:
                this->keyDOWN( (P::InputEvent*)e );
            break;
			
            case P::InputEvent::EVENT_KEYUP:
                this->keyUP( (P::InputEvent*)e );
            break;
        }
    }
}

void KeyboardUserInput::mouseKeyUP(Polycode::InputEvent*){
}

void KeyboardUserInput::mouseKeyDOWN(Polycode::InputEvent*){
}

void KeyboardUserInput::keyUP(Polycode::InputEvent*){
}

void KeyboardUserInput::keyDOWN(Polycode::InputEvent*){
}

ProGameobject::ProGameobject( P::PolycodeView* view )
        : keysHandler(core, &worldobjects, &gameState) {
    using namespace P; // fucking macros !
	core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);
}

ProGameobject::~ProGameobject(){
}

int ProGameobject::update() {
    return 0;
}
