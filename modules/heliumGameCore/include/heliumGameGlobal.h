/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumGameGlobal.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef  HELIUM_GAME_GLOBAL_INCLUDED 
#define  HELIUM_GAME_GLOBAL_INCLUDED

#include "heliumGameCore.h"

class HeliumGlobal {
public:
    static HeliumGameCore* getCurrentGame();
    static void setCurrentGame(HeliumGameCore*);
    
private:
    HeliumGlobal();
    ~HeliumGlobal();
    
    static HeliumGameCore* workingGame;
};
#endif // HELIUM_GAME_GLOBAL_INCLUDED 

