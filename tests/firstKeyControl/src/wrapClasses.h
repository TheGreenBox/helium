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

#include "heliumSceneObjects.h"
#include "heliumScreenConsole.h"

class ProGameObject;

class KeyHandler {
public:
    KeyHandler(){};
    virtual ~KeyHandler(){};
    virtual void process(ProGameObject*)=0;
};

class AddDice : public KeyHandler {
public:
    AddDice(){};
    virtual ~AddDice(){};
    void process(ProGameObject*);
    static int status;
};

class EscapeGame : public KeyHandler {
public:
    EscapeGame(){};
    virtual ~EscapeGame(){};
    void process(ProGameObject*);
};

class KeyboardUserInput : public Polycode::EventHandler {
public:
    KeyboardUserInput(ProGameObject*);
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event*);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    std::map< int, KeyHandler* > handlers;
    
    ScreenConsole* console;
    ProGameObject* gamePt;
};

class ProGameObject {
public:
    ProGameObject( Polycode::PolycodeView* );
    virtual ~ProGameObject();
    
    CommonWorldObjects*     getWorldPt() { return &world; };
    Polycode::PhysicsScene* getScenePt() { return scene; };
    Polycode::Core* getCorePt() { return core; };
    
    int update();
    
private:
    Polycode::Core*         core;
    Polycode::PhysicsScene* scene;
    
    KeyboardUserInput* keysHandler;
    CommonWorldObjects world;
};

