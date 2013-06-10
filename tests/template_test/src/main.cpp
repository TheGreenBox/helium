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

#ifdef OS_WIN32
    #include "windows.h"
    #include "tchar.h"
#endif

#ifdef OS_LINUX
int main (int argsNum, char** argAr)
#elif OS_WIN32
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif

{
#ifdef OS_LINUX
    Polycode::PolycodeView *view = new Polycode::PolycodeView("first test");
#elif OS_WIN32
    Polycode::PolycodeView *view = new Polycode::PolycodeView(hInstance, nCmdShow, _T("Polycode Example"));
#endif

    std::cout << "template test"; 
    return 0;
}
