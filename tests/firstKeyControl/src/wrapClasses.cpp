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

KeyboardUserInput::KeyboardUserInput( ScreenConsole* cons )
        : console(cons)
{}
 
void KeyboardUserInput::handleEvent(Polycode::Event *e) {
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
}

ProGameobject::ProGameobject( P::PolycodeView* view )
{
    using namespace P; // fucking macros !
    core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);

    P::String res_path(HELIUM_RESOURCE_PATH);
    CoreServices::getInstance()->getResourceManager()->addArchive(res_path+"/default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
	
    console = new ScreenConsole( 12, 10, 128, 0.25, P::Vector3(0.,1.,0.) );
    keysHandler = new KeyboardUserInput(console);
    core->getInput()->addEventListener( keysHandler, 
                                P::InputEvent::EVENT_KEYDOWN);
  
    core->getInput()->addEventListener( keysHandler,
                                P::InputEvent::EVENT_KEYUP);
	
	scene = new PhysicsScene();
    
    scene->getDefaultCamera()->setPosition(16,16,16);
	scene->getDefaultCamera()->lookAt(Vector3(0,0,0));

	ScenePrimitive* ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 16, 16);
	ground->loadTexture(res_path + "/simple_grey_texture.png");
	scene->addPhysicsChild(ground, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    ScenePrimitive* wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 2);
	wall->loadTexture(res_path + "/simple_grey_texture.png");
	wall->setPosition( 0, 1, 8 );
	scene->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
    
    wall = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 16, 2);
	wall->loadTexture(res_path + "/simple_grey_texture.png");
	wall->setPosition( 0, 1, -8 );
	scene->addPhysicsChild(wall, PhysicsSceneEntity::SHAPE_PLANE, 0.0);
}

ProGameobject::~ProGameobject(){
}

int ProGameobject::update() {
    return core->updateAndRender();
}

