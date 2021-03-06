/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumSceneObjects.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <iostream>

#include <Polycode.h>

#include "heliumSceneObjects.h"

/*SceneMesh *mesh = new SceneMesh("ninja.mesh");
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

ObjectBehavior::ObjectBehavior() {
}

ObjectBehavior::~ObjectBehavior() {
}

void ObjectBehavior::thinkAndDo() {
}

ObjectVitalSings::ObjectVitalSings() {
}

ObjectVitalSings::~ObjectVitalSings() {
}

void ObjectVitalSings::takeThePulse() {
    health -= damage;
    damage  = 0;
}

void ObjectVitalSings::getHarm(long int newHarm) {
   damage += newHarm; 
}

LifelessObject::LifelessObject(Polycode::ScenePrimitive* _primitive)
    : model(_primitive) {
}

LifelessObject::~LifelessObject() {
}

AliveObject::AliveObject(Polycode::ScenePrimitive* _primitive)
    :LifelessObject(_primitive) {
}

AliveObject::~AliveObject() {
}

void AliveObject::lifeStep() {
    pPulse->takeThePulse();   
    pMind->thinkAndDo();
}
    
PhysicsObject::PhysicsObject() {
}

PhysicsObject::~PhysicsObject() {
}

CollisionOnlyObject::CollisionOnlyObject() {
}

CollisionOnlyObject::~CollisionOnlyObject() {
}

ImmaterialObject::ImmaterialObject() {
}

ImmaterialObject::~ImmaterialObject() {
}

CommonWorldObjects::CommonWorldObjects()
    : engineScene(new Polycode::PhysicsScene()) {
    engineScene->clearColor = Polycode::Color(1,1,1,1);
    engineScene->useClearColor = true;
}

CommonWorldObjects::~CommonWorldObjects() {
}

void CommonWorldObjects::addPhysicsObject( 
                LifelessObject* obj,
                int type,
                Number mass,
                Number friction,
                Number restitution,
                int group,
                bool compoundChildren ) { 
    engineScene->addPhysicsChild( obj->getModel(),type,mass,friction,
                                  restitution,group,compoundChildren );
    lifelessObjects.push_back( obj );
}

void CommonWorldObjects::lifeStep() {
    using std::list;
    for ( list<AliveObject*>::iterator it = aliveObjects.begin();
            it != aliveObjects.end(); ++it )
    {
        (*it)->lifeStep();
    }
}

void CommonWorldObjects::setPause(bool set) {
    engineScene->setEnabled(set);
}

bool CommonWorldObjects::getPause() {
    return engineScene->isEnabled();
}

