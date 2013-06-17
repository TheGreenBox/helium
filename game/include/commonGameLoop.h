/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  commonGameLoop.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef _HELIUM_COMMON_GAME_LOOP_
#define _HELIUM_COMMON_GAME_LOOP_

#include <Polycode.h>
#include "PolycodeView.h"

#include "heliumGameCore.h"
#include "heliumMainMenu.h"

class HeliumCore
{
public:
    
    /**
    * Constructor
    * @param nil
    */
    HeliumCore( Polycode::PolycodeView* view );
    
    /**
    * Destructor
    * @param nil
    */
    virtual ~HeliumCore();
    
    void loop();
    
private:
	Polycode::Core* engineCore;
    
    I_HeliumMainMenu* menu;    
    HeliumGameCore* gameCore;
};

#endif // _HELIUM_COMMON_GAME_LOOP_

