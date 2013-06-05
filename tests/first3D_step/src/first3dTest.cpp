#include "first3dTest.h"

First3DTest::First3DTest(PolycodeView *view) 
{

	core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);

	//CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
	//CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	Scene *scene = new Scene();
	ScenePrimitive *ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 5,5);
	ground->loadTexture("../helium_resource/sand_big.png");
	scene->addEntity(ground);

	ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 1,1,1);
	box->loadTexture("../helium_resource/electronica.png");
	box->setPosition(0.0, 0.5, 0.0);
	scene->addEntity(box);
	
	scene->getDefaultCamera()->setPosition(7,7,7);
	scene->getDefaultCamera()->lookAt(Vector3(0,0,0));

}

First3DTest::~First3DTest() 
{ }

bool First3DTest::Update() 
{
    return core->updateAndRender();
}
