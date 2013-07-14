CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "FIRST 3D TEST GENERATING")

PROJECT( first3dTest )

SET ( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
INCLUDE ( heliumIncludes )

SET( FIRST_3D_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/first3D_step )
INCLUDE_DIRECTORIES ( ${FIRST_3D_TEST_DIR}/include )

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )

SET ( first3DTest_SRCS
      ${FIRST_3D_TEST_DIR}/src/main.cpp 
      ${FIRST_3D_TEST_DIR}/src/first3dTest.cpp 
    )

SET ( first3DTest_HDRS
      ${FIRST_3D_TEST_DIR}/include/first3dTest.h 
    )

ADD_EXECUTABLE ( first3dTest
                 ${first3DTest_SRCS}   
                 ${first3DTest_HDRS}
               )

IF(WIN32)
    set_target_properties( first3dTest PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows") 
    set_target_properties( first3dTest PROPERTIES COMPILE_DEFINITIONS_DEBUG "_WINDOWS")
    set_target_properties( first3dTest PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    set_target_properties( first3dTest PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_WINDOWS")
    set_target_properties( first3dTest PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    set_target_properties( first3dTest PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( first3dTest PROPERTIES COMPILE_DEFINITIONS _UNICODE,UNICODE)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( first3dTest
                        ${LIB_POLYCODE}
                      )
