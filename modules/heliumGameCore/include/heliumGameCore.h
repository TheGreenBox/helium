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

#include "heliumSceneObjects.h"

class HeliumGameCore {
public:    
    HeliumGameCore(Polycode::Core* );
    virtual ~HeliumGameCore();
    void game();
    
    CommonWorldObjects* getObjectWorldPt() { 
        return &objectWorld; 
    };
    
    Polycode::Core* getEngineCorePt() { 
        return engineCore; 
    };
    
protected:
    Polycode::Core*         engineCore;
    CommonWorldObjects      objectWorld;
};

#endif // HELIUM_GAME_CORE_INCLUDED

