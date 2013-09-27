CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE( STATUS "HELIUM USER INPUT MODULE:" )

PROJECT( heliumUserInput )

INCLUDE( heliumIncludes )

SET( HELIUM_USER_INPUT_PROJECT_DIR ${HELIUM_MODULES_DIR}/heliumUserInput )

SET ( heliumUserInput_SRCS
        ${HELIUM_USER_INPUT_PROJECT_DIR}/src/heliumPreparedKeyHandlers.cpp
        ${HELIUM_USER_INPUT_PROJECT_DIR}/src/heliumInputDipather.cpp
        ${HELIUM_USER_INPUT_PROJECT_DIR}/src/heliumPreparedMouseHandlers.cpp 
    )

SET ( heliumUserInput_HDRS
        ${HELIUM_USER_INPUT_PROJECT_DIR}/include/heliumPreparedKeyHandlers.h
        ${HELIUM_USER_INPUT_PROJECT_DIR}/include/heliumInputDipather.h
        ${HELIUM_USER_INPUT_PROJECT_DIR}/include/heliumUserInputHandler.h
        ${HELIUM_USER_INPUT_PROJECT_DIR}/include/heliumPreparedMouseHandlers.h
    ) 

ADD_LIBRARY ( heliumUserInput STATIC
                ${heliumUserInput_SRCS}
                ${heliumUserInput_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumUserInput
                            ${LIB_POLYCODE}
                            helium_2D_Object
                      )

