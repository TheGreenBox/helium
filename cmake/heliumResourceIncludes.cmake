MESSAGE( STATUS "HELIUM INSTAL RECOURCES:")

SET ( HELIUM_RESOURCE_SEARCH_PATHS
      ~/Dropbox/game_project/helium_resource/art
      ~/Dropbox/game_project/Helium_resource/art
      ~/Dropbox/game_project/HeliumResource/art
      ${CMAKE_HOME_DIRECTORY}/../helium_resource
      ${CMAKE_HOME_DIRECTORY}/../Helium_resource
      ${CMAKE_HOME_DIRECTORY}/../HeliumResource
    )

FIND_PATH ( HELIUM_RESOURCE_SRC_DIR NAME helium_resource.txt 
            HINTS
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_SYSTEM_PATH
            NO_SYSTEM_ENVIRONMENT_PATH
            NO_CMAKE_PATH
            CMAKE_FIND_FRAMEWORK NEVER
            PATHS ${HELIUM_RESOURCE_SEARCH_PATHS} 
          )

MESSAGE( STATUS "From: "${HELIUM_RESOURCE_SRC_DIR} )

