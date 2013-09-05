/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumObjectsWorldIntefrace.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_OBJECTS_WORLD_INTEFRACE_INCLUDED 
#define  HELIUM_OBJECTS_WORLD_INTEFRACE_INCLUDED 

#include <Polycode.h>

class IHeliumObjectsWorld {
public:
    IHeliumObjectsWorld();
    virtual ~IHeliumObjectsWorld();
    
    /**
    * 
    */
    virtual void lifeStep()=0;

    /**
    * @param
    * @param
    * @param
    */
    virtual bool mouseClick( int button, bool upDown, Polycode::Vector2 position )=0;
    
    /**
    * @param
    */
    virtual void setPause(bool)=0;
    
    /**
    *
    */
    virtual bool getPause()=0;
    
    //!> 
    typedef unsigned long long int ObjectsIdType;
    
    /**
    * @param
    */
    virtual void signOutObject( ObjectsIdType )=0;
};

#endif // HELIUM_OBJECTS_WORLD_INTEFRACE_INCLUDED 
 
