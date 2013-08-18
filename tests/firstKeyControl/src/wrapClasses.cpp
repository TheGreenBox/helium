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

#include "pathGlobal.h"

namespace P = Polycode;

Console::Console() 
    : screen(new P::Screen()),
        lines_count(0),
        visible_lines(0),
        lineSpacing(0.2),
        textSize(12),
        allLines(15) {
    
    this->newLine();
    this->add("Helium Console v_0.0.0.1:");
    this->newLine();
}

Console::~Console() {
    lines.back()->setText(lines.back()->getText() + str);
}

void Console::add(const std::string&) {}
void Console::add(const char* str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void Console::add(const Polycode::String& str) {
    lines.back()->setText(lines.back()->getText() + str);
}

void Console::clean() {
    lines.back()->setText("");
}

void Console::newLine() {
    P::String lineBegin = P::String::IntToString(lines_count);
    lineBegin += " : ";
    
    P::ScreenLabel* label = new P::ScreenLabel(lineBegin, textSize, "mono");
    label->setColor(0,1,0,1);
    label->setPosition(4, static_cast<double>(lines_count*textSize)*(lineSpacing+1) );
    screen->addChild(label);
    
    lines.push_back(label);
    ++lines_count;
    ++visible_lines;
    if ( visible_lines > allLines ) {
        scroll(-1);        
        --visible_lines;
    }
}

void Console::scroll(int n) {
    double offset = static_cast<double>((lines_count-visible_lines+n)*textSize) * (lineSpacing+1);
    screen->setScreenOffset(0, -offset);
    visible_lines += n;
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
    //std::cout << "Key Up: " << inputEvent->keyCode() << '\n';
    console->add("up: ");
    console->add(P::String::IntToString(inputEvent->keyCode()));
    console->add(" : ");
    console->add(inputEvent->charCode);
    console->newLine();
}

void KeyboardUserInput::keyDOWN(P::InputEvent* inputEvent){
    //std::cout << "Key Down: " << inputEvent->keyCode() << '\n';
    console->add("down: ");
    console->add(P::String::IntToString(inputEvent->keyCode()));
    console->add(" : ");
    console->add(inputEvent->charCode);
    console->newLine();
}

ProGameobject::ProGameobject( P::PolycodeView* view )
//        : core(new POLYCODE_CORE(view, 640,480,false,false,0,0,90)),
//          screen(new Screen()),
//          console(screen),
//          keysHandler(&console) {
{
    using namespace P; // fucking macros !
    core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);

    P::String res_path(HELIUM_RESOURCE_PATH);
    CoreServices::getInstance()->getResourceManager()->addArchive(res_path+"/default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
	
//    Screen *screen = new Screen();
	
    console = new Console();
    keysHandler = new KeyboardUserInput(console);
    core->getInput()->addEventListener( keysHandler, 
                                P::InputEvent::EVENT_KEYDOWN);
  
    core->getInput()->addEventListener( keysHandler,
                                P::InputEvent::EVENT_KEYUP);
}

ProGameobject::~ProGameobject(){
}

int ProGameobject::update() {
    return core->updateAndRender();
}

