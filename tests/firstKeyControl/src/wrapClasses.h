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

class KeyboardUserInput : public Polycode::EventHandler
{
public:
    KeyboardUserInput( ScreenConsole* );
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event *e);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    ScreenConsole* console;
};

class ProGameobject
{
public:
    ProGameobject( Polycode::PolycodeView* );
    virtual ~ProGameobject();
    int update();
    
private:
    Polycode::Core *core;
    
    ScreenConsole* console;
    KeyboardUserInput* keysHandler;
};

