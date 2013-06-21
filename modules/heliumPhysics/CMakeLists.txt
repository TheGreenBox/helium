CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: PHYSICS")

PROJECT( heliumPhysics )

INCLUDE( heliumIncludes )

SET ( heliumPhysics_SRCS
        ${HELIUM_MODULES_DIR}/heliumPhysics/src/heliumPhysics.cpp
    )

SET ( heliumPhysics_HDRS
        ${HELIUM_MODULES_DIR}/heliumPhysics/include/heliumPhysics.h
    ) 

ADD_LIBRARY ( heliumPhysics STATIC
                    ${heliumPhysics_SRCS}
                    ${heliumPhysics_HDRS} 
               )

TARGET_LINK_LIBRARIES ( heliumPhysics
                            ${LIB_POLYCODE}
                      )

