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
    
protected:
    void renderPause(bool);
	
private:
    Polycode::Core*      engineCore;
    
    Polycode::Scene*     engineScene;
    Polycode::Screen*    engineScreen; // may be it wiil be no one ?
    
    WorldObjects*        physObjects;
};

#endif // _HELIUM_GAME_CORE_INCLUDED_

