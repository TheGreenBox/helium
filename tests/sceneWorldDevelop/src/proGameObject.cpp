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
#include "proGameObject.h"

#include "pathGlobal.h"
#include "heliumScreenObjects.h"
#include "heliumGameGlobal.h"
#include "heliumPreparedScreenButton.h"
#include "heliumPreparedSceneObjects.h"

namespace P = Polycode;

void AddDice::process() {
}

void AddBarrel::process() {
}

void AddBoll::process() {
}

void XCameraMove::process() {
}

void XNegativeCameraMove::process() {
}

void YCameraMove::process() {
}

void YNegativeCameraMove::process() {
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
    
    HeliumTestFloor floor( 20.0, 20.0 );
    this->getSceneWorldPt()->addObject( &floor );
    
    HeliumTestBarrel barrel( 1, 3, 0, 0, 6 );
    this->getSceneWorldPt()->addObject( &barrel );

    HeliumTestBox box( 2, 2, 2, 2, 2, 5); 
    this->getSceneWorldPt()->addObject( &box );
    
    HeliumExitScreenButton exitBt(this);
    this->getScreenWorldPt()->addObject( &exitBt );
    
    HeliumSceneArchitecktHandPack hand;
    this->getSceneWorldPt()->addObject( &hand );
}

ProGameObject::~ProGameObject(){
}

