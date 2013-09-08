/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name: debugTools.cpp
 * Description:
 * Author:
 * ========================================================
 */

#ifdef OS_WIN32
#include <windows.h>
#include <stdio.h>
#endif

#include "debugTools.h"

int setDebugConsoleForWin32() {
    #ifdef OS_WIN32
        if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
            AllocConsole();
        }
        // SetConsoleTitle("Helium debug console");
        freopen("CONOUT$", "w", stdout);
        return 0;
    #endif
    return 1;
}

void enableDebugTools() {
    setDebugConsoleForWin32();
}
