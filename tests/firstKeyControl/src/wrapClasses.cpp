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

void AddDice::process(ProGameObject* gm) {
    static float pos = 1;
    double x = 3 * std::sin(pos);
    double y = 3 * std::cos(pos);
    pos += 0.25;
    P::ScenePrimitive* dice = new P::ScenePrimitive(P::ScenePrimitive::TYPE_BOX, 0.5, 0.5, 0.5 );
    dice->loadTexture(res_path + "/flame1.png");
    dice->setRoll(-45);
    dice->setPitch(45);
    dice->setPosition(x, 10, y);
    gm->getScenePt()->addPhysicsChild(dice, P::PhysicsSceneEntity::SHAPE_BOX, 0.5);
}

void AddBoll::process(ProGameObject* gm) {
    P::ScenePrimitive* dice 
        = new P::ScenePrimitive(P::ScenePrimitive::TYPE_SPHERE, 0.5, 10, 10 );
    dice->loadTexture(res_path + "/flame1.png");
    dice->setPosition(0, 10, 0);
    gm->getScenePt()->addPhysicsChild(dice, P::PhysicsSceneEntity::SHAPE_SPHERE, 0.5, 0.1, 100 );
}

void XCameraMove::process(ProGameObject* gm) {
    P::Vector3 pos = gm->getScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z - 0.25;
    gm->getScenePt()->getDefaultCamera()->setPosition(pos);
}

void XNegativeCameraMove::process(ProGameObject* gm) {
    P::Vector3 pos = gm->getScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z + 0.25;
    gm->getScenePt()->getDefaultCamera()->setPosition(pos);
}

void YCameraMove::process(ProGameObject* gm) {
    P::Vector3 pos = gm->getScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x + 0.25;
    pos.z = pos.z - 0.25;
    gm->getScenePt()->getDefaultCamera()->setPosition(pos);
}

void YNegativeCameraMove::process(ProGameObject* gm) {
    P::Vector3 pos = gm->getScenePt()->getDefaultCamera()->getPosition();
    pos.x = pos.x - 0.25;
    pos.z = pos.z + 0.25;
    gm->getScenePt()->getDefaultCamera()->setPosition(pos);
}

void EscapeGame::process(ProGameObject* gm) {
    gm->getCorePt()->Shutdown();
}

KeyboardUserInput::KeyboardUserInput(ProGameObject* gm)
        : console(new ScreenConsole( 12, 10, 128, 0.25, P::Vector3(0.0,1.0,0.0))),
          gamePt(gm)
{
    handlers[P::KEY_1] = new AddDice();
    handlers[P::KEY_2] = new AddBoll();
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
ProGameObject::ProGameObject( P::PolycodeView* view )
    : core(new POLYCODE_CORE(view, 640, 480, false, false, 0, 0, 90)),
      scene(new PhysicsScene()),
      world(scene)
{
    CoreServices::getInstance()->getResourceManager()->addArchive(res_path+"/default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
    
    keysHandler = new KeyboardUserInput(this);

    core->getInput()->addEventListener( keysHandler, 
                                        P::InputEvent::EVENT_KEYDOWN);
  
    core->getInput()->addEventListener( keysHandler,
                                        P::InputEvent::EVENT_KEYUP);
    
    scene->getDefaultCamera()->setPosition(17,17,17);
	scene->getDefaultCamera()->lookAt(Vector3(0,0,0));

	ScenePrimitive* ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 16, 16);
	ground->loadTexture(res_path + "/simple_stone_texture.png");
	scene->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    ScenePrimitive* wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 2);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setPosition( 0, 1, 8 );
	scene->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 2);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setPosition( 0, 1, -8 );
	scene->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 2);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setYaw( 90 );
	wall->setPosition( 8, 1, 0 );
	scene->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);

    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 2);
	wall->loadTexture(res_path + "/simple_stone_texture.png");
	wall->setYaw( 90 );
	wall->setPosition( -8, 1, 0 );
	scene->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
}

ProGameObject::~ProGameObject(){
}

int ProGameObject::update() {
    return core->updateAndRender();
}

