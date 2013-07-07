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

#include "first3dTest.h"
#include "mainMacro.h"

#ifdef OS_WIN32
   #include "windows.h"
   #include "tchar.h"
#endif

APP_MAIN_FINCTION
{
	PolycodeView *view = new POLYCODE_VIEW_CREATOR("first 3D test");
    
    First3DTest* test = new First3DTest(view);

	while( test->Update() ) {}
    
    return 0;
}
