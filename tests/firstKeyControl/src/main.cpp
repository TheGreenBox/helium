/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  first_step_main.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <iostream> 

#include <Polycode.h>
#include "PolycodeView.h"

#include "mainMacro.h"

#ifdef OS_WIN32
   #include "windows.h"
   #include "tchar.h"
#endif

#include "wrapClasses.h"

APP_MAIN_FINCTION
{
    using namespace Polycode;
	PolycodeView*  view = new POLYCODE_VIEW_CREATOR("key test");
    
    ProGameObject* game = new ProGameObject( view );
    
    std::cout << "Keys test start...\n"; 
    
    while (game->update()) { }
    
    std::cout << "Keys test finished!\n"; 
    return 0;
}

