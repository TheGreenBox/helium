/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  mainLoop.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */


//=============================================================================
// Main app function macros

#define __WIN32_MAIN_FUNCTION                       \
    #include "windows.h"                            \
    #include "tchar.h"                              \
                                                    \
    int APIENTRY WinMain( HINSTANCE hInstance,      \
                          HINSTANCE hPrevInstance,  \
                          LPSTR lpCmdLine,          \
                          int nCmdShow )


#define __LINUX_MAIN_FUNCTION           \
    int main (int argsNum, char** argAr)


#ifdef OS_LINUX
    #define APP_MAIN_FINCTION __LINUX_MAIN_FUNCTION
#elif OS_WIN32
    #define APP_MAIN_FINCTION __WIN32_MAIN_FUNCTION
#else
    #define APP_MAIN_FINCTION 
    #warning "OS type didn't defined and main function type can not be define"
#endif


// end of main app function macros
//=============================================================================


//=============================================================================
// creating  POLYCODE VIEW obj macros

#ifdef OS_LINUX
    #define POLYCODE_VIEW_CREATOR(name_in_quotes)   \
            Polycode::PolycodeView(name_in_quotes)
    
#elif OS_WIN32
    #define POLYCODE_VIEW_CREATOR(name_in_quotes)   \
            Polycode::PolycodeView( hInstance, nCmdShow, _T(name_in_quotes) ) 

#else
    #define POLYCODE_VIEW_CREATOR 
    #warning "OS type didn't defined and mcreating  POLYCODE VIEW obj macros can not be define"
#endif

// end creating  POLYCODE VIEW obj macros
//=============================================================================
