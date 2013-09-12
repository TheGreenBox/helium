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
#include "heliumScreenObjects.h"
#include "heliumSceneObjects.h"

class HeliumGameCore {
public:    
    HeliumGameCore(Polycode::Core* );
    virtual ~HeliumGameCore();
    void game();
    void makeSelfMainChief();

    SceneObjectsWorld* getSceneWorldPt() { 
        return &solidWorld; 
    }
    
    ScreenObjectsWorld* getScreenWorldPt() { 
        return &flatWorld; 
    }
    
    Polycode::Core* getEngineCorePt() { 
        return engineCore; 
    }
    
protected:
    Polycode::Core*     engineCore;
    SceneObjectsWorld   solidWorld;
    ScreenObjectsWorld  flatWorld; 
    
    KeyboardUserInput*  keyboardInput;
    MouseUserInput*     mouseInput;

private:
    void mainLoop();
};

#endif // HELIUM_GAME_CORE_INCLUDED

