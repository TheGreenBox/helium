CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "firstKeyControl TEST GENERATING")

PROJECT( firstKeyControl )

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

INCLUDE(heliumIncludes)

SET( 3D_POLY_PHYS_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/firstKeyControl )

INCLUDE_DIRECTORIES ( ${3D_POLY_PHYS_TEST_DIR}/include )

SET ( firstKeyControl_SRCS
      ${3D_POLY_PHYS_TEST_DIR}/src/main.cpp 
      ${3D_POLY_PHYS_TEST_DIR}/src/wrapClasses.cpp 
      ${SRC_STATIC_LIB}
    )

SET ( firstKeyControl_HDRS
      ${3D_POLY_PHYS_TEST_DIR}/src/wrapClasses.h 
    )

ADD_EXECUTABLE ( firstKeyControl
                 ${firstKeyControl_SRCS}   
                 ${firstKeyControl_HDRS}
               )

IF(WIN32)
    set_target_properties( firstKeyControl PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows") 
    set_target_properties( firstKeyControl PROPERTIES COMPILE_DEFINITIONS_DEBUG "_WINDOWS")
    set_target_properties( firstKeyControl PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    set_target_properties( firstKeyControl PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_WINDOWS")
    set_target_properties( firstKeyControl PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    set_target_properties( firstKeyControl PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( firstKeyControl PROPERTIES COMPILE_DEFINITIONS _UNICODE,UNICODE)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( firstKeyControl
                        ${LIB_POLYCODE}
                        heliumUtil
                        heliumScreenObjects
                      )

INSTALL ( TARGETS firstKeyControl
            DESTINATION ${OUTCOME_PATH}
        )

