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
    
    handlers[P::KEY_ESCAPE] = new EscapeGame();
    handlers[P::KEY_PAUSE] = new PauseGame();
}

void KeyboardUserInput::setEnable(bool set) {
    Polycode::CoreInput* input = gamePt->getEngineCorePt()->getInput();
    if (set) {
        input->addEventListener( this, P::InputEvent::EVENT_KEYDOWN);
        input->addEventListener( this, P::InputEvent::EVENT_KEYUP);
    }
    else {
        input->removeEventListener( this, P::InputEvent::EVENT_KEYDOWN);
        input->removeEventListener( this, P::InputEvent::EVENT_KEYUP);
    }
}

KeyboardUserInput::~KeyboardUserInput() {
    this->setEnable(false);
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
        prc->second->process();
    }
}

MouseUserInput::MouseUserInput(HeliumGameCoreObjects*) {
}

MouseUserInput::~MouseUserInput() {
}
     
void MouseUserInput::handleEvent(Polycode::Event*) {
}

void MouseUserInput::addEventHandler(Polycode::PolyKEY, KeyHandler*) {
    //handlers[key] = pHandler
}

void MouseUserInput::setEnable(bool set) {
    // TODO : add different class for different mouse event!!!
    Polycode::CoreInput* input = gamePt->getEngineCorePt()->getInput();
    if (set) {
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEDOWN       );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEUP         );
        input->addEventListener( this, P::InputEvent::EVENT_DOUBLECLICK     );
        
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEMOVE       );
        
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEOVER       );
        
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEOUT        );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEUP_OUTSIDE );
        
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_UP   );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_DOWN );
    }
    else {
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEDOWN       );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEUP         );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEMOVE       );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEOVER       );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEOUT        );
        input->removeEventListener( this, P::InputEvent::EVENT_DOUBLECLICK     );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEUP_OUTSIDE );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_UP   );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_DOWN );
    }
}

void keyUP (Polycode::InputEvent*) {
}

void keyDOWN (Polycode::InputEvent*) {
    // Polycode::Rectangle    selectionArea;
}

void mouseMove(Polycode::InputEvent*) {

}    
