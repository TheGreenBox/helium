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
#include "heliumGameCoreObjects.h"

struct HeliumPauseScreenButton {
    HeliumPauseScreenButton (HeliumGameCoreObjects* );
    virtual ~HeliumPauseScreenButton ();

    ScreenButton* getButton() { return button; }
    ScreenButton* button;
};

struct HeliumExitScreenButton {
    HeliumExitScreenButton(HeliumGameCoreObjects* );
    virtual ~HeliumExitScreenButton();

    ScreenButton* getButton() { return button; }
    ScreenButton* button;
};

#endif // HELIUM_PREPARED_SCREEN_BUTTON_INCLUDED

