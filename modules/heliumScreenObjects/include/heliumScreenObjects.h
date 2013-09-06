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

class AlifeScreenObject {
public:
    AlifeScreenObject(Polycode::ScreenEntity*);
    virtual ~AlifeScreenObject() {}
    
    virtual void lifeStep()=0;
    virtual void mouseCursor()=0;
    virtual void mouseClick( bool upDown )=0;
    virtual void mouseDoubleClick()=0;
};

typedef std::pair< IHeliumObjectsWorld::ObjectsIdType, AlifeScreenObject* > AlifePairType;

class PackagedAlifeScreenObject {
public:
    PackagedAlifeScreenObject (){}
    
    virtual ~PackagedAlifeScreenObject (){}
    
    Polycode::ScreenEntity* getModel()const {
        return model;
    }
    
    int getEntityType()const {
        return entityType;
    }

    AlifePairType getAlifePair()const {
        return AlifePairType(
                reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(model),
                heliumAlife );
    }

protected:
    Polycode::ScreenEntity* model;
    int entityType;

    AlifeScreenObject* heliumAlife;
};

class PackagedScreenObject {
public:
    PackagedScreenObject (){}
    
    virtual ~PackagedScreenObject (){}
    
    Polycode::ScreenEntity* getModel()const {
        return model;
    }
    
    IHeliumObjectsWorld::ObjectsIdType getId()const {
        return reinterpret_cast<IHeliumObjectsWorld::ObjectsIdType>(model);
    }

protected:
    Polycode::ScreenEntity* model;
};

class ScreenObjectsFactory {
public:
    ScreenObjectsFactory () {}
    ~ScreenObjectsFactory () {}
    static PackagedScreenObject& make(int);
private:

};

class ScreenObjectsWorld : public IHeliumObjectsWorld {
public:
    ScreenObjectsWorld();
    virtual ~ScreenObjectsWorld();
    
    void lifeStep();

    bool mouseClick( int button, bool upDown, Polycode::Vector2 position );
    
    void setPause(bool);
    bool getPause();
    
    //Polycode::Screen* getEngineScreenPt() { 
    //    return engineScreen;
    //}
    //typedef unsigned long long int HeliumObjectsIdType;
    
    void signOutObject( IHeliumObjectsWorld::ObjectsIdType );
    
    IHeliumObjectsWorld::ObjectsIdType addObject( PackagedScreenObject& );
    IHeliumObjectsWorld::ObjectsIdType addAlifeObject( PackagedAlifeScreenObject& );
    
private:
    Polycode::PhysicsScreen* engineScreen;
    
    // may be in the future here will be map
    std::set< IHeliumObjectsWorld::ObjectsIdType > objects;
    typedef std::set< IHeliumObjectsWorld::ObjectsIdType >::iterator ObjectIterator;
    
    std::map< IHeliumObjectsWorld::ObjectsIdType, AlifeScreenObject* > alifeObjects;
    typedef std::map< IHeliumObjectsWorld::ObjectsIdType, AlifeScreenObject* >::iterator AlifeIterator;
};

#endif // HELIUM_SCREEN_OBJECTS_INCLUDED

