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
#
#  POLYCODE_FOUND - system has Polycode
#  POLYCODE_INCLUDE_DIR - the POLYCODE include directory
#  POLYCODE_LIBRARIES - Link these to use Collada DOM
#

# POLYCODE_CORE_INCLUDE_DIR
# LIB_POLYCODE_CORE


# Core/lib/libPolycore.a 
# Core/lib/libPolycore_d.a 

# Core/Dependencies/lib/libfreetype.a 
# Core/Dependencies/lib/libfreetype_d.a 
SET( LIB_FREE_TYPE_NAME "libfreetype" )
SET( LIB_FREE_TYPE_NAME_DEBUG "libfreetype_d" )

# Core/Dependencies/lib/liblibvorbisfile.a 
# Core/Dependencies/lib/liblibvorbisfiled.a 
SET( LIB_VORBIS_FILE_NAME "liblibvorbisfile"
SET( LIB_VORBIS_FILE_NAME_DEBUG "liblibvorbisfiled" )

# Core/Dependencies/lib/liblibvorbis.a 
# Core/Dependencies/lib/liblibvorbisd.a 
SET( LIB_VORBIS_NAME "liblibvorbis" )
SET( LIB_VORBIS_NAME_DEBUG "liblibvorbisd" ) 

# Core/Dependencies/lib/liblibogg.a 
# Core/Dependencies/lib/libliboggd.a 
SET( LIB_OGG_NAME "liblibogg" )
SET( LIB_OGG_NAME_DEBUG "libliboggd" )

# Core/Dependencies/lib/libopenal.so 
# Core/Dependencies/lib/libopenald.so 
SET( LIB_OPENAL_NAME "libopenal" )
SET( LIB_OPENAL_NAME_DEBUG "libopenald" ) 

# Core/Dependencies/lib/libphysfs.a 
# Core/Dependencies/lib/libphysfsd.a 
SET( LIB_PHYS_FS_NAME "libphysfs" )
SET( LIB_PHYS_FS_NAME_DEBUG "libphysfsd" )

# Core/Dependencies/lib/libpng15.a 
# Core/Dependencies/lib/libpng15d.a 
SET( lib_png_name "libpng15" )
SET( lib_png_name_debug "libpng15d" )

# Core/Dependencies/lib/libz.a 
set( LIB_Z_NAME "libz" ) 

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

# ---------------------------------------------------------
# -------------- find policore lib ------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib free type ------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib ogg ------------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib vorbis ---------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib vorbisfile -----------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib open al --------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib phys fs --------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "Polycore"
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "Polycore_d"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------


# ---------------------------------------------------------
# ------------- find lib png ------------------------------

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEPEND_PNG NAME ${LIB_PNG_NAME}
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
MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEPEND_PNG_DEBUG NAME ${LIB_PNG_NAME_DEBUG}
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 
                PATHS ${POLYCODE_SEARCH_PATHS}
              )
MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# ---------------------------------------------------------



IF(POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG)
  SET(POLYCODE_CORE_FOUND TRUE)
ENDIF(POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG)

