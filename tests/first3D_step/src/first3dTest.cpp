#include "first3dTest.h"

First3DTest::First3DTest(PolycodeView *view) 
{

	core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);

	//CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
	//CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	Scene *scene = new Scene();
	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 25,25);
	ground->loadTexture("helium_resource/sand_big.png");
	scene->addEntity(ground);

	ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 1,1,1);
	box->loadTexture("helium_resource/electronica.png");
	box->setPosition(0.0, 0.5, 0.0);
	scene->addEntity(box);
	
    scene->getDefaultCamera()->setPosition(10,10,10);
	scene->getDefaultCamera()->lookAt(Vector3(0,-2,0));

	Screen *screen = new Screen();			
    cursor = new ScreenImage("helium_resource/cursor.png");
	cursor->setPositionMode(ScreenEntity::POSITION_CENTER);
	screen->addChild(cursor);	
	
	core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEMOVE);
	core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEDOWN);
	core->getInput()->addEventListener(this, InputEvent::EVENT_MOUSEUP);
}

First3DTest::~First3DTest() 
{ }

void First3DTest::handleEvent(Event *e) {
	
	if(e->getDispatcher() == core->getInput()) {
		InputEvent *inputEvent = (InputEvent*)e;
		switch(e->getEventCode()) {
			case InputEvent::EVENT_MOUSEMOVE:
				cursor->setPosition(inputEvent->mousePosition.x,
						   inputEvent->mousePosition.y);
			break;
			case InputEvent::EVENT_MOUSEDOWN:
				cursor->setColor(1,0,0,1);
			break;			
			case InputEvent::EVENT_MOUSEUP:
				cursor->setColor(1,1,1,1);	
			break;						
		}
	}
	
}

bool First3DTest::Update() 
{
    return core->updateAndRender();
}
