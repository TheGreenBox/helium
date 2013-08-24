/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  include/keyboardHandler.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_KEYBOARD_HANDLER_INCLUDED
#define HELIUM_KEYBOARD_HANDLER_INCLUDED

#include "heliumGameCoreObjects.h"

class KeyHandler {
public:
    KeyHandler(){};
    virtual ~KeyHandler(){};
    virtual void process(HeliumGameCoreObjects*)=0;
};

struct EscapeGame : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct PauseGame : public KeyHandler {
    void process(HeliumGameCoreObjects* gm);
};

struct SetVirtualGame : public KeyHandler {
    void process(HeliumGameCoreObjects* gm);
};

#endif // HELIUM_KEYBOARD_HANDLER_INCLUDED

