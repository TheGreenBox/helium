/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/helium_3D_Object/src/helium_3D_CharVitals.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
 
#include "helium_3D_CharVitals.h"

struct Vitals {
    int health;
    int armor;
    int morality;

CharacterVitals::CharacterVitals( int maxHealth,
                                  int maxArmor    =0,
                                  int maxMorality =1 )
    :   Vitals( maxHealth, maxArmor, maxMorality ),
        this->maxHealth(maxHealth),      
        this->maxArmor(maxArmor), 
        this->maxMorality(maxMorality) 
{}
