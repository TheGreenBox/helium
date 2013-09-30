/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_2D_Button.cpp 
 * Description:
 * Author:       AKindyakov 
 * =======================================================
 */
#include <iostream>

#include "Polycode.h"

#include "helium_2D_Button.h"
#include "heliumUserInputHandler.h"

HeliumButton::HeliumButton( Polycode::ScreenEntity* _model,
                            KeyHandler* _mouseClickEvent,
                            KeyHandler* _mouseDoubleClickEvent )
    :   Helium_2D_Object(_model),
        mouseClickEvent(_mouseClickEvent),
        mouseDoubleClickEvent(_mouseDoubleClickEvent) {}

void HeliumButton::lifeStep() {
}
    
void HeliumButton::mouseCursor() {
    cursorAnimation();
}

void HeliumButton::mouseClick(bool upDown) {
    clickAnimation(upDown);
    if ( upDown && mouseClickEvent != NULL ) {
        mouseClickEvent->process();
    }
}

void HeliumButton::mouseDoubleClick() {
    if ( mouseDoubleClickEvent != NULL ) {
        mouseDoubleClickEvent->process();
    }
}

void HeliumButton::cursorAnimation() {
}

void HeliumButton::clickAnimation(bool upDown) {
    if ( upDown ) {
        this->getModel()->setColor(1.0, 1.0, 1.0, 1.0);
    }
    else {
        this->getModel()->setColor(1.0, 0.2, 0.0, 1.0);
    }
}

