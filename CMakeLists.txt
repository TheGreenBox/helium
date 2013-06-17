CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "START HELIUM GENERATING")

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

INCLUDE( heliumIncludes )
INCLUDE( heliumResourceIncludes )

# -------------------------------------------------------------------
# ------ modules building -------

ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/heliumGameCore)
ADD_SUBDIRECTORY ( ${HELIUM_MODULES_DIR}/heliumMainMenu)

# -------------------------------------------------------------------

# -------------------------------------------------------------------
# ------ test building -------

ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/tests/first_step)
ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/tests/first3D_step)

# template test - not for real build
#ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/tests/template_test)

# -------------------------------------------------------------------

ADD_SUBDIRECTORY ( ${CMAKE_SOURCE_DIR}/game)

MESSAGE(STATUS "END HELIUM GENERATING")

