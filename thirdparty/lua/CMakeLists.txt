
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(lualib C)

#IF(NOT CMAKE_BUILD_TYPE)
#    #SET(CMAKE_BUILD_TYPE "Debug")
#    SET(CMAKE_BUILD_TYPE "Release")
#    MESSAGE("No CMAKE_BUILD_TYPE specified, defaulting to ${CMAKE_BUILD_TYPE}") 
#ENDIF(NOT CMAKE_BUILD_TYPE)

# to distinguish between debug and release lib
SET(CMAKE_DEBUG_POSTFIX "_d")

SET ( LUALIB_SRC_DIR ${CMAKE_SOURCE_DIR}/lua-5.2.2/src )

SET ( lualib_HDRS
        ${LUALIB_SRC_DIR}/lmem.h
        ${LUALIB_SRC_DIR}/ltm.h
        ${LUALIB_SRC_DIR}/lfunc.h
        ${LUALIB_SRC_DIR}/lapi.h
        ${LUALIB_SRC_DIR}/lctype.h
        ${LUALIB_SRC_DIR}/lgc.h
        ${LUALIB_SRC_DIR}/lcode.h
        ${LUALIB_SRC_DIR}/ltable.h
        ${LUALIB_SRC_DIR}/ldo.h
        ${LUALIB_SRC_DIR}/luaconf.h
        ${LUALIB_SRC_DIR}/llimits.h
        ${LUALIB_SRC_DIR}/lauxlib.h
        ${LUALIB_SRC_DIR}/lundump.h
        ${LUALIB_SRC_DIR}/ldebug.h
        ${LUALIB_SRC_DIR}/lzio.h
        ${LUALIB_SRC_DIR}/lvm.h
        ${LUALIB_SRC_DIR}/lua.h
        ${LUALIB_SRC_DIR}/lopcodes.h
        ${LUALIB_SRC_DIR}/lparser.h
        ${LUALIB_SRC_DIR}/lstate.h
        ${LUALIB_SRC_DIR}/llex.h
        ${LUALIB_SRC_DIR}/lstring.h
        ${LUALIB_SRC_DIR}/lualib.h
        ${LUALIB_SRC_DIR}/lobject.h
    )

SET ( lualib_SRCS 
        ${LUALIB_SRC_DIR}/lcorolib.c
        ${LUALIB_SRC_DIR}/lctype.c
        ${LUALIB_SRC_DIR}/lobject.c
        ${LUALIB_SRC_DIR}/lopcodes.c
        ${LUALIB_SRC_DIR}/ltm.c
        ${LUALIB_SRC_DIR}/ltable.c
        ${LUALIB_SRC_DIR}/linit.c
        ${LUALIB_SRC_DIR}/lundump.c
        ${LUALIB_SRC_DIR}/loadlib.c
        ${LUALIB_SRC_DIR}/luac.c
        ${LUALIB_SRC_DIR}/lzio.c
        ${LUALIB_SRC_DIR}/lparser.c
        ${LUALIB_SRC_DIR}/lstring.c
        ${LUALIB_SRC_DIR}/lauxlib.c
        ${LUALIB_SRC_DIR}/lstate.c
        ${LUALIB_SRC_DIR}/ldo.c
        ${LUALIB_SRC_DIR}/ldblib.c
        ${LUALIB_SRC_DIR}/llex.c
        ${LUALIB_SRC_DIR}/lvm.c
        ${LUALIB_SRC_DIR}/lmathlib.c
        ${LUALIB_SRC_DIR}/lfunc.c
        ${LUALIB_SRC_DIR}/ltablib.c
        ${LUALIB_SRC_DIR}/lstrlib.c
        ${LUALIB_SRC_DIR}/lbaselib.c
        ${LUALIB_SRC_DIR}/lgc.c
        ${LUALIB_SRC_DIR}/lbitlib.c
        ${LUALIB_SRC_DIR}/lapi.c
        ${LUALIB_SRC_DIR}/lcode.c
        ${LUALIB_SRC_DIR}/lua.c
        ${LUALIB_SRC_DIR}/loslib.c
        ${LUALIB_SRC_DIR}/ldump.c
        ${LUALIB_SRC_DIR}/lmem.c
        ${LUALIB_SRC_DIR}/liolib.c
        ${LUALIB_SRC_DIR}/ldebug.c
    )

#INCLUDE_DIRECTORIES(src)

IF(NOT MINGW AND NOT MSVC)
  ADD_DEFINITIONS(-DLUA_USE_POSIX -DLUA_USE_DLOPEN)
ENDIF(NOT MINGW AND NOT MSVC)

ADD_DEFINITIONS(-DLUA_COMPAT_MODULE)

ADD_LIBRARY ( lua52 STATIC ${lualib_SRCS} ${lualib_HDRS} )

SET ( LUALIB_IMPORT_HEADERS 
        ${LUALIB_SRC_DIR}/lua.h
        ${LUALIB_SRC_DIR}/luaconf.h
        ${LUALIB_SRC_DIR}/lualib.h
        ${LUALIB_SRC_DIR}/lauxlib.h
    )

INSTALL ( TARGETS lua52
            DESTINATION ${HELIUM_THIRD_PARTY_OUTPUT_PATH}/lualib/lib
        )

INSTALL ( FILES ${LUALIB_IMPORT_HEADERS}            
            DESTINATION ${HELIUM_THIRD_PARTY_OUTPUT_PATH}/lualib/include
        )

INSTALL ( FILES ${CMAKE_SOURCE_DIR}/luaIncludes.h            
            DESTINATION ${HELIUM_THIRD_PARTY_OUTPUT_PATH}/lualib/include
        )
