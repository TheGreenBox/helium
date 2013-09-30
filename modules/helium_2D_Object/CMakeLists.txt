CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: << helium_2D_Object >>")

PROJECT( helium_2D_Object )

INCLUDE( heliumIncludes )

SET( HELIUM_2D_OBJECT_DIR ${HELIUM_MODULES_DIR}/helium_2D_Object )

SET ( helium_2d_SRCS
        ${HELIUM_2D_OBJECT_DIR}/src/helium_2D_Button.cpp
        ${HELIUM_2D_OBJECT_DIR}/src/helium_2D_ObjectPackaging.cpp
        ${HELIUM_2D_OBJECT_DIR}/src/helium_2D_PreparedButton.cpp
        ${HELIUM_2D_OBJECT_DIR}/src/helium_2D_World.cpp
    )

SET ( helium_2d_HDRS
        ${HELIUM_2D_OBJECT_DIR}/include/helium_2D.h
        ${HELIUM_2D_OBJECT_DIR}/include/helium_2D_Button.h
        ${HELIUM_2D_OBJECT_DIR}/include/helium_2D_ObjectPackaging.h
        ${HELIUM_2D_OBJECT_DIR}/include/helium_2D_PreparedButton.h
        ${HELIUM_2D_OBJECT_DIR}/include/helium_2D_World.h
    ) 

ADD_LIBRARY ( helium_2D_Object STATIC
                    ${helium_2d_SRCS}
                    ${helium_2d_HDRS} 
            )

TARGET_LINK_LIBRARIES ( helium_2D_Object
                            ${LIB_POLYCODE}
                            helium_2D_Object
                      )

