MESSAGE(STATUS "start polycode finder module")

#../../Core/Dependencies/include 
#../../Core/Dependencies/include/AL 
#../../Core/include 

SET ( POLYCODE_SEARCH_PATHS
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/lib
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/Dependencies/lib
	  
      ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/include
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/Dependencies/include
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/Dependencies/include/AL
    )

#MESSAGE(STATUS "Let,s find polycode in this directories :")
#MESSAGE(STATUS ${POLYCODE_SEARCH_PATHS})

# - Try to find Polycode
# Once done this will define

SET ( POLLYCORE_LIB_NAMES
      "Polycore"
      "freetype"
      "libvorbisfile"
      "libvorbis"
      "libogg"
      "openal"
      "physfs"
      "png15"
      "z"
    )

SET ( POLLYCORE_LIB_DEBUG_NAMES
      "Polycore_d"
      "freetype_d"
      "libvorbisfiled"
      "libvorbisd"
      "liboggd"
      "openald"
      "physfsd"
      "png15d"
      "z"
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
MESSAGE(STATUS ${POLYCODE_CORE_CORE_INCLUDE_DIR})

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
MESSAGE(STATUS ${POLYCODE_CORE_DEPEND_INCLUDE_DIR})

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
MESSAGE(STATUS ${POLYCODE_CORE_DEPEND_AL_INCLUDE_DIR})

SET ( POLYCODE_CORE_INCLUDE_DIR
      ${POLYCODE_CORE_CORE_INCLUDE_DIR}
      ${POLYCODE_CORE_DEPEND_INCLUDE_DIR}
      ${POLYCODE_CORE_DEPEND_AL_INCLUDE_DIR} 
    )

FOREACH( LIBRARY ${POLLYCORE_LIB_NAMES} )
    
#    MESSAGE(STATUS ${LIBRARY})
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
    
#    MESSAGE(STATUS ${LIB_${LIBRARY}})
    
    set ( LIB_POLYCODE_CORE  
          ${LIB_POLYCODE_CORE}
          ${LIB_${LIBRARY}}
        )

ENDFOREACH( LIBRARY ${POLLYCORE_LIB_NAMES} )

IF(POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG)
  SET(POLYCODE_CORE_FOUND TRUE)
ENDIF(POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG)

