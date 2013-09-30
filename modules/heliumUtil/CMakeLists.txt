CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: << heliumUtil >>")

PROJECT( heliumUtil )

INCLUDE( heliumIncludes )

SET( HELIUM_UTIL_PROJECT_DIR ${HELIUM_MODULES_DIR}/heliumUtil )

SET ( heliumGameCore_SRCS
        ${HELIUM_UTIL_PROJECT_DIR}/src/pathGlobal.cpp
        ${HELIUM_UTIL_PROJECT_DIR}/src/debugTools.cpp
    )

SET ( heliumGameCore_HDRS
        ${HELIUM_UTIL_PROJECT_DIR}/include/pathGlobal.h
        ${HELIUM_UTIL_PROJECT_DIR}/include/mainMacro.h
        ${HELIUM_UTIL_PROJECT_DIR}/include/debugTools.h
    )

ADD_LIBRARY ( heliumUtil STATIC
                ${heliumGameCore_SRCS}
                ${heliumGameCore_HDRS}
            )

