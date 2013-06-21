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

class HeliumGameCore
{
public:    
    HeliumGameCore(Polycode::Core* );
    virtual ~HeliumGameCore();
    void game();
    
private:
    
	Polycode::Core*     engineCore;
    
//	IPhysicsHandler*      physics;
//  ICollisionsDetector*  collisions;
    IWorldObjects*        physObjects;
};

// physicsUpdate();
// stuckDetector();
// gameObjectsBehavior();
// 
#endif // _HELIUM_GAME_CORE_INCLUDED_
