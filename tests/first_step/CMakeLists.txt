CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "FIRST TEST GENERATING")

PROJECT( firstStepTest )

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
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

IF(WIN32)
    set_target_properties(helium PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows") 
    set_target_properties(helium PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
    set_target_properties(helium PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    set_target_properties(helium PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
    set_target_properties(helium PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    set_target_properties(helium PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( firstStepTest
                        ${LIB_POLYCODE}
                      )
