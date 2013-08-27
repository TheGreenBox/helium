/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  src/keyboardHandler.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include "keyboardHandler.h"
#include "heliumPreparedScreenButton.h"

#include <iostream>

void EscapeGame::process(HeliumGameCoreObjects* gm) {
    gm->getEngineCorePt()->Shutdown();
}

PauseGame::PauseGame() {
    PauseGame::pauseButton = NULL;
}

ScreenButton* PauseGame::pauseButton;

PauseGame::~PauseGame() {
    if ( pauseButton != NULL ) {
        delete pauseButton->getModel();
        delete pauseButton;
    }
}

void PauseGame::process(HeliumGameCoreObjects* gm) {
    if ( gm->getSceneWorldPt()->getPause() ) {
        gm->getSceneWorldPt()->setPause(false);
        HeliumPauseScreenButton pauseButtonConstrctor(gm);
        pauseButton = pauseButtonConstrctor.getButton();
        gm->getScreenWorldPt()->addAlifeObject(pauseButton);
    }
    else {
        gm->getSceneWorldPt()->setPause(true);
        gm->getScreenWorldPt()->signOutObject( pauseButton );
        delete pauseButton->getModel();
        delete pauseButton;
        pauseButton = NULL;
    }
}

void SetVirtualGame::process(HeliumGameCoreObjects* gm) {
    if ( gm->getSceneWorldPt()->getEngineScenePt()->isVirtual() ) {
        gm->getSceneWorldPt()->getEngineScenePt()->setVirtual(false);
    }
    else {    
        gm->getSceneWorldPt()->getEngineScenePt()->setVirtual(true);
    }
}
