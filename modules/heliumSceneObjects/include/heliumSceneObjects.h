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

class HeliumObject {
public:    
    virtual void changeMesh()=0;
    virtual void setPosition( double x, double y, double z )=0;
    virtual void pushToScene(Polycode::PhysicsScene*)=0;
};

class StaticObject : public HeliumObject {
public:    
    StaticObject(Polycode::SceneMesh* );
    virtual ~StaticObject();
    
    void setPosition( double x, double y, double z ){};

private:
    Polycode::SceneMesh* pModel;
};

class DynamicObject : public HeliumObject {
public:    
    DynamicObject();
    virtual ~DynamicObject();
    void lifeStep();
    
protected:
    ObjectVitalSings*  pPulse;
    ObjectBehavior*    pMind;
};

class PhysicsObject : public DynamicObject {
public:    
    PhysicsObject(Polycode::SceneMesh*);
    
    virtual ~PhysicsObject();
    
    void changeMesh(){};
    void setPosition( double x, double y, double z ){};
    void pushToScene(Polycode::PhysicsScene*){};

private:
	Polycode::PhysicsSceneEntity*  pEntity;
};

class CollisionOnlyObject : public DynamicObject{
public:    
    CollisionOnlyObject(Polycode::SceneMesh*);
    
    virtual ~CollisionOnlyObject();
    
    void changeMesh(){};
    void setPosition( double x, double y, double z ){};

private:
    Polycode::CollisionSceneEntity* pEntity;
};

class ImmaterialObject : public DynamicObject{
public:    
    ImmaterialObject(Polycode::SceneMesh*);
    
    virtual ~ImmaterialObject();
    
    void changeMesh(){};
    void setPosition( double x, double y, double z ){};

private:
    Polycode::SceneMesh* pEntity;
};

class CommonWorldObjects {
public:    
    CommonWorldObjects(Polycode::PhysicsScene*);
    virtual ~CommonWorldObjects();
    
    void addDynamic( DynamicObject* );
    void addStatic( StaticObject* );
    
    void lifeStep();
    
private:
    Polycode::PhysicsScene*     pEngineScene;
    
    std::list< StaticObject* >  staticiObjects;
    std::list< DynamicObject*>  dynamicObjects;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_

