CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT( firstStepTest )

SET(CMAKE_MODULE_PATH ${helium_SOURCE_DIR}/cmake/)
INCLUDE(heliumIncludes)

SET( firstStepTest ${CMAKE_SOURCE_DIR}/tests/first_step)

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )

SET( firstStepTest_SRCS
     ${firstStepTest}/src/main.cpp )

SET( firstStepTest_HDRS
     ${firstStepTest}/include/firstStepTest.h )

ADD_EXECUTABLE ( firstStepTest
                 ${firstStepTest_SRCS}   
                 ${firstStepTest_HDRS}
               )

TARGET_LINK_LIBRARIES ( firstStepTest
                        ${LIB_POLYCODE_CORE}
                      )
