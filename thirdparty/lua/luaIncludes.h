/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  luaIncludes.h
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#ifndef _LUA_COMMON_INCLUDED
#define _LUA_COMMON_INCLUDED

namespace Lua {
    extern "C" {
        #include "lua.h"
        #include "lauxlib.h"
        #include "lualib.h"
    }
}

#endif // _LUA_COMMON_INCLUDED

