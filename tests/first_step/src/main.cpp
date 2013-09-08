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
#include "firstTestClass.h"

#include "mainMacro.h"

#ifdef OS_WIN32
   #include "windows.h"
   #include "tchar.h"
#endif

APP_MAIN_FINCTION
{
    setDebugConsoleForWin32();

	PolycodeView *view = new POLYCODE_VIEW_CREATOR("first step test");

    FirstStepTest* test = new FirstStepTest(view);

	while(test->Update())
    {}
    return 0;
}
