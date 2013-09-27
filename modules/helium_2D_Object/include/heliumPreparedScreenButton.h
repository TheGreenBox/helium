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

#include <Polycode.h>
#include "heliumScreenButton.h"
#include "heliumGameCore.h"

namespace P = Polycode;

struct HeliumPauseScreenButton : public PackagedScreenObject {
    HeliumPauseScreenButton ( HeliumGameCore* );
    virtual ~HeliumPauseScreenButton ();
};

struct HeliumExitScreenButton : public PackagedScreenObject {
    HeliumExitScreenButton ( HeliumGameCore* );
    virtual ~HeliumExitScreenButton();
};

struct HeliumTextScreenButton : public PackagedScreenObject {
    HeliumTextScreenButton ( HeliumGameCore*, P::String textValue, KeyHandler* buttonHandler, int b_x_size, int b_y_size, int x_pos, int y_pos, P::String font, int t_size);
    virtual ~HeliumTextScreenButton();
};


#endif // HELIUM_PREPARED_SCREEN_BUTTON_INCLUDED

