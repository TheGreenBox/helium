/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumGameCore.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <iostream>
#include "heliumGameCore.h"
#include "heliumGameGlobal.h"

namespace P = Polycode;

HeliumGameCore::HeliumGameCore( Polycode::Core* engCore ) 
    : HeliumGameCoreObjects( engCore ),
      keyboardInput(new KeyboardUserInput()),
      mouseInput(new MouseUserInput())
{
    
}
HeliumGameCore::~HeliumGameCore() {
    
}

void HeliumGameCore::game() { 
    HeliumGlobal::setCurrentGame(this);
    keyboardInput->setEnable(true);
    mouseInput->setEnable(true);
    
    bool game_is_running = true;
    while( game_is_running ) {
        game_is_running = engineCore->Update();
        objectWorld.lifeStep();
        engineCore->Render();
    }
    mouseInput->setEnable(false);
    keyboardInput->setEnable(false);
    HeliumGlobal::setCurrentGame(NULL);
    return; 
}

