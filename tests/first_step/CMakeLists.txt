CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT( firstStepTest )


SET( firstStepTest ${CMAKE_SOURCE_DIR}/tests/first_step)

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )
SET( exp_outoput_dir ${CMAKE_BINARY_DIR}/Release )

INCLUDE_DIRECTORIES(${firstStepTest}/include)

SET( firstStepTest_SRCS
     ${firstStepTest}/src/main.cpp )

SET( firstStepTest_HDRS
     ${firstStepTest}/include/firstStepTest.h )

ADD_EXECUTABLE( firstStepTest ${firstStepTest_SRCS} )

