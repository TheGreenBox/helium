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

namespace P = Polycode;

HeliumGameCore::HeliumGameCore( Polycode::Core* engCore ) 
    : HeliumGameCoreObjects( engCore ),
      keyboardInput(new KeyboardUserInput(this))
{
    
}
HeliumGameCore::~HeliumGameCore() {
    
}

void HeliumGameCore::game() { 
    //const int TICKS_PER_SECOND = 50;
    //const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    //const int MAX_FRAMESKIP = 10;
    bool game_is_running = true;

    while( game_is_running ) {
        //unsigned next_game_tick = engineCore->getTicks();
        //int loops = 0;
        
        //while( engineCore->getTicks() > next_game_tick 
        //        && loops < MAX_FRAMESKIP            ) {
            
        game_is_running = engineCore->Update();
        objectWorld.lifeStep();
   
        //    next_game_tick += SKIP_TICKS;
        //    loops++;
        //}
        engineCore->Render();
    }   
    return; 
}

