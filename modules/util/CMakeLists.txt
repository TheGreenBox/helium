CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM UTILS MODULE: ")

PROJECT( heliumUtil )

INCLUDE( heliumIncludes )

SET ( heliumGameCore_SRCS
        ${HELIUM_MODULES_DIR}/util/src/pathGlobal.cpp
        ${HELIUM_MODULES_DIR}/util/src/debugTools.cpp
    )

SET ( heliumGameCore_HDRS
        ${HELIUM_MODULES_DIR}/util/include/pathGlobal.h
        ${HELIUM_MODULES_DIR}/util/include/mainMacro.h
        ${HELIUM_MODULES_DIR}/util/include/debugTools.h
    )

ADD_LIBRARY ( heliumUtil STATIC
                    ${heliumGameCore_SRCS}
                    ${heliumGameCore_HDRS}
            )

