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

void EscapeGame::process(HeliumGameCore* gm) {
    gm->getEngineCorePt()->Shutdown();
}

void PauseGame::process(HeliumGameCore* gm) {
    if ( gm->getObjectWorldPt()->getEngineScenePt()->isEnabled() ) {
        gm->getObjectWorldPt()->getEngineScenePt()->setEnabled(false);
    }
    else {    
        gm->getObjectWorldPt()->getEngineScenePt()->setEnabled(true);
    }
}

void SetVirtualGame::process(HeliumGameCore* gm) {
    if ( gm->getObjectWorldPt()->getEngineScenePt()->isVirtual() ) {
        gm->getObjectWorldPt()->getEngineScenePt()->setVirtual(false);
    }
    else {    
        gm->getObjectWorldPt()->getEngineScenePt()->setVirtual(true);
    }
}
