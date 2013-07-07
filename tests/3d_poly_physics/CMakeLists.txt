CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


#---------------------------------------
# please set test name
# replce template for your name 

SET( TEST_NAME "3d_poly_physics" )

#---------------------------------------


# test speach to building log
MESSAGE(STATUS "TEMPLATE TEST GENERATING")

# test name
PROJECT( ${TEST_NAME} )

#set place where will live test executable file 
SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )
# set helium cmake modules directory
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
# include helium common include files and library
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
   SET_TARGET_PROPERTIES( ${TEST_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")
ENDIF(WIN32)
# ----- ??? -----

TARGET_LINK_LIBRARIES ( ${TEST_NAME}
                        ${LIB_POLYCODE}
                      )
