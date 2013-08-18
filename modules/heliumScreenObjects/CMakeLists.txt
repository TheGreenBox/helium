CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: SCREEN OBJECTS")

PROJECT( heliumScreenObjects )

INCLUDE( heliumIncludes )

SET ( heliumScreenObjects_SRCS
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/src/heliumScreenConsole.cpp
    )

SET ( heliumScreenObjects_HDRS
        ${HELIUM_MODULES_DIR}/heliumScreenObjects/src/heliumScreenConsole.h
    ) 

ADD_LIBRARY ( heliumScreenObjects STATIC
                    ${heliumScreenObjects_SRCS}
                    ${heliumScreenbjects_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumScreenObjects
                            ${LIB_POLYCODE}
                      )

