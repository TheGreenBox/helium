CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: ")

INCLUDE( heliumIncludes )

PROJECT( heliumGameCore )

SET ( heliumGameCore_SRCS
        ${HELIUM_MODULES_DIR}/heliumGameCore/src/heliumGameCore.cpp
    )

SET ( heliumGameCore_HDRS
        ${HELIUM_MODULES_DIR}/heliumGameCore/include/heliumGameCore.h
    ) 

ADD_LIBRARY ( heliumGameCore STATIC
                    ${heliumGameCore_SRCS}
                    ${heliumGameCore_HDRS} 
               )

TARGET_LINK_LIBRARIES ( heliumGameCore
                            ${LIB_POLYCODE}
                      )

