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
#include <string>

#include <Polycode.h>
#include "PolycodeView.h"

#include "mainMacro.h"

#ifdef OS_WIN32
   #include "windows.h"
   #include "tchar.h"
#endif

#define HELIUM_RESOURCE_PATH_FROM_TEST "../helium_resource"

APP_MAIN_FINCTION
{
    std::string path(HELIUM_RESOURCE_PATH_FROM_TEST);
    path += "/test.blend";
//	Polycode::Mesh(path);
    std::cout << "Hello! 3D Model learning test.\n";
    std::cout << path << '\n';
    return 0;
}
