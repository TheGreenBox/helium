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
#include <PolyCollisionSceneEntity.h>
#include <PolyPhysicsSceneEntity.h>

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

class StaticObject {
public:    
    StaticObject();
    StaticObject(Polycode::SceneMesh* );
    virtual ~StaticObject();
    
    Polycode::SceneMesh* getMesh(){ return pModel; };
    void changeMesh(){};
    void setPosition( double x, double y, double z );

private:
    Polycode::SceneMesh* pModel;
};

class DynamicObject {
public:    
    DynamicObject();
    DynamicObject(Polycode::SceneMesh*);
    
    virtual ~DynamicObject();
    virtual void lifeStep();
    
    virtual Polycode::SceneMesh* getMesh()=0;
    virtual void changeMesh()=0;
    virtual void setPosition( double x, double y, double z )=0;
    
protected:
    int priorityLevel;
    ObjectVitalSings*  pPulse;
    ObjectBehavior*    pMind;
};

class PhysicObject : public DynamicObject {
public:    
    PhysicObject();
    PhysicObject(Polycode::SceneMesh*);
    
    virtual ~PhysicObject();
    
    Polycode::SceneMesh* getMesh(){ return NULL; };
    void changeMesh(){};
    void setPosition( double x, double y, double z ){};

private:
	Polycode::PhysicsSceneEntity*  pEntity;
};

class CollisionOnlyObject : public DynamicObject{
public:    
    CollisionOnlyObject();
    CollisionOnlyObject(Polycode::SceneMesh*);
    
    virtual ~CollisionOnlyObject();
    
    Polycode::SceneMesh* getMesh(){ return NULL; };
    void changeMesh(){};
    void setPosition( double x, double y, double z ){};

private:
    Polycode::CollisionSceneEntity* pEntity;
};

class ImmaterialObject : public DynamicObject{
public:    
    ImmaterialObject();
    ImmaterialObject(Polycode::SceneMesh*);
    
    virtual ~ImmaterialObject();
    
    Polycode::SceneMesh* getMesh(){ return NULL; };
    void changeMesh(){};
    void setPosition( double x, double y, double z ){};

private:
    Polycode::SceneMesh* pEntity;
};

class WorldObjects {
public:    
    WorldObjects();
    virtual ~WorldObjects();
    
    virtual void lifeStep()=0;
    virtual int  addObject(long int id)=0;
};

class CommonWorldObjects : public WorldObjects {
public:    
    CommonWorldObjects(Polycode::Scene*);
    virtual ~CommonWorldObjects();
    
    void lifeStep();
    int  addObject(long int id);
    
    void  addGround(long int id);

private:

    Polycode::Scene* pEngineScene;
    
    std::list<StaticObject*>  staticiObjects;
    std::list<DynamicObject*> dynamicObjects;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_

