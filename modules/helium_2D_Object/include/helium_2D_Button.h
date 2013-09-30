/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_2D_Button.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef  HELIUM__2D__BUTTON_INCLUDED
#define  HELIUM__2D__BUTTON_INCLUDED

#include "Polycode.h"
#include "heliumUserInputHandler.h"
#include "helium_2D_Object.h"

class HeliumButton : public Helium_2D_Object {
public:
    HeliumButton( Polycode::ScreenEntity* _model,
                  KeyHandler*             mouseClickEvent,
                  KeyHandler*             mouseDoubleClickEvent );
    
    virtual ~HeliumButton() {}
    
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

#endif // HELIUM__2D__BUTTON_INCLUDED

