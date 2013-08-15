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
class Console {
public:
    Console(Polycode::Screen*);
    virtual ~Console();

    void add(const std::string&);    
    void add(const char*);    
    void add(const Polycode::String&);    
    void clean();    
    
private:
    Polycode::ScreenLabel label;
    Polycode::Screen* screen;
};

class KeyboardUserInput : public Polycode::EventHandler
{
public:
    KeyboardUserInput( Console* );
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event *e);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    Console* console;
};

class ProGameobject
{
public:
    ProGameobject( Polycode::PolycodeView* );
    virtual ~ProGameobject();
    int update();
    
private:
	Polycode::Core *core;
	Polycode::PhysicsScene *scene;
	Polycode::Screen *screen;

    Console console;
    KeyboardUserInput keysHandler;
};

