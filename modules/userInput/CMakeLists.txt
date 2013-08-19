CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE( STATUS "HELIUM USER INPUT MODULE:" )

PROJECT( heliumUserInput )

INCLUDE( heliumIncludes )

SET ( heliumUserInput_SRCS
        ${HELIUM_MODULES_DIR}/userInput/src/keyboardHandler.cpp
    )

SET ( heliumUserInput_HDRS
        ${HELIUM_MODULES_DIR}/userInput/include/keyboardHandler.h
    ) 

ADD_LIBRARY ( heliumUserInput STATIC
                ${heliumUserInput_SRCS}
                ${heliumUserInput_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumUserInput
                            ${LIB_POLYCODE}
                      )

