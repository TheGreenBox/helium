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

#include "mainLoop.h"

APP_MAIN_FINCTION
{
	PolycodeView *view = new POLYCODE_VIEW_CREATOR("first step test");
    
    FirstStepTest* test = new FirstStepTest(view);
   
	while(test->Update()) 
    {}
    return 0;
}
