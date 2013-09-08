/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumScreenObjects/include/heliumScreenOjects.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_SCREEN_OBJECTS_INCLUDED
#define HELIUM_SCREEN_OBJECTS_INCLUDED

#include <set>
#include <map>
#include <Polycode.h>
#include <PolyPhysicsScreen.h>

#include "heliumObjectsWorldIntefrace.h"

class ScreenObject;
class ScreenObjectsWorld;
class PackagedScreenObject;
class ScreenObjectsFactory;

/**
*
*/  
class ScreenObject {
public:
    /**
    *
    */  
    ScreenObject(Polycode::ScreenEntity*);
    
    virtual ~ScreenObject() {}
    
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
*
*/  
class ScreenObjectsWorld : public IHeliumObjectsWorld {
public:

    /**
    *
    */  
    ScreenObjectsWorld();
    virtual ~ScreenObjectsWorld();
    
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
    void signOutObject( IHeliumObjectsWorld::ObjectsIdType );
    
    /**
    *
    */  
    IHeliumObjectsWorld::ObjectsIdType addObject( PackagedScreenObject* );
    
    //!> 
    typedef std::pair< IHeliumObjectsWorld::ObjectsIdType, ScreenObject* > AlifePairType;
    
private:
    Polycode::PhysicsScreen* engineScreen;
    
    // may be in the future here will be map
    std::set< IHeliumObjectsWorld::ObjectsIdType > objects;
    typedef std::set< IHeliumObjectsWorld::ObjectsIdType >::iterator ObjectIterator;
    
    std::map< IHeliumObjectsWorld::ObjectsIdType, ScreenObject* > alifeObjects;
    typedef std::map< IHeliumObjectsWorld::ObjectsIdType, ScreenObject* >::iterator AlifeIterator;
};

/**
*
*/  
class PackagedScreenObject {
public:
    /**
    *
    */
    PackagedScreenObject (){}
    
    virtual ~PackagedScreenObject (){}
    
    /**
    *
    */  
    Polycode::ScreenEntity* getModel()const;
    
    /**
    *
    */  
    ScreenObjectsWorld::AlifePairType getAlifePair()const;
    
    /**
    *
    */  
    IHeliumObjectsWorld::ObjectsIdType getId()const;
    
    typedef enum {
        ENTITY_IMMATERIAL,
        ENTITY_COLLISION_ONLY,
        ENTITY_PHYSICAL,     
        ENTITY_EMPTY
    } ScreenEntityType;
    
    /**
    *
    */  
    ScreenEntityType getEntityType()const;
    
    /**
    *
    */  
    int getShapeType()const;
    
    /**
    *
    */  
    int isAlife ()const;
    
protected:
    ScreenObject* heliumAlife;
    
    ScreenEntityType entityType;
    int entityShapeType;
    int alife;
};

/**
*
*/  
class ScreenObjectsFactory {
public:
    /**
    *
    */  
    ScreenObjectsFactory () {}
    
    ~ScreenObjectsFactory () {}
    
    /**
    *
    */  
    static PackagedScreenObject& make(int);
private:

};

#endif // HELIUM_SCREEN_OBJECTS_INCLUDED

