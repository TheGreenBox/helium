CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: SCREEN OBJECTS")

PROJECT( heliumScreenObjects )

INCLUDE( heliumIncludes )

SET ( heliumScreenObjects_SRCS
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/src/heliumScreenConsole.cpp
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/src/heliumScreenObjects.cpp
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/src/heliumScreenButton.cpp 
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/src/heliumPreparedScreenButton.cpp
    )

SET ( heliumScreenObjects_HDRS
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/include/heliumScreenConsole.h
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/include/heliumScreenObjects.h
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/include/heliumScreenButton.h
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/include/heliumPreparedScreenButton.h
    ) 

ADD_LIBRARY ( heliumScreenObjects STATIC
                    ${heliumScreenObjects_SRCS}
                    ${heliumScreenbjects_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumScreenObjects
                            ${LIB_POLYCODE}
                      )

