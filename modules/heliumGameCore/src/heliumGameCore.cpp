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

#if OS_WIN32
#include "windows.h"
#endif

namespace P = Polycode;

HeliumGameCore::HeliumGameCore( Polycode::Core* engCore ) 
    : engineCore( engCore ),
      keyboardInput(new KeyboardUserInput()),
      mouseInput(new MouseUserInput())
{
    
}
HeliumGameCore::~HeliumGameCore() {
    
}

void HeliumGameCore::mainLoop() {
    #if OS_WIN32
        MSG Msg;
        do {
            solidWorld.lifeStep();
            flatWorld.lifeStep();
            engineCore->Render();
            
            if(PeekMessage(&Msg, NULL, 0,0,PM_REMOVE)) {
                TranslateMessage(&Msg);
                DispatchMessage(&Msg);
            }
        } while( engineCore->Update() );
    #elif OS_LINUX
        while( engineCore->Update() ) {
            solidWorld.lifeStep();
            flatWorld.lifeStep();
            engineCore->Render();
        }
    #endif
}

void HeliumGameCore::game() { 
    HeliumGlobal::setCurrentGame(this);
    keyboardInput->setEnable(true);
    mouseInput->setEnable(true);
    
    this->mainLoop();
    
    mouseInput->setEnable(false);
    keyboardInput->setEnable(false);
    HeliumGlobal::setCurrentGame(NULL);
}

