CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: 3D OBJECTS WORLD")

PROJECT( helium_3D_Object )

INCLUDE( heliumIncludes )

SET( HELIUM_3D_OBJECT_DIR ${HELIUM_MODULES_DIR}/helium_3D_Object )

SET ( helium_3D_Object_SRCS
        ${HELIUM_3D_OBJECT_DIR}/src/heliumSceneObjects.cpp
        ${HELIUM_3D_OBJECT_DIR}/src/heliumPreparedSceneObjects.cpp
    )

SET ( helium_3D_Object_HDRS
        ${HELIUM_3D_OBJECT_DIR}/include/heliumSceneObjects.h
        ${HELIUM_3D_OBJECT_DIR}/include/heliumPreparedSceneObjects.h
    ) 

ADD_LIBRARY ( helium_3D_Object STATIC
                    ${helium_3D_Object_SRCS}
                    ${helium_3D_Object_HDRS} 
            )

TARGET_LINK_LIBRARIES ( helium_3D_Object
                            ${LIB_POLYCODE}
                      )

