/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/heliumScreenObjects/src/heliumScreenButton.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#include <iostream>
#include <Polycode.h>
#include "heliumScreenButton.h"
#include "heliumUserInputHandler.h"

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

void ScreenButton::mouseClick(bool upDown) {
    clickAnimation(upDown);
    if ( upDown && mouseClickEvent != NULL ) {
        mouseClickEvent->process();
    }
}

void ScreenButton::mouseDoubleClick() {
    if ( mouseDoubleClickEvent != NULL ) {
    //    mouseDoubleClickEvent->process();
    }
}

void ScreenButton::cursorAnimation() {
}

void ScreenButton::clickAnimation(bool upDown) {
    if ( upDown ) {
        this->getModel()->setColor(1.0, 1.0, 1.0, 1.0);
    }
    else {
        this->getModel()->setColor(1.0, 0.2, 0.0, 1.0);
    }
}

