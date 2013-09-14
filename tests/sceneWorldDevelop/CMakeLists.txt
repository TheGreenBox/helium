CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "\"SCENE WORLD DEVELOP TEST\" GENERATING")

PROJECT( sceneWorldDevelop )

SET( RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests )
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

INCLUDE(heliumIncludes)

SET( TEST_DIR ${CMAKE_SOURCE_DIR}/tests/sceneWorldDevelop )

INCLUDE_DIRECTORIES ( ${TEST_DIR}/include )

SET ( sceneWorldDevelop_SRCS
      ${TEST_DIR}/src/main.cpp
      ${TEST_DIR}/src/proGameObject.cpp
      ${SRC_STATIC_LIB}
    )

SET ( sceneWorldDevelop_HDRS
      ${TEST_DIR}/src/proGameObject.h
    )

ADD_EXECUTABLE ( sceneWorldDevelop
                 ${sceneWorldDevelop_SRCS}
                 ${sceneWorldDevelop_HDRS}
               )

IF(WIN32)
    set_target_properties( sceneWorldDevelop PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:windows")
    set_target_properties( sceneWorldDevelop PROPERTIES COMPILE_DEFINITIONS_DEBUG "_WINDOWS")
    set_target_properties( sceneWorldDevelop PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows")
    set_target_properties( sceneWorldDevelop PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_WINDOWS")
    set_target_properties( sceneWorldDevelop PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:windows")
    set_target_properties( sceneWorldDevelop PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows")
    SET_TARGET_PROPERTIES( sceneWorldDevelop PROPERTIES COMPILE_DEFINITIONS _UNICODE,UNICODE)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES ( sceneWorldDevelop
                        ${LIB_POLYCODE}
                        heliumGameCore
                        heliumUserInput
                        heliumUtil
                        heliumScreenObjects
                        heliumSceneObjects
                      )

INSTALL ( TARGETS sceneWorldDevelop
            DESTINATION ${OUTCOME_PATH}
        )

