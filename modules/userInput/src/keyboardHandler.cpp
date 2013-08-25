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

void EscapeGame::process(HeliumGameCoreObjects* gm) {
    gm->getEngineCorePt()->Shutdown();
}

void PauseGame::process(HeliumGameCoreObjects* gm) {
    if ( gm->getSceneWorldPt()->getEngineScenePt()->isEnabled() ) {
        gm->getSceneWorldPt()->getEngineScenePt()->setEnabled(false);
    }
    else {    
        gm->getSceneWorldPt()->getEngineScenePt()->setEnabled(true);
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
