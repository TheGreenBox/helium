SET ( POLYCODE_SEARCH_PATHS
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/lib
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/Dependencies/lib
      
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/include
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/PolycodeView
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/Dependencies/include
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/Dependencies/include/AL
    )

SET ( LIB_PNG_POSIBLE_NAMES 
        "png"
        "png15"
        "png15_static" 
        "libpng15_static" 
    )

SET ( LIB_PNG_POSIBLE_DEBUG_NAMES 
        "pngd"
        "png15d"
        "png15_staticd" 
        "libpng15_staticd" 
    )

# posible names for zpng 
SET ( LIB_Z_POSIBLE_NAMES 
        "z"
        "zlib"
    )

SET ( LIB_Z_POSIBLE_DEBUG_NAMES 
        "z"
        "zlibd"
    )

# posible names for OpenAL 
SET ( LIB_OPENAL_POSIBLE_NAMES 
        "openal"
        "OpenAL32"
    )

SET ( LIB_OPENAL_POSIBLE_DEBUG_NAMES 
        "openald"
        "OpenAL32d"
    )

SET ( POLLYCORE_LIB_NAMES
        "Polycore"
        "freetype"
        "libvorbisfile"
        "libvorbis"
        "libogg"
        ${LIB_OPENAL_POSIBLE_NAMES}
        "physfs"
        ${LIB_PNG_POSIBLE_NAMES}
        ${LIB_Z_POSIBLE_NAMES}
    )

SET ( POLLYCORE_LIB_DEBUG_NAMES
        "Polycore_d"
        "freetype_d"
        "libvorbisfiled"
        "libvorbisd"
        "liboggd"
        ${LIB_OPENAL_POSIBLE_DEBUG_NAMES}
        "physfsd"
        ${LIB_PNG_POSIBLE_DEBUG_NAMES}
        ${LIB_Z_POSIBLE_DEBUG_NAMES}
    )

FIND_PATH ( POLYCODE_CORE_CORE_INCLUDE_DIR NAMES PolyCore.h
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )

FIND_PATH ( POLYCODE_VIEW_DIR NAMES PolycodeView.cpp
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )

SET ( LIB_POLYVIEW_SRC 
       ${POLYCODE_VIEW_DIR}/PolycodeView.cpp
    )

FIND_PATH ( POLYCODE_CORE_DEPEND_INCLUDE_DIR NAMES pnglibconf.h
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )

FIND_PATH ( POLYCODE_CORE_DEPEND_AL_INCLUDE_DIR NAMES efx-creative.h
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )

SET ( POLYCODE_CORE_INCLUDE_DIR
      ${POLYCODE_CORE_CORE_INCLUDE_DIR}
      ${POLYCODE_CORE_DEPEND_INCLUDE_DIR}
      ${POLYCODE_CORE_DEPEND_AL_INCLUDE_DIR} 
      ${POLYCODE_VIEW_DIR}
    )

FOREACH( LIBRARY ${POLLYCORE_LIB_NAMES} )
    FIND_LIBRARY  ( LIB_${LIBRARY} NAME ${LIBRARY}
                    HINTS
                    NO_DEFAULT_PATH
                    NO_CMAKE_ENVIRONMENT_PATH
                    NO_CMAKE_SYSTEM_PATH
                    NO_SYSTEM_ENVIRONMENT_PATH
                    NO_CMAKE_PATH
                    CMAKE_FIND_FRAMEWORK NEVER
                    $ENV{POLYCODEDIR}
                    $ENV{POLYCODE_PATH}
                    PATH_SUFFIXES lib 
                    PATHS ${POLYCODE_SEARCH_PATHS} 
                  )
    
    IF( LIB_${LIBRARY} )
       # MESSAGE(STATUS ${LIBRARY} " was found")
        SET ( LIB_POLYCODE_CORE  
                ${LIB_POLYCODE_CORE}
                ${LIB_${LIBRARY}}
            )
    ENDIF( LIB_${LIBRARY} )
ENDFOREACH( LIBRARY ${POLLYCORE_LIB_NAMES} )

FOREACH( LIBRARY ${POLLYCORE_LIB_DEBUG_NAMES} )
    FIND_LIBRARY  ( LIB_${LIBRARY} NAME ${LIBRARY}
                    HINTS
                    NO_DEFAULT_PATH
                    NO_CMAKE_ENVIRONMENT_PATH
                    NO_CMAKE_SYSTEM_PATH
                    NO_SYSTEM_ENVIRONMENT_PATH
                    NO_CMAKE_PATH
                    CMAKE_FIND_FRAMEWORK NEVER
                    $ENV{POLYCODEDIR}
                    $ENV{POLYCODE_PATH}
                    PATH_SUFFIXES lib 
                    PATHS ${POLYCODE_SEARCH_PATHS} 
                  )
    
    IF( LIB_${LIBRARY} )   
      #  MESSAGE(STATUS ${LIBRARY} " DEBUG was found")
        SET ( LIB_POLYCODE_CORE_DEBUG
                ${LIB_POLYCODE_CORE_DEBUG}
                ${LIB_${LIBRARY}}
            )
    ENDIF( LIB_${LIBRARY} )
ENDFOREACH( LIBRARY ${POLLYCORE_LIB_DEBUG_NAMES} )

IF( POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG )
    IF( NOT POLYCODE_CORE_FOUND )
        SET(POLYCODE_CORE_FOUND TRUE)
        MESSAGE(STATUS "POLYCODE CORE LIB WAS FOUND")
        MESSAGE(STATUS "Release:")
        MESSAGE(STATUS ${LIB_POLYCODE_CORE})
        MESSAGE(STATUS "Debug:")
        MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})
    ENDIF()
ENDIF()

