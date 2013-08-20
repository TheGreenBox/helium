/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  wrapClasses.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <iostream>
#include "wrapClasses.h"

#include "pathGlobal.h"

namespace P = Polycode;

P::String res_path(HELIUM_RESOURCE_PATH);

void AddDice::process(P::PhysicsScene* scene) {
    P::ScenePrimitive* dice = new P::ScenePrimitive(P::ScenePrimitive::TYPE_BOX, 1.1, 1.1, 1.1 );
    dice->loadTexture(res_path + "/flame1.png");
    dice->setRoll(-45);
    dice->setPitch(45);
    dice->setPosition(0, 10, 0);
    scene->addPhysicsChild(dice, P::PhysicsSceneEntity::SHAPE_BOX, 1.0);
}

KeyboardUserInput::KeyboardUserInput(P::PhysicsScene* _scene)
        : console(new ScreenConsole( 12, 10, 128, 0.25, P::Vector3(0.0,1.0,0.0))),
          scene(_scene)
{
   handlers[P::KEY_a] = new AddDice();
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
        prc->second->process(scene);
    }
}

ProGameobject::ProGameobject( P::PolycodeView* view )
{
    using namespace P; // fucking macros !
    core = new POLYCODE_CORE(view, 640, 480, false, false, 0, 0, 90);

    CoreServices::getInstance()->getResourceManager()->addArchive(res_path+"/default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
	scene = new PhysicsScene();
    
    keysHandler = new KeyboardUserInput(scene);

    core->getInput()->addEventListener( keysHandler, 
                                        P::InputEvent::EVENT_KEYDOWN);
  
    core->getInput()->addEventListener( keysHandler,
                                        P::InputEvent::EVENT_KEYUP);
	std::cout << "85\n";
    
    scene->getDefaultCamera()->setPosition(16,16,16);
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

ProGameobject::~ProGameobject(){
}

int ProGameobject::update() {
    return core->updateAndRender();
}

