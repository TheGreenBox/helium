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
      keyboardInput(new KeyboardUserInput(this))
{
    
}
HeliumGameCore::~HeliumGameCore() {
    
}

void HeliumGameCore::game() { 
    keyboardInput->setEnable(true);
    HeliumGlobal::setCurrentGame(this);
    
    bool game_is_running = true;
    while( game_is_running ) {
        game_is_running = engineCore->Update();
        objectWorld.lifeStep();
        engineCore->Render();
    }
    keyboardInput->setEnable(false);
    HeliumGlobal::setCurrentGame(NULL);
    return; 
}

