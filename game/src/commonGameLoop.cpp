/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumCore.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <Polycode.h>
#include "PolycodeView.h"

#include "commonGameLoop.h"
    
HeliumCore::HeliumCore( Polycode::PolycodeView *view ) {

    // TODO: fix it whe link text config files
    // xRes Inital horizontal resolution of the renderer.
    int xRes = 640;
    // yRes Inital vertical resolution of the renderer.		
    int yRes = 480;
    // fullScreen True to launch in fullscreen, false to launch in window.
    bool fullScreen = false;
    bool vSync = false; // WTF ?
    // aaLevel Level of anti-aliasing. Possible values are 2,4 and 6.
    int aaLevel = 0;
    int anisotropyLevel = 0; // wtf?
    int frameRate = 90;	

    engineCore = new Polycode::POLYCODE_CORE ( view,xRes,yRes,fullScreen,vSync,aaLevel,anisotropyLevel,frameRate);

    menu = new HeliumMainMenu(engineCore);
}

HeliumCore::~HeliumCore() {
    delete menu;
    delete engineCore;
}

void HeliumCore::loop() {

    // if user choose the Exit load return 0
    while( menu->load(gameCore) ) {
        if (gameCore) {
            gameCore->game();
        }
    }
    
    return;
}
