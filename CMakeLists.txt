CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE( STATUS "START HELIUM GENERATING" )

SET( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/ )
SET( RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET( OUTCOME_PATH ${CMAKE_BINARY_DIR}/product )
SET( OUTCOME_RESOURCES_PATH ${OUTCOME_PATH}/helium_resource )

INCLUDE( heliumIncludes )
INCLUDE( heliumResourceIncludes )

# -------------------------------------------------------------------
# ------ modules building -------

ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/util                )
ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/userInput           )
ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/heliumSceneObjects  )
ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/heliumScreenObjects )
ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/heliumGameCore      )
ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/heliumMainMenu      )

# -------------------------------------------------------------------

# -------------------------------------------------------------------
# ------ test building -------

ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/tests/first_step      )
ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/tests/first3D_step    )
ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/tests/first3DModel    )
ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/tests/firstKeyControl )

# template test - not for real build
#ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/tests/template_test)

# -------------------------------------------------------------------

ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/game)

INSTALL ( DIRECTORY ${HELIUM_RESOURCE_SRC_DIR}/
            DESTINATION ${OUTCOME_RESOURCES_PATH}
        )

INCLUDE( heliumLibInstall )

MESSAGE(STATUS "END HELIUM GENERATING")

