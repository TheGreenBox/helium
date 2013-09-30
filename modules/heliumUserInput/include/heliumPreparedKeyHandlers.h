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

#include "Polycode.h"

#include "helium_2D_World.h"
#include "heliumUserInputHandler.h"
#include "helium_2D_Button.h"

struct EscapeGame : public KeyHandler {
    void process();
};

class PauseGame : public KeyHandler {
public:
    PauseGame();
    virtual ~PauseGame();
    void process();

private:
    static Helium_2D_World::ObjectId button;
};

struct SetVirtualGame : public KeyHandler {
    void process();
};

#endif // HELIUM_KEYBOARD_HANDLER_INCLUDED

