/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  wrapClasses.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <cmath>
#include <iostream>
#include "wrapClasses.h"

#include "pathGlobal.h"
#include "heliumScreenObjects.h"
#include "heliumGameGlobal.h"
#include "heliumPreparedScreenButton.h"

namespace P = Polycode;

void AddDice::process() {
    static float pos = 1;
    double x = 3 * std::sin(pos);
    double y = 3 * std::cos(pos);
    pos += 0.25;
    
    P::ScenePrimitive* diceModel = new P::ScenePrimitive(P::ScenePrimitive::TYPE_BOX, 0.5, 0.5, 0.5 );
    diceModel->loadTexture(g_helium_resource_path + "/flame1.png");
    diceModel->setRoll(-45);
    diceModel->setPitch(45);
    diceModel->setPosition(x, 10, y);
    
    LifelessObject* dice = new LifelessObject(diceModel);
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    gm->getSceneWorldPt()->addPhysicsObject(dice, P::PhysicsSceneEntity::SHAPE_BOX, 0.5);
}

void AddBarrel::process() {
}

void AddBoll::process() {
    P::ScenePrimitive* dice 
        = new P::ScenePrimitive(P::ScenePrimitive::TYPE_SPHERE, 3, 16, 16 );
    dice->loadTexture(g_helium_resource_path + "/earth_world_map.png");
    dice->setPosition(0, 10, 0);
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    gm->getSceneWorldPt()->getEngineScenePt()->addPhysicsChild(dice,
P::PhysicsSceneEntity::SHAPE_SPHERE, 0.5, 0.1, 0.1 );
}

void XCameraMove::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    P::Vector3 pos = gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z - 0.25;
    gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void XNegativeCameraMove::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    P::Vector3 pos = gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z + 0.25;
    gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void YCameraMove::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    P::Vector3 pos = gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z - 0.25;
    gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void YNegativeCameraMove::process() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    P::Vector3 pos = gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z + 0.25;
    gm->getSceneWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

using namespace P; // fucking macros !
ProGameObject::ProGameObject( P::Core* _core )
    : HeliumGameCore( _core ) 
{
    CoreServices::getInstance()->getResourceManager()->addArchive(g_helium_resource_path+"/default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
    
    keyboardInput->addEventHandler( P::KEY_1, new AddDice());
    keyboardInput->addEventHandler( P::KEY_2, new AddBoll());
    keyboardInput->addEventHandler( P::KEY_3, new AddBarrel());

    keyboardInput->addEventHandler( P::KEY_d, new YCameraMove());
    keyboardInput->addEventHandler( P::KEY_a, new YNegativeCameraMove());
    keyboardInput->addEventHandler( P::KEY_w, new XCameraMove());
    keyboardInput->addEventHandler( P::KEY_s, new XNegativeCameraMove());
    
    objectWorld.getEngineScenePt()->getDefaultCamera()->setPosition(17,17,17);
	objectWorld.getEngineScenePt()->getDefaultCamera()->lookAt(Vector3(0,0,0));

	ScenePrimitive* ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 16, 16);
	ground->loadTexture(g_helium_resource_path + "/simple_stone_texture.png");
	objectWorld.getEngineScenePt()->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    ScenePrimitive* wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(g_helium_resource_path + "/simple_stone_texture.png");
	wall->setPosition( 0, 2, 8 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(g_helium_resource_path + "/simple_stone_texture.png");
	wall->setPosition( 0, 2, -8 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(g_helium_resource_path + "/simple_stone_texture.png");
	wall->setYaw( 90 );
	wall->setPosition( 8, 2, 0 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(g_helium_resource_path + "/simple_stone_texture.png");
	wall->setYaw( 90 );
	wall->setPosition( -8, 2, 0 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    std::cout << "!\n";
    HeliumExitScreenButton exitBt(this);
    std::cout << "!!\n";
    this->getScreenWorldPt()->addAlifeObject(exitBt.getButton());
    std::cout << "!!!\n";
}

ProGameObject::~ProGameObject(){
}

