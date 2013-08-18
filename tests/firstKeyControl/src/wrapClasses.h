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

class ConsoleLine {
public:
    ConsoleLine() {};
    virtual ~ConsoleLine() {};
    
private:
    Polycode::ScreenLabel* line;
};

class Console {
public:
    Console();
    virtual ~Console();

    void add(const std::string&);    
    void add(const char*);    
    void add(const Polycode::String&);    
    void clean();    
    void newLine();    
    void scroll(int);    
    
private:
    // Polycode::ScreenLabel label;
    std::list< Polycode::ScreenLabel* > lines;
    int lines_count;
    int visible_lines;
    Polycode::Screen* screen;
    
    double lineSpacing;
    int    textSize;
    int    allLines;
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
//	Polycode::PhysicsScene *scene;
//	Polycode::Screen *screen;

    Console* console;
    KeyboardUserInput* keysHandler;
};

