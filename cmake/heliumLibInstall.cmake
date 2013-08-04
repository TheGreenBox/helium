MESSAGE( STATUS "HELIUM LIBRARY INSTAL:")

IF ( WIN32 )

    FIND_PACKAGE( PolyCore REQUIRED)
    
    SET ( LIB_OPENAL_POSIBLE_NAMES 
            "OpenAL32.dll"
            "OpenAL32d.dll"
        )

    FOREACH( LIB_NAME ${LIB_OPENAL_POSIBLE_NAMES} )
        FIND_FILE( FINDED_${LIB_NAME}
                     NAME  ${LIB_NAME}
                     PATHS ${POLYCODE_SEARCH_PATHS}
                     NO_DEFAULT_PATH
                     NO_CMAKE_ENVIRONMENT_PATH
                     NO_CMAKE_PATH
                     NO_SYSTEM_ENVIRONMENT_PATH
                     NO_CMAKE_SYSTEM_PATH
                     NO_CMAKE_FIND_ROOT_PATH
                )
        IF( FINDED_${LIB_NAME} )   
            MESSAGE (STATUS ${LIB_NAME} " was found" )
            SET ( LIB_OPENAL_FILES
                    ${LIB_OPENAL_FILES}
                    FINDED_${LIB_NAME}
                )
        ENDIF( FINDED_${LIB_NAME} )
    ENDFOREACH( LIB_NAME ${LIB_OPENAL_POSIBLE_NAMES} )

    INSTALL ( FILES ${LIB_OPENAL_FILES}
                DESTINATION  ${OUTCOME_PATH} )

ENDIF ( WIN32 )

