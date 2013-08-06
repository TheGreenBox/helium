/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumSceneObjects.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

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

ObjectDamage::ObjectDamage() {
}

ObjectDamage::~ObjectDamage() {
}

void ObjectDamage::takeThePulse() {
}

StaticObject::StaticObject() {
}

StaticObject::~StaticObject() {
}

DynamicObject::DynamicObject() {
}

DynamicObject::DynamicObject(Polycode::SceneMesh*) {
}

DynamicObject::~DynamicObject() {
}
    
PhysicObject::PhysicObject() {
}

PhysicObject::PhysicObject(Polycode::SceneMesh*) {
}

PhysicObject::~PhysicObject() {
}

CollisionOnlyObject::CollisionOnlyObject() {
}

CollisionOnlyObject::CollisionOnlyObject(Polycode::SceneMesh*) {
}

CollisionOnlyObject::~CollisionOnlyObject() {
}

ImmaterialObject::ImmaterialObject() {
}

ImmaterialObject::ImmaterialObject(Polycode::SceneMesh*) {
}

ImmaterialObject::~ImmaterialObject() {
}

CommonWorldObjects::CommonWorldObjects() { 
}

CommonWorldObjects::~CommonWorldObjects() {
}

