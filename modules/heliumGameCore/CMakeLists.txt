CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: ")

PROJECT( heliumGameCore )

INCLUDE( heliumIncludes )

SET ( heliumGameCore_SRCS
        ${HELIUM_MODULES_DIR}/heliumGameCore/src/heliumGameCore.cpp
        ${HELIUM_MODULES_DIR}/heliumGameCore/src/heliumGameGlobal.cpp 
    )

SET ( heliumGameCore_HDRS
        ${HELIUM_MODULES_DIR}/heliumGameCore/include/heliumGameCore.h
        ${HELIUM_MODULES_DIR}/heliumGameCore/include/heliumGameCoreObjects.h
        ${HELIUM_MODULES_DIR}/heliumGameCore/include/heliumGameGlobal.h
    ) 

ADD_LIBRARY ( heliumGameCore STATIC
                    ${heliumGameCore_SRCS}
                    ${heliumGameCore_HDRS} 
               )

TARGET_LINK_LIBRARIES ( heliumGameCore
                            ${LIB_POLYCODE}
                            heliumSceneObjects
                            heliumScreenObjects
                            heliumUserInput
                      )

