/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_2D_World.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_2D_WORLD_INCLUDED 
#define  HELIUM_2D_WORLD_INCLUDED

#include <set>
#include <map>

#include "Polycode.h"
#include "PolyPhysicsScreen.h"

#include "objectsWorldIntefrace.h"

#include "helium_2D_Object.h"
#include "helium_2D_ObjectPackaging.h"

/**
*
*/  
class Helium_2D_World : public IHeliumObjectsWorld {
public:

    /**
    *
    */  
    Helium_2D_World();
    virtual ~Helium_2D_World();
    
    /**
    *
    */  
    void lifeStep();

    /**
    *
    */  
    bool mouseClick( int button, bool upDown, Polycode::Vector2 position );
    
    /**
    *
    */  
    void setPause(bool);
    
    /**
    *
    */  
    bool getPause();
    
    /**
    *
    */  
    void signOutObject( Polycode::ScreenEntity* );
    
    /**
    *
    */  
    Polycode::ScreenEntity* addObject( Packaged_2D_Object* );
    
    //!> short name for ScreenEntity pointer 
    typedef typename Polycode::ScreenEntity* ObjectId;
    
protected:
    Polycode::PhysicsScreen* engineScreen;

private:

    Helium_2D_ObjectContainer souls;    
};

#endif // HELIUM_2D_WORLD_INCLUDED

