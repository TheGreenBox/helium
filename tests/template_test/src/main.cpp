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

APP_MAIN_FINCTION
{
    enableDebugTools();
    std::cout << "template test";
    return 0;
}
