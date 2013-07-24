CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "#D_POLY_PHYSICS TEST GENERATING")

PROJECT( 3dPolyPhysics )

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests )
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
INCLUDE(heliumIncludes)


SET( 3D_POLY_PHYS_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/3d_poly_physics)

INCLUDE_DIRECTORIES ( ${3D_POLY_PHYS_TEST_DIR}/include )

SET ( 3dPolyPhysics_SRCS
      ${3D_POLY_PHYS_TEST_DIR}/src/main.cpp 
      ${3D_POLY_PHYS_TEST_DIR}/src/wrapClasses.cpp 
      ${SRC_STATIC_LIB}
    )

SET ( 3dPolyPhysics_HDRS
      ${3D_POLY_PHYS_TEST_DIR}/src/wrapClasses.h 
    )

ADD_EXECUTABLE ( 3dPolyPhysics
                 ${3dPolyPhysics_SRCS}   
                 ${3dPolyPhysics_HDRS}
               )

IF(WIN32)
    set_target_properties( 3dPolyPhysics PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows") 
    set_target_properties( 3dPolyPhysics PROPERTIES COMPILE_DEFINITIONS_DEBUG "_WINDOWS")
    set_target_properties( 3dPolyPhysics PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    set_target_properties( 3dPolyPhysics PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_WINDOWS")
    set_target_properties( 3dPolyPhysics PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    set_target_properties( 3dPolyPhysics PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( 3dPolyPhysics PROPERTIES COMPILE_DEFINITIONS _UNICODE,UNICODE)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( 3dPolyPhysics
                        ${LIB_POLYCODE}
                      )

INSTALL ( TARGETS 3dPolyPhysics
            DESTINATION ${OUTCOME_PATH}/tests
        )

