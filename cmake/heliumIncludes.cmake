MESSAGE(STATUS "start helium includes")

FIND_PACKAGE(Polycode REQUIRED)

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/core/contents/include
    ${CMAKE_SOURCE_DIR}/gameMap/contents/include
    ${CMAKE_SOURCE_DIR}/mainMenu/contents/include
    ${POLYCODE_CORE_INCLUDE_DIR}
)
