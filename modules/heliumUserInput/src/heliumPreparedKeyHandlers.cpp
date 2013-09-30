/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name:  keyboardHandler.cpp
 * Description:
 * Author:  AKindyakov
 * ========================================================
 */

#include "heliumPreparedKeyHandlers.h"

#include "helium_2D_PreparedButton.h"
#include "heliumGameGlobal.h"

void EscapeGame::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    gm->getEngineCorePt()->Shutdown();
}

PauseGame::PauseGame() {}

Helium_2D_World::ObjectId PauseGame::button = 0;

PauseGame::~PauseGame() {}

void PauseGame::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    if ( gm->getSceneWorldPt()->getPause() ) {
        gm->getSceneWorldPt()->setPause(false);
        HeliumPause_2D_Button container(gm);
        button = gm->getScreenWorldPt()->addObject( &container );
    }
    else {
        gm->getSceneWorldPt()->setPause(true);
        gm->getScreenWorldPt()->signOutObject( button );
    }
}

void SetVirtualGame::process() {
//    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
//    if ( gm->getSceneWorldPt()->getEngineScenePt()->isVirtual() ) {
//        gm->getSceneWorldPt()->getEngineScenePt()->setVirtual(false);
//    }
//    else {
//        gm->getSceneWorldPt()->getEngineScenePt()->setVirtual(true);
//    }
}
