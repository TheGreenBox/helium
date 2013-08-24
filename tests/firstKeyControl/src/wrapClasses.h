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

#include "heliumGameCore.h"
#include "heliumSceneObjects.h"
#include "heliumScreenConsole.h"
#include "keyboardHandler.h"

class ProGameObject;

struct AddDice : public KeyHandler {
    void process(HeliumGameCore*);
};

struct AddBarrel : public KeyHandler {
    void process(HeliumGameCore*);
};

struct AddBoll : public KeyHandler {
    void process(HeliumGameCore*);
};

struct XCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

struct XNegativeCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

struct YCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

struct YNegativeCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

class KeyboardUserInput : public Polycode::EventHandler {
public:
    KeyboardUserInput(HeliumGameCore*);
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event*);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    std::map< int, KeyHandler* > handlers;
    
    ScreenConsole* console;
    HeliumGameCore* gamePt;
};

class ProGameObject : public HeliumGameCore {
public:
    ProGameObject( Polycode::Core* );
    virtual ~ProGameObject();
    
private:
    KeyboardUserInput* keysHandler;
};

