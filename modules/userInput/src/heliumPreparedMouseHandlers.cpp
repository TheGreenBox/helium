/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumPreparedMouseHandlers.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#include <iostream>
#include "heliumPreparedMouseHandlers.h"
#include "heliumGameGlobal.h"

float CameraHorisontalMove::speed = 0.05;

CameraHorisontalMove::CameraHorisontalMove() {
}

CameraHorisontalMove::~CameraHorisontalMove() {
}

void CameraHorisontalMove::process(Polycode::Vector2 mouse) {
    Number xres = Polycode::CoreServices::getInstance()->getCore()->getXRes();
    Number yres = Polycode::CoreServices::getInstance()->getCore()->getYRes();
    
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    const float BORDER = 20;
    if ( mouse.x > xres-BORDER || mouse.x < BORDER 
         || mouse.y > yres-BORDER || mouse.y < BORDER )
    {
        Polycode::Vector2 mv(mouse.x-xres/2, mouse.y-yres/2);
        mv.Normalize();
        mv = mv*speed;
        HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
        gm->getSceneWorldPt()->setCameraMovingDirection(mv);
    }
    else
    {
        gm->getSceneWorldPt()->setCameraMovingDirection(Polycode::Vector2(0,0));
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

