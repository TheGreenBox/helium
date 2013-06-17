/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  game/src/main.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include "heliumGameCore.h"

#include "commonGameLoop.h"
#include "mainMacro.h"

APP_MAIN_FINCTION
{
	Polycode::PolycodeView *view = 
              new POLYCODE_VIEW_CREATOR("The Helium game");
    return 0;
}
