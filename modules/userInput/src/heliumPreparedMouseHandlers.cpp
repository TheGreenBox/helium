/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumPreparedMouseHandlers.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include  "heliumPreparedMouseHandlers.h"
#include "heliumGameGlobal.h"

int CameraHorisontalMove::speed = 10;

CameraHorisontalMove::CameraHorisontalMove() {
}

CameraHorisontalMove::~CameraHorisontalMove() {
}

void CameraHorisontalMove::process(Polycode::Vector2 mouse) {
    Number xres = Polycode::CoreServices::getInstance()->getCore()->getXRes();
    Number yres = Polycode::CoreServices::getInstance()->getCore()->getYRes();
    
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    const float BORDER = 0.95;
    if ( mouse.x > xres*BORDER ) {
    //    setSpeed(mouse);
    }
    if ( mouse.x < xres*(1-BORDER) ) {
    //
    }
    if ( mouse.y > xres*BORDER ) {
    //
    }
    if ( mouse.y < xres*(1-BORDER) ) {
    //
    }
}

SceneObjectHorTransfer::SceneObjectHorTransfer(Polycode::SceneEntity* _model) 
    : model (_model) {}

SceneObjectHorTransfer::~SceneObjectHorTransfer() {
}

void SceneObjectHorTransfer::process(Polycode::Vector2 mouse) {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::RayTestResult test = gm->getSceneWorldPt()->rayTest(mouse);
    model->setPosition(test.position);
}

