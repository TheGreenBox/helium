CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "#D_POLY_PHYSICS TEST GENERATING")

SET( TEST_NAME "3d_poly_physics" )

PROJECT( ${TEST_NAME} )

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
INCLUDE(heliumIncludes)


SET( 3D_POLY_PHYS_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/${TEST_NAME})

INCLUDE_DIRECTORIES ( ${3D_POLY_PHYS_TEST_DIR}/include )

SET ( ${TEST_NAME}_SRCS
      ${3D_POLY_PHYS_TEST_DIR}/src/main.cpp 
      ${3D_POLY_PHYS_TEST_DIR}/src/wrapClasses.cpp 
      # end other cpp test files if it exist
    )

SET ( ${TEST_NAME}_HDRS
      ${3D_POLY_PHYS_TEST_DIR}/src/wrapClasses.h 
      # headers test files if it exist
    )

ADD_EXECUTABLE ( ${TEST_NAME}
                 ${${TEST_NAME}_SRCS}   
                 ${${TEST_NAME}_HDRS}
               )
# ----- Do you realy need it ? -----
IF(WIN32)
    set_target_properties( ${TEST_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows") 
    set_target_properties( ${TEST_NAME} PROPERTIES COMPILE_DEFINITIONS_DEBUG "_WINDOWS")
    set_target_properties( ${TEST_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    set_target_properties( ${TEST_NAME} PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_WINDOWS")
    set_target_properties( ${TEST_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    set_target_properties( ${TEST_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
ENDIF(WIN32)
# ----- ??? -----

TARGET_LINK_LIBRARIES ( ${TEST_NAME}
                        ${LIB_POLYCODE}
                      )
