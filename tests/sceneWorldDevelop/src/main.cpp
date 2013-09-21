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
#include <exception> 

#include <Polycode.h>
#include "PolycodeView.h"

#include "mainMacro.h"

#ifdef OS_WIN32
   #include "windows.h"
   #include "tchar.h"
#endif

#include "proGameObject.h"

APP_MAIN_FINCTION
{
    enableDebugTools();
    using namespace Polycode;
	PolycodeView*  view = new POLYCODE_VIEW_CREATOR("key test");
    Core* core = new POLYCODE_CORE(view, 640, 480, false, false, 0, 0, 90);
    
    ProGameObject* game = new ProGameObject( core );
    
    std::cout << "Keys test start...\n"; 
    
    try { 
    game->game();  
    }
    catch (std::exception e) {
        std::cout << "Exception: " << e.what() << '\n';
    }
    catch (...) {
        std::cout << "Unknoun exception\n";
    }
    std::cout << "Keys test finished!\n"; 
    return 0;
}

