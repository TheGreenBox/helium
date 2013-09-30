CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "TEST: << first3DModel >> GENERATING")

PROJECT( first3DModel )

SET( RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests )
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

INCLUDE(heliumIncludes)

SET( 3D_POLY_PHYS_TEST_DIR ${CMAKE_SOURCE_DIR}/tests/first3DModel )

INCLUDE_DIRECTORIES ( ${3D_POLY_PHYS_TEST_DIR}/include )

SET ( first3DModel_SRCS
      ${3D_POLY_PHYS_TEST_DIR}/src/main.cpp
      ${3D_POLY_PHYS_TEST_DIR}/src/helium3DWrap.cpp
      ${SRC_STATIC_LIB}
    )

SET ( first3DModel_HDRS
      ${3D_POLY_PHYS_TEST_DIR}/src/helium3DWrap.h
    )

ADD_EXECUTABLE ( first3DModel
                 ${first3DModel_SRCS}
                 ${first3DModel_HDRS}
               )

IF(WIN32)
    set_target_properties( first3DModel PROPERTIES LINK_FLAGS_DEBUG                   "/SUBSYSTEM:windows")
    set_target_properties( first3DModel PROPERTIES COMPILE_DEFINITIONS_DEBUG          "_WINDOWS")
    set_target_properties( first3DModel PROPERTIES LINK_FLAGS_RELWITHDEBINFO          "/SUBSYSTEM:windows")
    set_target_properties( first3DModel PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_WINDOWS")
    set_target_properties( first3DModel PROPERTIES LINK_FLAGS_RELEASE                 "/SUBSYSTEM:windows")
    set_target_properties( first3DModel PROPERTIES LINK_FLAGS_MINSIZEREL              "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( first3DModel PROPERTIES COMPILE_DEFINITIONS                _UNICODE,UNICODE)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( first3DModel
                        ${LIB_POLYCODE}
                        heliumUtil
                      )

INSTALL ( TARGETS first3DModel
            DESTINATION ${OUTCOME_PATH}
        )

