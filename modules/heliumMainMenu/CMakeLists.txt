CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

MESSAGE(STATUS "HELIUM MODULE: << heliumMainMenu >>")

PROJECT( heliumMainMenu )

INCLUDE( heliumIncludes )

SET ( heliumMainMenu_SRCS
        ${HELIUM_MODULES_DIR}/heliumMainMenu/src/heliumMainMenu.cpp
    )

SET ( heliumMainMenu_HDRS
        ${HELIUM_MODULES_DIR}/heliumMainMenu/include/heliumMainMenu.h
    ) 

ADD_LIBRARY ( heliumMainMenu STATIC
                    ${heliumMainMenu_SRCS}
                    ${heliumMainMenu_HDRS} 
               )

TARGET_LINK_LIBRARIES ( heliumMainMenu
                            ${LIB_POLYCODE}
                      )
