/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_2D_ObjectPackaging.h
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_2D_OBJECT_PACKAGING_INCLUDED
#define  HELIUM_2D_OBJECT_PACKAGING_INCLUDED 

#include "helium_2D_Object.h"

#include "objectPackagingInterface.h"

/**
*
*/  
class Packaged_2D_Object : public IHeliumPackaging {
public:
    /**
    *
    */
    Packaged_2D_Object (){}
    
    virtual ~Packaged_2D_Object (){}
    
    /**
    *
    */  
    Polycode::ScreenEntity* getModel()const;
    
    /**
    *
    */  
    typename Helium_2D_ObjectContainer::ObjectPairType getObjectPair()const;
    
    /**
    *
    */  
    ObjectEntityType getEntityType()const;
    
    /**
    *
    */  
    int getShapeType()const;
    
protected:
    Helium_2D_Object* object;
    
    ObjectEntityType entityType;
    int entityShapeType;
    int alife;
};

/**
*
*/  
class Helium_2D_ObjectFactory {
public:
    /**
    *
    */  
    Helium_2D_ObjectFactory () {}
    
    ~Helium_2D_ObjectFactory () {}
    
    /**
    *
    */  
    static Packaged_2D_Object* make(int);
private:

};
#endif // HELIUM_2D_OBJECT_PACKAGING_INCLUDE 
