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


class ObjectBehavior {
public:
    ObjectBehavior(){};
    virtual ~ObjectBehavior(){};
    void thinkAndDo();
private:
    
};

class ObjectDamage {
public:
    ObjectDamage(){};
    virtual ~ObjectDamage(){};
    void takeThePulse();
private:
    long int damage;
    
};

class StaticObject {
public:    
    StaticObject(){};
    virtual ~StaticObject(){};

private:
    Polycode::SceneMesh* pModel;
};

class DynamicObject {
public:    
    DynamicObject();
    DynamicObject(Polycode::SceneMesh*);
    
    virtual ~DynamicObject(){};
    
protected:
    int priorityLevel;
    ObjectDamage*   pPulse;
    ObjectBehavior* pMind;
};

class PhysicObject : public DynamicObject {
public:    
    PhysicObject();
    PhysicObject(Polycode::SceneMesh*);
    
    virtual ~PhysicObject();

private:
	Polycode::PhysicsSceneEntity*  pEntity;
};

class CollisionOnlyObject : public DynamicObject{
public:    
    CollisionOnlyObject();
    CollisionOnlyObject(Polycode::SceneMesh*);
    
    virtual ~CollisionOnlyObject();

private:
    Polycode::CollisionSceneEntity* pEntity;
};

class ImmaterialObject : public DynamicObject{
public:    
    ImmaterialObject();
    ImmaterialObject(Polycode::SceneMesh*);
    
    virtual ~ImmaterialObject();

private:
    Polycode::SceneMesh* pEntity;
};

class WorldObjects {
public:    
    WorldObjects(){};
    virtual ~WorldObjects(){};
};

class CommonWorldObjects : public WorldObjects {
public:    
    CommonWorldObjects(){};
    virtual ~CommonWorldObjects(){};

private:
    std::list<StaticObject*>  staticiObjects;
    std::list<DynamicObject*> dynamicObject;
};

#endif // _HELIUM_SCENE_OBJECTS_INCLUDED_

