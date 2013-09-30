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
    Helium_2D_Object( Polycode::ScreenEntity* );
    
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

class Helium_2D_ObjectContainer {
public:
    Helium_2D_ObjectContainer() {}
    ~Helium_2D_ObjectContainer() {}

    //!> 
    typedef std::pair< Polycode::ScreenEntity*, Helium_2D_Object* > ObjectPairType;
private:
    std::map< Polycode::ScreenEntity, Helium_2D_Object* > alifeObjects;
    typedef std::map< Polycode::ScreenEntity, Helium_2D_Object* >::iterator souls;
    
};

#endif // HELIUM_SCREEN_OBJECTS_INCLUDED

