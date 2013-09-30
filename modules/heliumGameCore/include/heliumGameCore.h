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

#include "heliumUserInput.h"
#include "helium_3D.h"
#include "helium_2D.h"

class HeliumGameCore {
public:    
    HeliumGameCore(Polycode::Core* );
    virtual ~HeliumGameCore();
    void game();
    void makeSelfMainChief();

    Helium_3D_World* getSceneWorldPt() { 
        return &solidWorld; 
    }
    
    Helium_2D_World* getScreenWorldPt() { 
        return &flatWorld; 
    }
    
    Polycode::Core* getEngineCorePt() { 
        return engineCore; 
    }
    
protected:
    Polycode::Core*  engineCore;
    
    Helium_3D_World  solidWorld;
    Helium_2D_World  flatWorld; 
    
    KeyboardUserInput*  keyboardInput;
    MouseUserInput*     mouseInput;

private:
    void mainLoop();
};

#endif // HELIUM_GAME_CORE_INCLUDED

