CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "START GENERATING")
PROJECT( helium )

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

INCLUDE( heliumIncludes )
INCLUDE( heliumResourceIncludes )


## ADD_SUBDIRECTORY(modules/gameMap)
## INCLUDE_DIRECTORIES(modules/gameMap/include)

# -------------------------------------------------------------------
# ------ test building -------

ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/tests/first_step)
ADD_SUBDIRECTORY(${CMAKE_SOURCE_DIR}/tests/first3D_step)

# ------ no more test building -------
# -------------------------------------------------------------------

SET( helium_SRCS
     ${CMAKE_SOURCE_DIR}/game/main.cpp )

SET( helium_HDRS
     ) ## same_header.h )

ADD_EXECUTABLE( helium ${helium_SRCS} )

TARGET_LINK_LIBRARIES ( helium )

