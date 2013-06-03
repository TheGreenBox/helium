MESSAGE(STATUS "start helium includes cmake module")

FIND_PACKAGE(PolyCore REQUIRED)
FIND_PACKAGE(PolycodeModules REQUIRED)

INCLUDE_DIRECTORIES ( ${CMAKE_SOURCE_DIR}/core/include
                      ${CMAKE_SOURCE_DIR}/gameMap/include
                      ${CMAKE_SOURCE_DIR}/mainMenu/include
                      ${POLYCODE_CORE_INCLUDE_DIR}
                    )

# GET_PROPERTY(inc_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
# message("inc_dirs = ${inc_dirs}")

