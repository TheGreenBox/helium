/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  ../include/heliumGameCore.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_GAME_CORE_INCLUDED
#define HELIUM_GAME_CORE_INCLUDED

#include <Polycode.h>
#include "PolycodeView.h"

#include "heliumGameCoreObjects.h"
#include "heliumUserInput.h"

class HeliumGameCore : public HeliumGameCoreObjects {
public:    
    HeliumGameCore(Polycode::Core* );
    virtual ~HeliumGameCore();
    void game();

protected:
    KeyboardUserInput*  keyboardInput;
//    MouseUserInput*     mouseInput;
};

#endif // HELIUM_GAME_CORE_INCLUDED

