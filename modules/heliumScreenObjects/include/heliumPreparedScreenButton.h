/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumPreparedScreenButton.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_PREPARED_SCREEN_BUTTON_INCLUDED
#define  HELIUM_PREPARED_SCREEN_BUTTON_INCLUDED

#include "heliumScreenButton.h"
#include "heliumGameCore.h"

struct HeliumPauseScreenButton : public PackagedScreenObject {
    HeliumPauseScreenButton ( HeliumGameCore* );
    virtual ~HeliumPauseScreenButton ();
};

struct HeliumExitScreenButton : public PackagedScreenObject {
    HeliumExitScreenButton ( HeliumGameCore* );
    virtual ~HeliumExitScreenButton();
};

#endif // HELIUM_PREPARED_SCREEN_BUTTON_INCLUDED

