/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  ../include/heliumGameCore.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef _HELIUM_GAME_CORE_INCLUDED_
#define _HELIUM_GAME_CORE_INCLUDED_

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
//    void renderPause(bool);
    Polycode::Core*         engineCore;
    CommonWorldObjects      objectWorld;
};

#endif // _HELIUM_GAME_CORE_INCLUDED_

