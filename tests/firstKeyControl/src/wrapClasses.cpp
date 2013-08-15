/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  wrapClasses.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <iostream>
#include "wrapClasses.h"

namespace P = Polycode;

Console::Console(P::Screen* consScreen) 
    : screen(consScreen),
        label("Hello!\n", 12) {
    screen->addChild(&label);
}

Console::~Console() {
    screen->removeChild(&label);
}

void Console::add(const std::string&) {}
void Console::add(const char* str) {
    label.setText(label.getText() + str);
}

void Console::add(const Polycode::String& str) {
    label.setText(label.getText() + str);
}

void Console::clean() {
    label.setText("");
}

KeyboardUserInput::KeyboardUserInput( Console* cons )
        : console(cons)
{}
 
void KeyboardUserInput::handleEvent(Polycode::Event *e) {
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

void KeyboardUserInput::keyUP(P::InputEvent* inputEvent){
    std::cout << "Key Up: " << inputEvent->keyCode() << '\n';
    console->add("up\n");
}

void KeyboardUserInput::keyDOWN(P::InputEvent* inputEvent){
    std::cout << "Key Down: " << inputEvent->keyCode() << '\n';
    console->add("down\n");
}

using namespace P; // fucking macros !
ProGameobject::ProGameobject( PolycodeView* view )
        : core(new POLYCODE_CORE(view, 640,480,false,false,0,0,90)),
          screen(new Screen()),
          console(screen),
          keysHandler(&console) {
    //core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);
	Screen *screen = new Screen();
	ScreenLabel *label = new ScreenLabel("Hello, Polycode!", 32);
	screen->addChild(label);
	core->getInput()->addEventListener( &keysHandler, 
                                P::InputEvent::EVENT_KEYDOWN);
    
	core->getInput()->addEventListener( &keysHandler,
                                P::InputEvent::EVENT_KEYUP);
}

ProGameobject::~ProGameobject(){
}

int ProGameobject::update() {
    return core->updateAndRender();
}

