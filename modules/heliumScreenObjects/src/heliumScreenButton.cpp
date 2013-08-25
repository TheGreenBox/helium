/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/heliumScreenObjects/src/heliumScreenButton.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include <Polycode.h>
#include "heliumScreenButton.h"
#include "keyboardHandler.h"

ScreenButton::ScreenButton( Polycode::ScreenEntity* _model,
                            KeyHandler* _mouseClickEvent,
                            KeyHandler* _mouseDoubleClickEvent )
    :   AlifeScreenObject(_model),
        mouseClickEvent(_mouseClickEvent),
        mouseDoubleClickEvent(_mouseDoubleClickEvent) {}

void ScreenButton::lifeStep() {
}
    
void ScreenButton::mouseCursor() {
    cursorAnimation();
}

void ScreenButton::mouseClick() {
    clickAnimation();
    if ( mouseClickEvent != NULL ) {
//        mouseClickEvent->process();
    }
}

void ScreenButton::mouseDoubleClick() {
    clickAnimation();
    if ( mouseDoubleClickEvent != NULL ) {
//        mouseDoubleClickEvent->process();
    }
}

void ScreenButton::cursorAnimation() {
}

void ScreenButton::clickAnimation() {
}

