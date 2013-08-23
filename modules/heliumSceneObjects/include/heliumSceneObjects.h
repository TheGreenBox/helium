/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumSceneObjects.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef _HELIUM_SCENE_OBJECTS_INCLUDED_
#define _HELIUM_SCENE_OBJECTS_INCLUDED_

#include <list>

#include <Polycode.h>
#include "Polycode3DPhysics.h"
#include "heliumPrepared3DObjects.h"

class ObjectBehavior {
public:
    ObjectBehavior();
    virtual ~ObjectBehavior();
    void thinkAndDo();
private:
    
};

class ObjectVitalSings {
public:
    ObjectVitalSings();
    virtual ~ObjectVitalSings();
    void takeThePulse();
    void getHarm(long int);
    
private:
    long int health;
    long int damage;
};

class LifelessObject {
public:    
    LifelessObject(Polycode::ScenePrimitive*);
    
    virtual ~LifelessObject();
    
    void setPosition( double x, double y, double z );
    
    Polycode::ScenePrimitive* getModel() { return model; }
    
protected:
    Polycode::ScenePrimitive* model;
};

class AliveObject : public LifelessObject {
public:    
    //AliveObject();
    AliveObject(Polycode::ScenePrimitive*);
    virtual ~AliveObject();
    void lifeStep();
    
protected:
    ObjectVitalSings*  pPulse;
    ObjectBehavior*    pMind;
};

struct PhysicsObject {
    PhysicsObject();
    ~PhysicsObject();
    
    LifelessObject* body; 
    
    int type;
    Number mass;
    Number friction;
    Number restitution;
    int group;
};

struct CollisionOnlyObject {
    CollisionOnlyObject();
    ~CollisionOnlyObject();
    
    LifelessObject* body; 

    int type; 
};

struct ImmaterialObject {
    ImmaterialObject();
    ~ImmaterialObject();

    LifelessObject* body; 
};

class CommonWorldObjects {
public:    
    CommonWorldObjects(Polycode::PhysicsScene*);
    virtual ~CommonWorldObjects();
    
    void addObject( HeliumPrepared3D );
    
    void addObject( PhysicsObject );
    void addObject( CollisionOnlyObject );
    void addObject( ImmaterialObject );
    
    void addImmaterialObject( LifelessObject* );
    void addImmaterialObject( AliveObject* );
    
    void addPhysicsObject( AliveObject* obj,
                           int type=0,
                           Number mass = 0.0f,
                           Number friction=1,
                           Number restitution=0,
                           int group=1, 
                           bool compoundChildren = false );
    
    void addCollisionOnlyObject( AliveObject* obj,
                                 int type, 
                                 bool compoundChildren = false );
    
    void addPhysicsObject( LifelessObject* obj,
                           int type=0,
                           Number mass = 0.0f,
                           Number friction=1,
                           Number restitution=0,
                           int group=1, 
                           bool compoundChildren = false );
    
    void addCollisionOnlyObject( LifelessObject* obj,
                                 int type, 
                                 bool compoundChildren = false );
    
    void lifeStep();
    
private:
    Polycode::PhysicsScene*     pEngineScene;
    
    std::list< LifelessObject* >  lifelessObjects;
    std::list< AliveObject*    >  aliveObjects;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_

