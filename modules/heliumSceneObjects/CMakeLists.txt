CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: SCENE OBJECTS")

PROJECT( heliumSceneObjects )

INCLUDE( heliumIncludes )

SET ( heliumSceneObjects_SRCS
        ${HELIUM_MODULES_DIR}/heliumSceneObjects/src/heliumSceneObjects.cpp
    )

SET ( heliumSceneObjects_HDRS
        ${HELIUM_MODULES_DIR}/heliumSceneObjects/include/heliumSceneObjects.h
    ) 

ADD_LIBRARY ( heliumSceneObjects STATIC
                    ${heliumSceneObjects_SRCS}
                    ${heliumSceneObjects_HDRS} 
            )

TARGET_LINK_LIBRARIES ( heliumSceneObjects
                            ${LIB_POLYCODE}
                      )

