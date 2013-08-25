/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/heliumScreenObjects/include/heliumScreenButton.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_SCREEN_BUTTON_INCLUDED
#define  HELIUM_SCREEN_BUTTON_INCLUDED

#include <Polycode.h>
#include "heliumUserInput.h"

class ScreenButton : public AlifeScreenObject {
public:
    ScreenButton( Polycode::ScreenEntity* model,
                  KeyHandler*             mouseClickEvent,
                  KeyHandler*             mouseDoubleClickEvent );
    virtual ~ScreenButton() {}
    
    void lifeStep();
    
    void mouseCursor();
    void mouseClick();
    void mouseDoubleClick();

private:
    void cursorAnimation();
    void clickAnimation();
    
    Polycode::ScreenEntity* model;   
    
    KeyHandler* mouseClickEvent;
    KeyHandler* mouseDoubleClickEvent;
};

#endif // HELIUM_SCREEN_BUTTON_INCLUDED

