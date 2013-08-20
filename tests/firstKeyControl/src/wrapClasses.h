/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
  File name:  wrapClasses.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <list>
#include <map>

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"

#include "heliumScreenConsole.h"

class KeyHandler {
public:
    KeyHandler(){};
    virtual ~KeyHandler(){};
    virtual void process(Polycode::PhysicsScene*)=0;
};

class AddDice : public KeyHandler {
public:
    AddDice(){};
    virtual ~AddDice(){};
    void process(Polycode::PhysicsScene*);
    static int status;
};

class KeyboardUserInput : public Polycode::EventHandler {
public:
    KeyboardUserInput(Polycode::PhysicsScene*);
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event*);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    std::map<int, KeyHandler*> handlers;
    ScreenConsole* console;
    Polycode::PhysicsScene* scene;
};

class ProGameobject {
public:
    ProGameobject( Polycode::PolycodeView* );
    virtual ~ProGameobject();
    int update();
    
private:
    Polycode::Core* core;
    Polycode::PhysicsScene* scene;
    
    KeyboardUserInput* keysHandler;
};

