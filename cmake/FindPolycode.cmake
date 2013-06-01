MESSAGE(STATUS "start polycode finder module")

SET ( POLYCODE_SEARCH_PATHS
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/lib
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Core/include
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Modules/lib
	  ${CMAKE_HOME_DIRECTORY}/../polycode/Polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Modules/include )

MESSAGE(STATUS "Let,s find polycode in this directories :")
MESSAGE(STATUS ${POLYCODE_SEARCH_PATHS})

# - Try to find Polycode
# Once done this will define
#
#  POLYCODE_FOUND - system has Polycode
#  POLYCODE_INCLUDE_DIR - the POLYCODE include directory
#  POLYCODE_LIBRARIES - Link these to use Collada DOM
#

# POLYCODE_CORE_INCLUDE_DIR
# LIB_POLYCODE_CORE

# list of polycode modules

# POLYCODE_MODULES_INCLUDE_DIR
#
# LIB_POLYCODE_2D_PHYSICS
# LIB_POLYCODE_2D_PHYSICS_D
# LIB_POLYCODE_3D_PHYSICS
# LIB_POLYCODE_3D_PHYSICS_D
# LIB_POLYCODE_TUIO
# LIB_POLYCODE_TUIO_D
# LIB_POLYCODE_UI
# LIB_POLYCODE_UI_D

#libPolycore.a
#libPolycore_d.a

#libPolycode2DPhysics.a
#libPolycode2DPhysics_d.a
#libPolycode3DPhysics.a
#libPolycode3DPhysics_d.a
#libPolycodeTUIO.a
#libPolycodeTUIO_d.a
#libPolycodeUI.a
#libPolycodeUI_d.a

FIND_PATH ( POLYCODE_CORE_INCLUDE_DIR NAMES PolyCore.h
	        HINTS
	        NO_DEFAULT_PATH
    	    NO_CMAKE_ENVIRONMENT_PATH
	        NO_CMAKE_SYSTEM_PATH
	        NO_SYSTEM_ENVIRONMENT_PATH
	        NO_CMAKE_PATH
	        CMAKE_FIND_FRAMEWORK NEVER
	        PATHS ${POLYCODE_SEARCH_PATHS} )

MESSAGE(STATUS ${POLYCODE_CORE_INCLUDE_DIR})

FIND_LIBRARY  ( LIB_POLYCODE_CORE NAME "libPolycore.a"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 win32/Dynamic_Release "Win32/${MSVC_YEAR_NAME}/x64/Release" "Win32/${MSVC_YEAR_NAME}/Win32/Release"
                PATHS ${POLYCODE_SEARCH_PATHS} )

MESSAGE(STATUS ${LIB_POLYCODE_CORE})

FIND_LIBRARY  ( LIB_POLYCODE_CORE_DEBUG NAME "libPolycore_d.a"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 win32/Dynamic_Release "Win32/${MSVC_YEAR_NAME}/x64/Release" "Win32/${MSVC_YEAR_NAME}/Win32/Release"
                PATHS ${POLYCODE_SEARCH_PATHS} )

MESSAGE(STATUS ${LIB_POLYCODE_CORE_DEBUG})

# found polycode lib modules
FIND_PATH ( POLYCODE_MODULES_INCLUDE_DIR NAMES Polycode3DPhysics.h
	        HINTS
	        NO_DEFAULT_PATH
    	    NO_CMAKE_ENVIRONMENT_PATH
	        NO_CMAKE_SYSTEM_PATH
	        NO_SYSTEM_ENVIRONMENT_PATH
	        NO_CMAKE_PATH
	        CMAKE_FIND_FRAMEWORK NEVER
	        PATHS ${POLYCODE_SEARCH_PATHS} )

MESSAGE(STATUS ${POLYCODE_MODULES_INCLUDE_DIR})

# founding Polycode 3D Physics module
FIND_LIBRARY  ( LIB_POLYCODE_3D_PHYSICS NAME "libPolycode3DPhysics.a"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 win32/Dynamic_Release "Win32/${MSVC_YEAR_NAME}/x64/Release" "Win32/${MSVC_YEAR_NAME}/Win32/Release"
                PATHS ${POLYCODE_SEARCH_PATHS} )

MESSAGE(STATUS ${LIB_POLYCODE_3D_PHYSICS})

FIND_LIBRARY  ( LIB_POLYCODE_3D_PHYSICS_DEBUG NAME "libPolycode3DPhysics_d.a"
	            HINTS
                NO_DEFAULT_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_CMAKE_SYSTEM_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PATH
                CMAKE_FIND_FRAMEWORK NEVER
                $ENV{POLYCODEDIR}
                $ENV{POLYCODE_PATH}
                PATH_SUFFIXES lib lib64 win32/Dynamic_Release "Win32/${MSVC_YEAR_NAME}/x64/Release" "Win32/${MSVC_YEAR_NAME}/Win32/Release"
                PATHS ${POLYCODE_SEARCH_PATHS} )

MESSAGE(STATUS ${LIB_POLYCODE_3D_PHYSICS_DEBUG})

IF(POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG)
  SET(POLYCODE_CORE_FOUND TRUE)
ENDIF(POLYCODE_CORE_INCLUDE_DIR AND LIB_POLYCODE_CORE AND LIB_POLYCODE_CORE_DEBUG)

# show the POLYCODE_INCLUDE_DIR and POLYCODE_LIBRARIES variables only in the advanced view
IF(POLYCODE_CORE_FOUND)
  MESSAGE ("POLYCODE found (${POLYCODE_CORE_INCLUDE_DIR}))")
ENDIF(POLYCODE_CORE_FOUND)

