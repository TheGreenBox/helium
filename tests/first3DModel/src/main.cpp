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
//#include <string>

#include <Polycode.h>
#include <PolyMesh.h>

#include "PolycodeView.h"

#include "mainMacro.h"
#include "pathGlobal.h"

#ifdef OS_WIN32
   #include "windows.h"
   #include "tchar.h"
#endif

APP_MAIN_FINCTION
{
    std::cout << "Hello! 3D Model learning test.\n";
    Polycode::String mesh_path(HELIUM_RESOURCE_PATH_FROM_TEST);
    mesh_path += "/polycode_smpl.mesh";
    std::cout << "Path to 3d model: " << mesh_path.c_str() << '\n';
    
    Polycode::SceneMesh* mesh = new Polycode::SceneMesh(mesh_path);
    
    return 0;
}
