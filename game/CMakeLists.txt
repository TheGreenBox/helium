CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM GAME GENERATING")

PROJECT( helium )

SET ( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
SET ( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET ( COMMON_GAME_SRC_DIR ${CMAKE_SOURCE_DIR}/game )

INCLUDE( heliumIncludes )

INCLUDE_DIRECTORIES ( ${COMMON_GAME_SRC_DIR}/include )

SET ( helium_SRCS
        ${COMMON_GAME_SRC_DIR}/src/main.cpp 
        ${COMMON_GAME_SRC_DIR}/src/commonGameLoop.cpp 
    )

SET ( helium_HDRS
        ${COMMON_GAME_SRC_DIR}/include/commonGameLoop.h
    )

ADD_EXECUTABLE( helium ${helium_SRCS} ${helium_HDRS} )

TARGET_LINK_LIBRARIES ( helium 
                            heliumGameCore 
                            heliumMainMenu 
                            ${LIB_POLYCODE}
                      )

