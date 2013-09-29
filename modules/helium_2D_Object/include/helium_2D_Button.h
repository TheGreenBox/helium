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
#include "heliumUserInputHandler.h"
#include "heliumScreenObjects.h"

class ScreenButton : public ScreenObject {
public:
    ScreenButton( Polycode::ScreenEntity* _model,
                  KeyHandler*             mouseClickEvent,
                  KeyHandler*             mouseDoubleClickEvent );
    
    virtual ~ScreenButton() {}
    
    void lifeStep();
    
    void mouseCursor();
    void mouseClick(bool upDown);
    void mouseDoubleClick();

private:
    void cursorAnimation();
    void clickAnimation(bool upDown);
    
    KeyHandler* mouseClickEvent;
    KeyHandler* mouseDoubleClickEvent;
};

#endif // HELIUM_SCREEN_BUTTON_INCLUDED

