/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  firstTestClass.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include "firstTestClass.h"
#include "PolySDLCore.h"

FirstStepTest::FirstStepTest(PolycodeView *view) 
{
	core = new SDLCore(view, 640,480,false,false,0,0,90);
	  
//	CoreServices::getInstance()->getResourceManager()->addArchive("Resources/default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

	Screen *screen = new Screen();			
	image = new ScreenImage("Resources/polycode_logo.png");
	screen->addChild(image);	
}

FirstStepTest::~FirstStepTest() 
{}

bool FirstStepTest::Update()
{
	Number elapsed = core->getElapsed();
	image->setRotation(image->getRotation()+(elapsed*100));
    return core->updateAndRender();
}