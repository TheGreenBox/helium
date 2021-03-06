CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "FIRST TEST GENERATING")

PROJECT( firstStepTest )

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
INCLUDE(heliumIncludes)

SET( FIRST_STEP_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/first_step)
INCLUDE_DIRECTORIES ( ${FIRST_STEP_TEST_DIR}/include )

SET( RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests )

SET ( firstStepTest_SRCS
      ${FIRST_STEP_TEST_DIR}/src/main.cpp
      ${FIRST_STEP_TEST_DIR}/src/firstTestClass.cpp
      ${SRC_STATIC_LIB}
    )

SET ( firstStepTest_HDRS
      ${FIRST_STEP_TEST_DIR}/include/firstTestClass.h
    )

ADD_EXECUTABLE ( firstStepTest
                 ${firstStepTest_SRCS}
                 ${firstStepTest_HDRS}
               )
IF( UNIX )
ELSEIF( WIN32 )
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( firstStepTest PROPERTIES COMPILE_DEFINITIONS _UNICODE,UNICODE)
ENDIF()

TARGET_LINK_LIBRARIES ( firstStepTest
                        ${LIB_POLYCODE}
                      )

INSTALL ( TARGETS firstStepTest
            DESTINATION ${OUTCOME_PATH}
        )

