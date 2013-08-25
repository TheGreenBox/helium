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
#include "heliumScreenButton.h"

namespace P = Polycode;

P::String res_path(HELIUM_RESOURCE_PATH);

void AddDice::process(HeliumGameCoreObjects* gm) {
    static float pos = 1;
    double x = 3 * std::sin(pos);
    double y = 3 * std::cos(pos);
    pos += 0.25;
    
    P::ScenePrimitive* diceModel = new P::ScenePrimitive(P::ScenePrimitive::TYPE_BOX, 0.5, 0.5, 0.5 );
    diceModel->loadTexture(res_path + "/flame1.png");
    diceModel->setRoll(-45);
    diceModel->setPitch(45);
    diceModel->setPosition(x, 10, y);
    
    LifelessObject* dice = new LifelessObject(diceModel);
    gm->getObjectWorldPt()->addPhysicsObject(dice, P::PhysicsSceneEntity::SHAPE_BOX, 0.5);
}

void AddBarrel::process(HeliumGameCoreObjects* gm) {
}

void AddBoll::process(HeliumGameCoreObjects* gm) {
    P::ScenePrimitive* dice 
        = new P::ScenePrimitive(P::ScenePrimitive::TYPE_SPHERE, 2, 8, 8 );
    dice->loadTexture(res_path + "/earth_world_map.png");
    dice->setPosition(0, 10, 0);
    gm->getObjectWorldPt()->getEngineScenePt()->addPhysicsChild(dice,
P::PhysicsSceneEntity::SHAPE_SPHERE, 0.5, 0.1, 0.1 );
}

void XCameraMove::process(HeliumGameCoreObjects* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z - 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void XNegativeCameraMove::process(HeliumGameCoreObjects* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z + 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void YCameraMove::process(HeliumGameCoreObjects* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z - 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void YNegativeCameraMove::process(HeliumGameCoreObjects* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z + 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

using namespace P; // fucking macros !
ProGameObject::ProGameObject( P::Core* _core )
    : HeliumGameCore( _core ) 
{
    CoreServices::getInstance()->getResourceManager()->addArchive(res_path+"/default.pak");
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
	ground->loadTexture(res_path + "/simple_stone_texture.png");
	objectWorld.getEngineScenePt()->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    ScenePrimitive* wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setPosition( 0, 2, 8 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setPosition( 0, 2, -8 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setYaw( 90 );
	wall->setPosition( 8, 2, 0 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 4);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setYaw( 90 );
	wall->setPosition( -8, 2, 0 );
	objectWorld.getEngineScenePt()->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

    Polycode::ScreenShape* button = 
            new Polycode::ScreenShape( Polycode::ScreenShape::SHAPE_RECT, 50, 50);
    button->setPosition( this->getEngineCorePt()->getXRes()-25,
                         this->getEngineCorePt()->getYRes()-25);
    button->loadTexture( res_path + "/exit_button.png" );
    this->getFlatWorldPt()->addAlifeObject(new ScreenButton( button, 
                                                                new EscapeGame, 
                                                                NULL ) );
}

ProGameObject::~ProGameObject(){
}

