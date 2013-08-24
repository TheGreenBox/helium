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
#include "heliumScreenObjects.h"
#include "heliumGameCoreObjects.h"

class KeyboardUserInput : public Polycode::EventHandler {
public:
    KeyboardUserInput(HeliumGameCoreObjects*);
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event*);
    void addEventHandler(Polycode::PolyKEY, KeyHandler*);
    
private:
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
    std::map< Polycode::PolyKEY, KeyHandler* > handlers;
    
    ScreenConsole* console;
    HeliumGameCoreObjects* gamePt;
};

class MouseUserInput : public Polycode::EventHandler {
public:
    MouseUserInput(HeliumGameCoreObjects*){};
    virtual ~MouseUserInput(){};
     
private:
    HeliumGameCoreObjects* gamePt;
};

#endif // HELIUM_INPUT_DIPATHER_INCLUDED

