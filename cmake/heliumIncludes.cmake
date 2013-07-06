FIND_PACKAGE( PolyCore REQUIRED)
FIND_PACKAGE( PolycodeModules REQUIRED)
FIND_PACKAGE( OpenGL REQUIRED)

# Use SDL on non-Apple unixes
IF(UNIX AND NOT APPLE)
    FIND_PACKAGE( SDL REQUIRED)
ENDIF(UNIX AND NOT APPLE)

SET ( HELIUM_MODULES_DIR ${CMAKE_SOURCE_DIR}/modules)

IF( CMAKE_BUILD_TYPE STREQUAL Release )
    SET ( LIB_POLYCODE 
          ${LIB_POLYCODE_CORE}
          ${LIB_POLYCODE_MODULES}
          ${SDL_LIBRARY}
          ${OPENGL_LIBRARIES} # GL and GLU
        )

ELSEIF( CMAKE_BUILD_TYPE STREQUAL Debug )
    SET ( LIB_POLYCODE
          ${LIB_POLYCODE_CORE_DEBUG}
          ${LIB_POLYCODE_MODULES_DEBUG}
          ${SDL_LIBRARY}
          ${OPENGL_LIBRARIES} # GL and GLU
        )
ELSE()
    MESSAGE (ERROR "CMAKE_BUILD_TYPE must be defined")
ENDIF()

INCLUDE_DIRECTORIES ( ${HELIUM_MODULES_DIR}/heliumGameCore/include
                      ${HELIUM_MODULES_DIR}/heliumMainMenu/include
                      ${HELIUM_MODULES_DIR}/heliumSceneObjects/include
                      ${HELIUM_MODULES_DIR}/util
                      ${POLYCODE_CORE_INCLUDE_DIR}
                      ${POLYCODE_MODULES_INCLUDE_DIR}
                      ${SDL_INCLUDE_DIR}
                      ${OPENGL_INCLUDE_DIR}
                    )

LINK_DIRECTORIES ( ${HELIUM_MODULES_DIR}/heliumGameCore )
LINK_DIRECTORIES ( ${HELIUM_MODULES_DIR}/heliumMainMenu )
LINK_DIRECTORIES ( ${HELIUM_MODULES_DIR}/heliumSceneObjects )

IF(UNIX)
    ADD_DEFINITIONS(-DOS_LINUX) 
ENDIF(UNIX)

IF(WIN32)
    ADD_DEFINITIONS(-DOS_WIN32)
ENDIF(WIN32)

# GET_PROPERTY(inc_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
# message("inc_dirs = ${inc_dirs}")

