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

Vitals::Vitals( int _health, int _armor, int _morality )
    : health(_health),
      armor(_armor),
      morality(_morality)
{}

CharacterVitals::CharacterVitals( int _maxHealth,
                                  int _maxArmor,
                                  int _maxMorality )
    :   Vitals( maxHealth, maxArmor, maxMorality ),
        maxHealth(_maxHealth),      
        maxArmor(_maxArmor), 
        maxMorality(_maxMorality) 
{}
