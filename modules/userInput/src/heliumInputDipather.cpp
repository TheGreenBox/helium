/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  modules/userInput/src/heliumInputDipather.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <iostream>
#include <Polycode.h>

#include "heliumInputDipather.h"
#include "heliumGameGlobal.h"

namespace P = Polycode;

KeyboardUserInput::KeyboardUserInput() {
    handlers[P::KEY_ESCAPE] = new EscapeGame();
    handlers[P::KEY_PAUSE] = new PauseGame();
}

void KeyboardUserInput::setEnable(bool set) {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::CoreInput* input = gm->getEngineCorePt()->getInput();
    if (set) {
       // input->addEventListener( this, P::InputEvent::EVENT_KEYDOWN);  -- Do you realy need it ?!
        input->addEventListener( this, P::InputEvent::EVENT_KEYUP);
    }
    else {
      //  input->removeEventListener( this, P::InputEvent::EVENT_KEYDOWN);
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
    // FIXME!!! keyCode must return PolyKEY type !!!
    P::PolyKEY code = static_cast<P::PolyKEY>(inputEvent->keyCode());
    std::map<P::PolyKEY, KeyHandler*>::iterator prc = handlers.find(code);
    if ( prc != handlers.end() ) {
        prc->second->process();
    }
}

void KeyboardUserInput::keyDOWN(P::InputEvent* inputEvent){
}

MouseUserInput::MouseUserInput() 
    :   buttoninput(new MouseButtonUserInput),
        moveInput  (new MouseMoveUserInput  ),
        otherInput (new MouseOtherUserInput),
        wheelInput (new MouseWheelUserInput)
{}

MouseUserInput::~MouseUserInput() {
}
     
void MouseUserInput::setEnable(bool set) {
    buttoninput->setEnable(set);
    moveInput->setEnable(set); 
    otherInput->setEnable(set);
    wheelInput->setEnable(set);
}

MouseButtonUserInput::MouseButtonUserInput () {
}

void MouseButtonUserInput::setEnable(bool set) {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::CoreInput* input = gm->getEngineCorePt()->getInput();
    if (set) {
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEDOWN       );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEUP         );
        input->addEventListener( this, P::InputEvent::EVENT_DOUBLECLICK     );
    }
    else {
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEDOWN       );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEUP         );
        input->removeEventListener( this, P::InputEvent::EVENT_DOUBLECLICK     );
    }
}

void MouseButtonUserInput::handleEvent(Polycode::Event* e) {
    P::InputEvent* ie = dynamic_cast<P::InputEvent*>(e);
    int code = ie->mouseButton;
    std::cout << "Mouse button: " << code << '\n';
//    switch(e->getEventCode()) {
//        case P::InputEvent::EVENT_MOUSEDOWN:
//        {
//            std::map<int, MouseKeyHandler*>::iterator prc = downHandlers.find(code);
//            if ( prc != downHandlers.end() ) {
//                prc->second->process(ie->getMousePosition());
//            }
//        }
//        break;
//        case P::InputEvent::EVENT_MOUSEUP:
//        {
//            std::map<int, MouseKeyHandler*>::iterator prc = upHandlers.find(code);
//            if ( prc != upHandlers.end() ) {
//                prc->second->process(ie->getMousePosition());
//            }
//            HeliumGlobal::GetCurrentGame()->getSceneWorldPt():E
//        }
//        break;
//        case P::InputEvent::EVENT_DOUBLECLICK:
//        {
//            std::map<int, MouseKeyHandler*>::iterator prc = doubleClickHandlers.find(code);
//            if ( prc != doubleClickHandlers.end() ) {
//                prc->second->process(ie->getMousePosition());
//            }
//        }
//        break;
//    }
}

void MouseButtonUserInput::addRightEventHandler(MouseKeyHandler*) {
}

void MouseButtonUserInput::addLeftEventHandler(MouseKeyHandler*) {
}

void MouseButtonUserInput::addButtonEventHandler(int, MouseKeyHandler*) {
}

MouseMoveUserInput::MouseMoveUserInput() {
}

void MouseMoveUserInput::setEnable(bool set) {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::CoreInput* input = gm->getEngineCorePt()->getInput();
    if (set) {
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEMOVE       );
    }
    else {
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEMOVE       );
    }
}

void MouseMoveUserInput::handleEvent(Polycode::Event* e) {
    //std::cout << "Mouse move\n";
}

MouseOtherUserInput::MouseOtherUserInput() {
}

void MouseOtherUserInput::setEnable(bool set) {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::CoreInput* input = gm->getEngineCorePt()->getInput();
    if (set) {
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEOVER       );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEOUT        );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEUP_OUTSIDE );
    }
    else {
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEOVER       );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEOUT        );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEUP_OUTSIDE );
    }
}

void MouseOtherUserInput::handleEvent(Polycode::Event* e) {
    std::cout << "Mouse other\n";
}

MouseWheelUserInput::MouseWheelUserInput () {
}

void MouseWheelUserInput::setEnable(bool set) {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::CoreInput* input = gm->getEngineCorePt()->getInput();
    if (set) {
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_UP   );
        input->addEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_DOWN );
    }
    else {
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_UP   );
        input->removeEventListener( this, P::InputEvent::EVENT_MOUSEWHEEL_DOWN );
    }
}

void MouseWheelUserInput::handleEvent(Polycode::Event* e) {
    switch(e->getEventCode()) {
        case P::InputEvent::EVENT_MOUSEWHEEL_UP:
            std::cout << "Mouse wheel up\n";
            if ( wheelUp != NULL ) {
                wheelUp->process();
            }
        break;
        case P::InputEvent::EVENT_MOUSEWHEEL_DOWN:
            std::cout << "Mouse wheel down\n";
            if ( wheelDown != NULL ) {
                wheelDown->process();
            }
        break;
    }
}

void MouseWheelUserInput::addUpEventHandler(KeyHandler* handler) {
    KeyHandler* wheelUp;
}

void MouseWheelUserInput::addDownEventHandler(KeyHandler* handler) {
    wheelDown = handler;
}

