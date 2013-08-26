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
#include "heliumUserInputHandler.h"
#include "heliumScreenButton.h"

struct EscapeGame : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct PauseGame : public KeyHandler {
    PauseGame();
    virtual ~PauseGame();
    void process(HeliumGameCoreObjects* gm);
    static ScreenButton* pauseButton;
};

struct SetVirtualGame : public KeyHandler {
    void process(HeliumGameCoreObjects* gm);
};

#endif // HELIUM_KEYBOARD_HANDLER_INCLUDED

