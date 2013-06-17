CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: ")


INCLUDE( heliumIncludes )

PROJECT( heliumCore )

SET ( heliumCore_SRCS
        ${HELIUM_MODULES_DIR}/heliumCore/src/heliumCore.cpp 
        ${HELIUM_MODULES_DIR}/heliumCore/src/heliumGameCore.cpp
    )

SET ( heliumCore_HDRS
        ${HELIUM_MODULES_DIR}/heliumCore/include/heliumCore.h 
        ${HELIUM_MODULES_DIR}/heliumCore/include/heliumGameCore.h
    ) 

ADD_EXECUTABLE( heliumCore ${heliumCore_SRCS} ${heliumCore_HDRS} )

TARGET_LINK_LIBRARIES ( )
