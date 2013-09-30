CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: << helium_3D_Object >>")

PROJECT( helium_3D_Object )

INCLUDE( heliumIncludes )

SET( HELIUM_3D_OBJECT_DIR ${HELIUM_MODULES_DIR}/helium_3D_Object )

SET ( helium_3D_Object_SRCS
        ${HELIUM_3D_OBJECT_DIR}/src/helium_3D_Character.cpp
        ${HELIUM_3D_OBJECT_DIR}/src/helium_3D_CharVitals.cpp
        ${HELIUM_3D_OBJECT_DIR}/src/helium_3D_ObjectPackaging.cpp
        ${HELIUM_3D_OBJECT_DIR}/src/helium_3D_PreparedObjects.cpp
        ${HELIUM_3D_OBJECT_DIR}/src/helium_3D_World.cpp
    )

SET ( helium_3D_Object_HDRS
        ${HELIUM_3D_OBJECT_DIR}/include/helium_3D.h
        ${HELIUM_3D_OBJECT_DIR}/include/helium_3D_Character.h
        ${HELIUM_3D_OBJECT_DIR}/include/helium_3D_CharVitals.h
        ${HELIUM_3D_OBJECT_DIR}/include/helium_3D_ObjectPackaging.h
        ${HELIUM_3D_OBJECT_DIR}/include/helium_3D_PreparedObjects.h
        ${HELIUM_3D_OBJECT_DIR}/include/helium_3D_World.h
    ) 

ADD_LIBRARY ( helium_3D_Object STATIC
                    ${helium_3D_Object_SRCS}
                    ${helium_3D_Object_HDRS} 
            )

TARGET_LINK_LIBRARIES ( helium_3D_Object
                            ${LIB_POLYCODE}
                      )

