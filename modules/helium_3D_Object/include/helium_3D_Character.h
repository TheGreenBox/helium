/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_3D_CharIntelligence.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_3D_CHARACTER_INTELLIGENCE_INCLUDED
#define  HELIUM_3D_CHARACTER_INTELLIGENCE_INCLUDED

#include <map>
#include <set>
#include "Polycode.h"
#include "helium_3D_CharVitals.h"

class CharacterWeapon {
    CharacterWeapon(){}
    virtual ~CharacterWeapon(){}
};

/**
*
*/  
class HeliumCharacter {
public:
    /**
    *
    */  
    HeliumCharacter();
    virtual ~HeliumCharacter();
    
    /**
    *
    */  
    void pulse();
    
private:
    CharacterVitals vitals;
    CharacterWeapon weapon;
};

class HeliumCharacterContainer {
    HeliumCharacterContainer() {}
    ~HeliumCharacterContainer() {}
    
    void lifeStep(){}
    void addSoul( HeliumCharacter*, Polycode::SceneEntity* ){}
    void killSoul( Polycode::SceneEntity* ){}
    
    void getHarm( const CharacterHarm& harm ){}
    
private:
    std::map< Polycode::SceneEntity*, HeliumCharacter* > souls;
    std::set< Polycode::SceneEntity* > queueToMousePoint;
};

#endif // HELIUM_3D_CHARACTER_INTELLIGENCE_INCLUDED

