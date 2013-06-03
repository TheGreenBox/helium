CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT( firstStepTest )

SET(CMAKE_MODULE_PATH ${helium_SOURCE_DIR}/cmake/)
INCLUDE(heliumIncludes)

SET( FIRST_STEP_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/first_step)
INCLUDE_DIRECTORIES ( ${FIRST_STEP_TEST_DIR}/include )

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )

SET ( firstStepTest_SRCS
      ${FIRST_STEP_TEST_DIR}/src/main.cpp 
      ${FIRST_STEP_TEST_DIR}/src/firstTestClass.cpp 
    )

SET ( firstStepTest_HDRS
      ${FIRST_STEP_TEST_DIR}/include/firstTestClass.h 
    )

ADD_EXECUTABLE ( firstStepTest
                 ${firstStepTest_SRCS}   
                 ${firstStepTest_HDRS}
               )

MESSAGE(STATUS "LIB_POLYCODE_CORE : ")
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

TARGET_LINK_LIBRARIES ( firstStepTest
                        ${LIB_POLYCODE_CORE}
                      )
