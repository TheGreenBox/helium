FIND_PACKAGE( PolyCore REQUIRED)
FIND_PACKAGE( PolycodeModules REQUIRED)
FIND_PACKAGE( OpenGL REQUIRED)

# Use SDL on non-Apple unixes
IF(UNIX AND NOT APPLE)
    FIND_PACKAGE( SDL REQUIRED)
ENDIF(UNIX AND NOT APPLE)

SET ( LIB_POLYCODE 
      ${LIB_POLYCODE_CORE}
      ${LIB_POLYCODE_MODULES}
      ${SDL_LIBRARY}
      ${OPENGL_LIBRARIES} # GL and GLU
    )

SET ( LIB_POLYCODE_DEBUG
      ${LIB_POLYCODE_CORE_DEBUG}
      ${LIB_POLYCODE_MODULES_DEBUG}
      ${SDL_LIBRARY}
      ${OPENGL_LIBRARIES} # GL and GLU
    )


INCLUDE_DIRECTORIES ( ${CMAKE_SOURCE_DIR}/modules/core/include
                      ${CMAKE_SOURCE_DIR}/modules/gameMap/include
                      ${CMAKE_SOURCE_DIR}/modules/mainMenu/include
                      ${CMAKE_SOURCE_DIR}/modules/mainLoop/include
                      ${POLYCODE_CORE_INCLUDE_DIR}
                      ${POLYCODE_MODULES_INCLUDE_DIR}
                      ${SDL_INCLUDE_DIR}
                      ${OPENGL_INCLUDE_DIR}
                    )

IF(UNIX)
    ADD_DEFINITIONS(-DOS_LINUX) 
ENDIF(UNIX)

IF(WIN32)
    ADD_DEFINITIONS(-DOS_WIN32)
ENDIF(WIN32)

# GET_PROPERTY(inc_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
# message("inc_dirs = ${inc_dirs}")

