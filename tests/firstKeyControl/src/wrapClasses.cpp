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

namespace P = Polycode;

P::String res_path(HELIUM_RESOURCE_PATH);

void AddDice::process(HeliumGameCore* gm) {
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

void AddBarrel::process(HeliumGameCore* gm) {
//    P::Mesh* mesh = new P::Mesh(P::Mesh::LINE_STRIP_MESH);
//    mesh->createCylinder(1, 0.25, 8);
//    PhysicsObject* bar = new PhysicsObject(new P::SceneMesh(mesh));    
//    gm->getObjectWorldPt()->addDynamic( bar );
}

void AddBoll::process(HeliumGameCore* gm) {
    P::ScenePrimitive* dice 
        = new P::ScenePrimitive(P::ScenePrimitive::TYPE_SPHERE, 1, 5, 5 );
    dice->loadTexture(res_path + "/simple_grey_texture.png");
    dice->setPosition(0, 10, 0);
    gm->getObjectWorldPt()->getEngineScenePt()->addPhysicsChild(dice, P::PhysicsSceneEntity::SHAPE_BOX, 0.5, 0.1, 0.1 );
}

void XCameraMove::process(HeliumGameCore* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z - 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void XNegativeCameraMove::process(HeliumGameCore* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z + 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void YCameraMove::process(HeliumGameCore* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z - 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

void YNegativeCameraMove::process(HeliumGameCore* gm) {
    P::Vector3 pos = gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z + 0.25;
    gm->getObjectWorldPt()->getEngineScenePt()->getDefaultCamera()->setPosition(pos);
}

KeyboardUserInput::KeyboardUserInput(HeliumGameCore* gm)
        : console(new ScreenConsole( 12, 10, 128, 0.25, P::Vector3(0.0,1.0,0.0))),
          gamePt(gm)
{
    handlers[P::KEY_1] = new AddDice();
    handlers[P::KEY_2] = new AddBoll();
    handlers[P::KEY_3] = new AddBarrel();
    handlers[P::KEY_ESCAPE] = new EscapeGame();
    
    handlers[P::KEY_d] = new YCameraMove();
    handlers[P::KEY_a] = new YNegativeCameraMove();
    handlers[P::KEY_w] = new XCameraMove();
    handlers[P::KEY_s] = new XNegativeCameraMove();
}
 
void KeyboardUserInput::handleEvent(P::Event *e) {
    // if(e->getDispatcher() == core->getInput()) {
    switch(e->getEventCode()) {
        case P::InputEvent::EVENT_KEYDOWN:
            this->keyDOWN( (P::InputEvent*)e );
        break;
        
        case P::InputEvent::EVENT_KEYUP:
            this->keyUP( (P::InputEvent*)e );
        break;
    }
}

void KeyboardUserInput::keyUP(P::InputEvent* inputEvent){
    console->add("up: ");
    console->add(P::String::IntToString(inputEvent->keyCode()));
    console->add(" : ");
    console->add(inputEvent->charCode);
    console->newLine();
}

void KeyboardUserInput::keyDOWN(P::InputEvent* inputEvent){
    console->add("down: ");
    console->add(P::String::IntToString(inputEvent->keyCode()));
    console->add(" : ");
    console->add(inputEvent->charCode);
    console->newLine();
    std::map<int, KeyHandler*>::iterator prc = handlers.find(inputEvent->keyCode());
    if ( prc != handlers.end() ) {
        prc->second->process(gamePt);
    }
}

using namespace P; // fucking macros !
ProGameObject::ProGameObject( P::Core* _core )
    : HeliumGameCore( _core ) 
{
    CoreServices::getInstance()->getResourceManager()->addArchive(res_path+"/default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
    
    keysHandler = new KeyboardUserInput(this);

    engineCore->getInput()->addEventListener( keysHandler, 
                                        P::InputEvent::EVENT_KEYDOWN);
  
    engineCore->getInput()->addEventListener( keysHandler,
                                        P::InputEvent::EVENT_KEYUP);
    
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
}

ProGameObject::~ProGameObject(){
}

