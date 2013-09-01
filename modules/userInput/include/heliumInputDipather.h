/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    userInput/include/heliumInputDipather.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_INPUT_DIPATHER_INCLUDED
#define HELIUM_INPUT_DIPATHER_INCLUDED

#include <Polycode.h>
#include <map>

#include "keyboardHandler.h"
#include "heliumGameCoreObjects.h"

class KeyboardUserInput : public Polycode::EventHandler {
public:
    KeyboardUserInput();
    virtual ~KeyboardUserInput();
     
    void handleEvent(Polycode::Event*);
    void addEventHandler(Polycode::PolyKEY, KeyHandler*);
    void setEnable(bool);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    std::map< Polycode::PolyKEY, KeyHandler* > handlers;
};

class MouseButtonUserInput : public Polycode::EventHandler {
public:
    MouseButtonUserInput();
    virtual ~MouseButtonUserInput() {}
    
    void handleEvent(Polycode::Event*);
    
    void addRightEventHandler(MouseKeyHandler*);
    void addLeftEventHandler(MouseKeyHandler*);
    
    void addButtonEventHandler(int, MouseKeyHandler*);
    void setEnable(bool);

private:
    Polycode::Rectangle    selectionArea;
    
    std::map< int, MouseKeyHandler* > upHandlers;
    std::map< int, MouseKeyHandler* > downHandlers;
    std::map< int, MouseKeyHandler* > doubleClickHandlers;
};

class MouseMoveUserInput : public Polycode::EventHandler {
public:
    MouseMoveUserInput();
    virtual ~MouseMoveUserInput() {}
    
    void handleEvent(Polycode::Event*){};
    // not KeyHandler
    void addEventHandler(){};
    void setEnable(bool);
private:
    MouseKeyHandler* handler;
    
};

class MouseOtherUserInput : public Polycode::EventHandler {
public:
    MouseOtherUserInput();
    virtual ~MouseOtherUserInput(){}
    
    void handleEvent(Polycode::Event*){}
    // not KeyHandler
    void addEventHandler(){}
    void setEnable(bool);
};

class MouseWheelUserInput : public Polycode::EventHandler {
public:
    MouseWheelUserInput();
    ~MouseWheelUserInput(){}

    void handleEvent(Polycode::Event*);
    void addUpEventHandler(KeyHandler*);
    void addDownEventHandler(KeyHandler*);
    void setEnable(bool);

private:
    KeyHandler* wheelUp;
    KeyHandler* wheelDown;
};
        
class MouseUserInput : public Polycode::EventHandler {
public:
    MouseUserInput();
    virtual ~MouseUserInput();
     
    void addEventHandler(Polycode::PolyKEY, KeyHandler*);
    void setEnable(bool);
    
private:
    void handleEvent(Polycode::Event*) {}
    
    MouseButtonUserInput*  buttoninput;
    MouseMoveUserInput*    moveInput; 
    MouseOtherUserInput*   otherInput;
    MouseWheelUserInput*   wheelInput;
};

class JoystickUserInput : public Polycode::EventHandler {
public:
    JoystickUserInput(HeliumGameCoreObjects*){};
    virtual ~JoystickUserInput(){};
     
private:
    HeliumGameCoreObjects* gamePt;
};

#endif // HELIUM_INPUT_DIPATHER_INCLUDED

