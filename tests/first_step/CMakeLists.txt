CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT( expFirstLib )


SET( firstModuleSRC  ${CMAKE_SOURCE_DIR}/modules/firstModule)

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/modules )
SET( exp_outoput_dir ${CMAKE_BINARY_DIR}/Release )

INCLUDE_DIRECTORIES(${firstModuleSRC}/include)

SET( expFirstLib_SRCS
     ${firstModuleSRC}/src/firstLib.cpp )

SET( expFirstLib_HDRS
     ${firstModuleSRC}/include/firstLib.h )

ADD_LIBRARY( expFirstLib SHARED ${expFirstLib_SRCS} )

