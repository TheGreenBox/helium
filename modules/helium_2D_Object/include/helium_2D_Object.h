/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumHelium_2D_Objects/include/heliumScreenOjects.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_SCREEN_OBJECTS_INCLUDED
#define HELIUM_SCREEN_OBJECTS_INCLUDED

#include "Polycode.h"

/**
*
*/  
class Helium_2D_Object {
public:
    /**
    *
    */  
    Helium_2D_Object( Polycode::ScreenEntity* ) {}
    
    virtual ~Helium_2D_Object() {}
    
    /**
    *
    */  
    virtual void lifeStep() {}
    
    /**
    *
    */  
    virtual void mouseCursor() {}
    
    /**
    *
    */  
    virtual void mouseClick( bool upDown ) {}
    
    /**
    *
    */  
    virtual void mouseDoubleClick() {}
    
    /**
    *
    */  
    Polycode::ScreenEntity* getModel() {
        return model;
    }
    
protected:
    Polycode::ScreenEntity* model;

};

/**
* @brief 2D_Objects container for intellectuals 2d_objects
*/
class Helium_2D_ObjectContainer {
public:
    Helium_2D_ObjectContainer() {}
    virtual ~Helium_2D_ObjectContainer() {}
    
    //!> 
    typedef typename std::pair< Polycode::ScreenEntity*, Helium_2D_Object* > ObjectPairType;
    
    Polycode::ScreenEntity* addObject( ObjectPairType ) {}
    void removeObject( Polycode::ScreenEntity* ) {}
    
private:
    std::map< Polycode::ScreenEntity*, Helium_2D_Object* > souls;
    typedef typename std::map< Polycode::ScreenEntity*, Helium_2D_Object* >::iterator SoulIteratirType;
    
};

#endif // HELIUM_SCREEN_OBJECTS_INCLUDED

