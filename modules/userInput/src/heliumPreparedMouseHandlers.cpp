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

