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
	PolycodeView *view = new POLYCODE_VIEW_CREATOR("first step test");
    ProGameobject* gm = new ProGameobject( view );
    std::cout << "template test start...\n"; 
    while (gm->update()) {
    }
    std::cout << "template test finished!\n"; 
    return 0;
}
