/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_3D_CharVitals.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef  HELIUM_3D_CHARACTER_VITALS_INCLUDED
#define  HELIUM_3D_CHARACTER_VITALS_INCLUDED

#include "Polycode.h"

/**
*
*/  
struct CharacterHarm {
    int harm;
    double probability;
};

/**
*
*/  
struct Vitals {
    int health;
    int armor;
    int morality;
};

/**
*
*/  
class CharacterVitals : protected Vitals {
public:
    /**
    *
    */  
    CharacterVitals( int maxHealth,
                     int maxArmor=0,
                     int maxMorality=1 );
    
    virtual ~CharacterVitals() {}
    
    /**
    * @brief
    */  
    void pulse() {}
    
    /**
    * @brief
    * @param
    */  
    void getHarm(long int) {}
    
//    int getHealth()const {
//        return health;
//    }
//    
//    int getArmor()const {
//        return armor;
//    }
//    
//    int morality()const {
//        return morality;
//    }

private:
    const int maxHealth;
    const int maxArmor;
    const int maxMorality;
};

#endif //HELIUM_3D_CHARACTER_VITALS_INCLUDED

