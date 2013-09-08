/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumGameCoreObjects.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_GAME_CORE_INTERFACE_INCLUDED
#define HELIUM_GAME_CORE_INTERFACE_INCLUDED

#include <Polycode.h>
#include "PolycodeView.h"

#include "heliumSceneObjects.h"
#include "heliumScreenObjects.h"

class HeliumGameCoreObjects {
public:    
    HeliumGameCoreObjects(Polycode::Core* core) : engineCore(core) {}
    virtual ~HeliumGameCoreObjects(){}
    
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
};

#endif // HELIUM_GAME_CORE_INTEFACE_INCLUDED

