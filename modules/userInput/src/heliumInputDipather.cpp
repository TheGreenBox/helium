/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  modules/userInput/src/heliumInputDipather.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <Polycode.h>

#include "heliumInputDipather.h"

namespace P = Polycode;

KeyboardUserInput::KeyboardUserInput(HeliumGameCoreObjects* gm)
        : gamePt(gm) {
    gamePt->getEngineCorePt()->getInput()->addEventListener( this, 
                                                    P::InputEvent::EVENT_KEYDOWN);
  
    gamePt->getEngineCorePt()->getInput()->addEventListener( this,
                                                    P::InputEvent::EVENT_KEYUP);
    
    handlers[P::KEY_ESCAPE] = new EscapeGame();
    handlers[P::KEY_PAUSE] = new PauseGame();
}
 
void KeyboardUserInput::handleEvent(P::Event *e) {
    // if(e->getDispatcher() == core->getInput()) {
    switch(e->getEventCode()) {
        case P::InputEvent::EVENT_KEYDOWN:
            this->keyDOWN( (P::InputEvent*)e );
        break;
        
        case P::InputEvent::EVENT_KEYUP:
            this->keyUP( (P::InputEvent*)e );
        break;
    }
}
void KeyboardUserInput::addEventHandler(Polycode::PolyKEY key, KeyHandler* pHandler) {
    handlers[key] = pHandler;
}

void KeyboardUserInput::keyUP(P::InputEvent* inputEvent){
}

void KeyboardUserInput::keyDOWN(P::InputEvent* inputEvent){
    // FIXME!!! keyCode must return PolyKEY type !!!
    P::PolyKEY code = static_cast<P::PolyKEY>(inputEvent->keyCode());
    std::map<P::PolyKEY, KeyHandler*>::iterator prc = handlers.find(code);
    if ( prc != handlers.end() ) {
        prc->second->process(gamePt);
    }
}
