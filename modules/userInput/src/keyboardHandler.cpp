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

PauseGame::PauseGame() {
    //Polycode::ScreenShape* button = 
    //        new Polycode::ScreenShape( Polycode::ScreenShape::SHAPE_RECT, 50, 50);
    //button->setPosition( this->getEngineCorePt()->getXRes()/2,
    //                     this->getEngineCorePt()->getYRes()/2);
    //button->loadTexture( res_path + "/exit_button.png" );
    //pauseButton()
}

PauseGame::~PauseGame() {
}

void PauseGame::process(HeliumGameCoreObjects* gm) {
    if ( gm->getSceneWorldPt()->getPause() ) {
        gm->getSceneWorldPt()->setPause(false);
        //gm->getScreenWorldPt();
    }
    else {
        gm->getSceneWorldPt()->setPause(true);
        //pauseButton = 
        //gm->getScreenWorldPt();
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
