/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumGameGlobal.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include "heliumGameGlobal.h"

HeliumGameCore* HeliumGlobal::workingGame = NULL;

HeliumGameCore* HeliumGlobal::getCurrentGame() {
    return workingGame;
}

void HeliumGlobal::setCurrentGame(HeliumGameCore* newGame) {
    workingGame = newGame;
}
    
HeliumGlobal::HeliumGlobal() {
}

HeliumGlobal::~HeliumGlobal() { 
}

