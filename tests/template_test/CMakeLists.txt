CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


#---------------------------------------
# please set test name
# replce template for your name

SET( TEST_NAME "template" )

#---------------------------------------


# test speach to building log
MESSAGE(STATUS "TEMPLATE TEST GENERATING")

# test name
PROJECT( ${TEST_NAME} )

#set place where will live test executable file
SET( RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests )
# set helium cmake modules directory
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
# include helium common include files and library
INCLUDE(heliumIncludes)


SET( ${TEST_NAME}_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/${TEST_NAME}_test)

INCLUDE_DIRECTORIES ( ${${TEST_NAME}_TEST_DIR}/include )

SET ( ${TEST_NAME}_SRCS
      ${${TEST_NAME}_TEST_DIR}/src/main.cpp
      ${SRC_STATIC_LIB}
      # end other cpp test files if it exist
    )

SET ( ${TEST_NAME}_HDRS
      # headers test files if it exist
    )

ADD_EXECUTABLE ( ${TEST_NAME}
                 ${${TEST_NAME}_SRCS}
                 ${${TEST_NAME}_HDRS}
               )

IF(WIN32)
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES COMPILE_DEFINITIONS _UNICODE,UNICODE)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( ${TEST_NAME}
                        ${LIB_POLYCODE}
                      )

INSTALL ( TARGETS ${TEST_NAME}
            DESTINATION ${OUTCOME_PATH}
        )

