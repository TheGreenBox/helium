CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT( helium )

SET(CMAKE_MODULE_PATH ${helium_SOURCE_DIR}/cmake/)
MESSAGE(STATUS ${CMAKE_MODULE_PATH})
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

INCLUDE(heliumIncludes)


## ADD_SUBDIRECTORY(modules/gameMap)
## INCLUDE_DIRECTORIES(modules/gameMap/include)

# -------------------------------------------------------------------
# ------ test building -------

ADD_SUBDIRECTORY(${helium_SOURCE_DIR}/tests/first_step)

# ------ no more test building -------
# -------------------------------------------------------------------

SET( helium_SRCS
     game/main.cpp )

SET( helium_HDRS
     ) ## same_header.h )

ADD_EXECUTABLE( helium ${helium_SRCS} )

MESSAGE(STATUS "let's build helium")
MESSAGE(STATUS ${LIB_POLYCODE_CORE})
TARGET_LINK_LIBRARIES ( helium 
                        ${LIB_POLYCODE_CORE}
                      )

