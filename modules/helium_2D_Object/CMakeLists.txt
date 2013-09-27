CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: SCREEN OBJECTS")

PROJECT( helium_2D_Object )

INCLUDE( heliumIncludes )

SET( HELIUM_2D_OBJECT_DIR ${HELIUM_MODULES_DIR}/helium_2D_Object )

SET ( heliumScreenObjects_SRCS
        ${HELIUM_2D_OBJECT_DIR}/src/heliumScreenConsole.cpp
        ${HELIUM_2D_OBJECT_DIR}/src/heliumScreenObjects.cpp
        ${HELIUM_2D_OBJECT_DIR}/src/heliumScreenButton.cpp 
        ${HELIUM_2D_OBJECT_DIR}/src/heliumPreparedScreenButton.cpp
    )

SET ( heliumScreenObjects_HDRS
        ${HELIUM_2D_OBJECT_DIR}/include/heliumScreenConsole.h
        ${HELIUM_2D_OBJECT_DIR}/include/heliumScreenObjects.h
        ${HELIUM_2D_OBJECT_DIR}/include/heliumScreenButton.h
        ${HELIUM_2D_OBJECT_DIR}/include/heliumPreparedScreenButton.h
    ) 

ADD_LIBRARY ( helium_2D_Object STATIC
                    ${heliumScreenObjects_SRCS}
                    ${heliumScreenbjects_HDRS} 
            )

TARGET_LINK_LIBRARIES ( helium_2D_Object
                            ${LIB_POLYCODE}
                            helium_2D_Object
                      )

