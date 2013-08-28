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
    KeyboardUserInput(HeliumGameCoreObjects*);
    virtual ~KeyboardUserInput();
     
    void handleEvent(Polycode::Event*);
    void addEventHandler(Polycode::PolyKEY, KeyHandler*);
    void setEnable(bool);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    std::map< Polycode::PolyKEY, KeyHandler* > handlers;
    HeliumGameCoreObjects* gamePt;
};

class MouseUserInput : public Polycode::EventHandler {
public:
    MouseUserInput(HeliumGameCoreObjects*);
    virtual ~MouseUserInput();
     
    void handleEvent(Polycode::Event*);
    void addEventHandler(Polycode::PolyKEY, KeyHandler*);
    void setEnable(bool);
    
private:
    void keyUP    (Polycode::InputEvent*);
    void keyDOWN  (Polycode::InputEvent*);
    void mouseMove(Polycode::InputEvent*);
    
    Polycode::Rectangle    selectionArea;
    HeliumGameCoreObjects* gamePt;
};

class MouseButtonUserInput : public Polycode::EventHandler {

    MouseButtonUserInput();
    virtual ~MouseButtonUserInput();
    
    void handleEvent(Polycode::Event*);
    
    void addRightEventHandler(KeyHandler*);
    void addLeftEventHandler(KeyHandler*);
    void setEnable(bool);
};

class MouseMoveUserInput : public Polycode::EventHandler {
    MouseMoveUserInput();
    virtual ~MouseMoveUserInput();
    
    void handleEvent(Polycode::Event*);
    // not KeyHandler
    void addEventHandler();
    void setEnable(bool);
};

class MouseOtherUserInput : public Polycode::EventHandler {
    MouseOtherUserInput();
    virtual ~MouseOtherUserInput();
    
    void handleEvent(Polycode::Event*);
    // not KeyHandler
    void addEventHandler();
    void setEnable(bool);
};

class MouseWheelUserInput : public Polycode::EventHandler {
public:
    MouseWheelUserInput();
    ~MouseWheelUserInput();

    void handleEvent(Polycode::Event*);
    void addUpEventHandler();
    void addDownEventHandler();
    void setEnable(bool);

private:
    KeyHandler* wheelUp;
    KeyHandler* wheelDown;
};
        
class JoystickUserInput : public Polycode::EventHandler {
public:
    JoystickUserInput(HeliumGameCoreObjects*){};
    virtual ~JoystickUserInput(){};
     
private:
    HeliumGameCoreObjects* gamePt;
};

#endif // HELIUM_INPUT_DIPATHER_INCLUDED

