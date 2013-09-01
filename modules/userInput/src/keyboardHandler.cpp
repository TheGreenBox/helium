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
#include "heliumGameGlobal.h"

#include <iostream>

void EscapeGame::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
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

void PauseGame::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
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

void SetVirtualGame::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    if ( gm->getSceneWorldPt()->getEngineScenePt()->isVirtual() ) {
        gm->getSceneWorldPt()->getEngineScenePt()->setVirtual(false);
    }
    else {    
        gm->getSceneWorldPt()->getEngineScenePt()->setVirtual(true);
    }
}
