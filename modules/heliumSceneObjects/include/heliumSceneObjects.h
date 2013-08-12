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

/*
    SceneMesh *mesh = new SceneMesh("ninja.mesh");
        mesh->loadTexture("ninja.png");
        mesh->loadSkeleton("ninja.skeleton");
        mesh->getSkeleton()->addAnimation("Run", "run.anim");
        mesh->getSkeleton()->playAnimation("Run");
        scene->addEntity(mesh);


    ScenePrimitive *box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 4,4,6);  
        box->setPitch(25.0);
        box->setPosition(7,-1.05, 0.0);
        box->setColor(0.5,0.5,1.0,1.0);
        box->loadTexture("green_texture.png");
        scene->addPhysicsChild(box, PhysicsSceneEntity::SHAPE_BOX, 0.0);


    testBox = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 4, 4, 4);
        testBox->loadTexture("Resources/pink_texture.png");
        testBox->setColor(0.3,0.5, 1.0,0.4);
        testBox->setPosition(-5,2,7);
        scene->addCollisionChild(testBox, PhysicsSceneEntity::SHAPE_BOX);
*/

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
    CommonWorldObjects();
    virtual ~CommonWorldObjects();
    
    void lifeStep();
    int  addObject(long int id);

private:

    Polycode::Scene* pEngineScene;
    
    std::list<StaticObject*>  staticiObjects;
    std::list<DynamicObject*> dynamicObjects;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_

