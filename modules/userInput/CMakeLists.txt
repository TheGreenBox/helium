CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE( STATUS "HELIUM USER INPUT MODULE:" )

PROJECT( heliumUserInput )

INCLUDE( heliumIncludes )

SET ( heliumUserInput_SRCS
        ${HELIUM_MODULES_DIR}/userInput/src/heliumPreparedKeyHandlers.cpp
        ${HELIUM_MODULES_DIR}/userInput/src/heliumInputDipather.cpp
        ${HELIUM_MODULES_DIR}/userInput/src/heliumPreparedMouseHandlers.cpp 
    )

SET ( heliumUserInput_HDRS
        ${HELIUM_MODULES_DIR}/userInput/include/heliumPreparedKeyHandlers.h
        ${HELIUM_MODULES_DIR}/userInput/include/heliumInputDipather.h
        ${HELIUM_MODULES_DIR}/userInput/include/heliumUserInputHandler.h
        ${HELIUM_MODULES_DIR}/userInput/include/heliumPreparedMouseHandlers.h
    ) 

ADD_LIBRARY ( heliumUserInput STATIC
                ${heliumUserInput_SRCS}
                ${heliumUserInput_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumUserInput
                            ${LIB_POLYCODE}
                            heliumScreenObjects
                      )

