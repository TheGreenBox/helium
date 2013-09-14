SET ( POLYCODE_MODULES_DIR ${CMAKE_SOURCE_DIR}/../polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Modules )
SET ( POLYCODE_MODULES_DIR_BIG ${CMAKE_SOURCE_DIR}/../Polycode/Release/${CMAKE_SYSTEM_NAME}/Framework/Modules )
SET ( POLYCODE_MODULES_DIR_INT ${CMAKE_SOURCE_DIR}/thirdparty/polycode/polycode_src/Release/${CMAKE_SYSTEM_NAME}/Framework/Modules )

MESSAGE( STATUS ${POLYCODE_FRAMEWORK_DIR_INT})

SET ( POLYCODE_SEARCH_PATHS
      ${POLYCODE_MODULES_DIR}/lib
      ${POLYCODE_MODULES_DIR_BIG}/lib
      ${POLYCODE_MODULES_DIR_INT}/lib
    
      ${POLYCODE_MODULES_DIR}/Dependencies/lib
      ${POLYCODE_MODULES_DIR_BIG}/Dependencies/lib
      ${POLYCODE_MODULES_DIR_INT}/Dependencies/lib
    
      ${POLYCODE_MODULES_DIR}/include 
      ${POLYCODE_MODULES_DIR_BIG}/include 
      ${POLYCODE_MODULES_DIR_INT}/include 
    
      ${POLYCODE_MODULES_DIR}/Dependencies/include/Box2D 
      ${POLYCODE_MODULES_DIR_BIG}/Dependencies/include/Box2D 
      ${POLYCODE_MODULES_DIR_INT}/Dependencies/include/Box2D 
    
      ${POLYCODE_MODULES_DIR}/Dependencies/include/bullet
      ${POLYCODE_MODULES_DIR_BIG}/Dependencies/include/bullet
      ${POLYCODE_MODULES_DIR_INT}/Dependencies/include/bullet
    )

SET ( POLYCODE_MODULES_LIB_NAMES
      "Polycode2DPhysics"
      "Polycode3DPhysics"
      "PolycodeTUIO"
      "PolycodeUI"

      "Box2D"
      "BulletDynamics"
      "BulletCollision"
      "LinearMath"
    )

SET ( POLYCODE_MODULES_LIB_DEBUG_NAMES
      "Polycode2DPhysics_d"
      "Polycode3DPhysics_d"
      "PolycodeTUIO_d"
      "PolycodeUI_d"

      "Box2D_d"
      "BulletDynamics_d"
      "BulletCollision_d"
      "LinearMath_d"
    )


#../../Modules/include 
#../../Modules/Dependencies/include 
#../../Modules/Dependencies/include/bullet

FIND_PATH ( POLYCODE_MODULES_COMMON_INCLUDE_DIR NAMES Polycode3DPhysics.h
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )
#MESSAGE(STATUS ${POLYCODE_MODULES_COMMON_INCLUDE_DIR})

FIND_PATH ( POLYCODE_MODULES_DEPEND_INCLUDE_DIR NAMES Box2D.h
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )
#MESSAGE(STATUS ${POLYCODE_MODULES_DEPEND_INCLUDE_DIR})

FIND_PATH ( POLYCODE_MODULES_DEPEND_BULLET_INCLUDE_DIR NAMES btBulletCollisionCommon.h
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${POLYCODE_SEARCH_PATHS} 
          )
#MESSAGE(STATUS ${POLYCODE_MODULES_DEPEND_BULLET_INCLUDE_DIR})

SET ( POLYCODE_MODULES_INCLUDE_DIR
      ${POLYCODE_MODULES_COMMON_INCLUDE_DIR}
      ${POLYCODE_MODULES_DEPEND_INCLUDE_DIR}/../
      ${POLYCODE_MODULES_DEPEND_BULLET_INCLUDE_DIR}
    )

FOREACH( LIBRARY ${POLYCODE_MODULES_LIB_NAMES} )
    
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
    
    set ( LIB_POLYCODE_MODULES 
          ${LIB_POLYCODE_MODULES}
          ${LIB_${LIBRARY}}
        )

ENDFOREACH( LIBRARY ${POLYCODE_MODULES_LIB_NAMES} )


FOREACH( LIBRARY ${POLYCODE_MODULES_LIB_DEBUG_NAMES} )
    
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
    
    set ( LIB_POLYCODE_MODULES_DEBUG 
          ${LIB_POLYCODE_MODULES_DEBUG}
          ${LIB_${LIBRARY}}
        )

ENDFOREACH( LIBRARY ${POLYCODE_MODULES_LIB_DEBUG_NAMES} )


IF ( POLYCODE_MODULES_INCLUDE_DIR AND LIB_POLYCODE_MODULES AND LIB_POLYCODE_MODULES_DEBUG )
    if( NOT POLYCODE_MODULES_FOUND )
        SET(POLYCODE_MODULES_FOUND TRUE)
        MESSAGE(STATUS "POLYCODE MODULES LIBS WERE FOUND")
        
        MESSAGE(STATUS "Release:")
        FOREACH( LIBRARY ${LIB_POLYCODE_MODULES} )
            MESSAGE(STATUS ${LIBRARY})
        ENDFOREACH()

        MESSAGE(STATUS "Debug:")
        FOREACH( LIBRARY ${LIB_POLYCODE_MODULES_DEBUG} )
            MESSAGE(STATUS ${LIBRARY})
        ENDFOREACH()
    ENDIF( NOT POLYCODE_MODULES_FOUND )
ENDIF()

