/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumPreparedScreenButton.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include <Polycode.h>

#include "heliumPreparedScreenButton.h"
#include "keyboardHandler.h"
//#include "heliumGameGlobal.h"
#include "pathGlobal.h"

namespace P = Polycode;

HeliumPauseScreenButton::HeliumPauseScreenButton (HeliumGameCore* gm) {
    const int b_size = 50;
    P::ScreenShape* shape = new P::ScreenShape( P::ScreenShape::SHAPE_RECT, 
                                                 b_size, b_size);
    shape->setPosition( gm->getEngineCorePt()->getXRes()/2,
                         gm->getEngineCorePt()->getYRes()/2);
  
    shape->loadTexture( g_helium_resource_path + "/pause_button.png" );
    button = new ScreenButton( shape, new PauseGame(), NULL );
}

HeliumPauseScreenButton::~HeliumPauseScreenButton () {
}

HeliumExitScreenButton::HeliumExitScreenButton(HeliumGameCore* gm) {
    const int b_size = 50;
    P::ScreenShape* shape = new P::ScreenShape( P::ScreenShape::SHAPE_RECT, 
                                                b_size, b_size);
    shape->setPosition( gm->getEngineCorePt()->getXRes()-b_size/2,
                        gm->getEngineCorePt()->getYRes()-b_size/2 );
    
    shape->loadTexture( g_helium_resource_path + "/exit_button.png" );
    button = new ScreenButton( shape, new EscapeGame(), NULL );
}

HeliumExitScreenButton::~HeliumExitScreenButton() {}

