CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE( STATUS "HELIUM USER INPUT MODULE:" )

PROJECT( heliumUserInput )

INCLUDE( heliumIncludes )

SET ( heliumUserInput_SRCS
        ${HELIUM_MODULES_DIR}/userInput/src/keyboardHandler.cpp
        ${HELIUM_MODULES_DIR}/userInput/src/heliumInputDipather.cpp
    )

SET ( heliumUserInput_HDRS
        ${HELIUM_MODULES_DIR}/userInput/include/keyboardHandler.h
        ${HELIUM_MODULES_DIR}/userInput/include/heliumInputDipather.h
        ${HELIUM_MODULES_DIR}/userInput/include/heliumUserInputHandler.h
    ) 

ADD_LIBRARY ( heliumUserInput STATIC
                ${heliumUserInput_SRCS}
                ${heliumUserInput_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumUserInput
                            ${LIB_POLYCODE}
                            heliumScreenObjects
                      )

