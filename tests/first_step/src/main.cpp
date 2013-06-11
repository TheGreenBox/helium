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
    std::cout << "The arguments to " << argAr[0] <<  "are:\n";
    for (int i = 1; i < argsNum; i++)
    {
        std::cout << i << " : " << argAr[i] << "\n";
    }

    PolycodeView *view = new PolycodeView("first test");
#elif OS_WIN32
	PolycodeView *view = new PolycodeView( hInstance, nCmdShow, static_cast<LPSTR>(_T("Polycode Example")) );
#endif

    FirstStepTest* test = new FirstStepTest(view);
   
	while(test->Update()) 
    {}
    return 0;
}
