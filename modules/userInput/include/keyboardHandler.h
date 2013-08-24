/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  include/keyboardHandler.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include "heliumGameCore.h"

class KeyHandler {
public:
    KeyHandler(){};
    virtual ~KeyHandler(){};
    virtual void process(HeliumGameCore*)=0;
};

struct EscapeGame : public KeyHandler {
    void process(HeliumGameCore*);
};

struct PauseGame : public KeyHandler {
    void process(HeliumGameCore* gm);
};

struct SetVirtualGame : public KeyHandler {
    void process(HeliumGameCore* gm);
};

