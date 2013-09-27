/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/heliumSceneObjects/src/heliumPrepared3DObjects.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#include <iostream>
#include "heliumGameGlobal.h"
#include "heliumPreparedSceneObjects.h"
#include "pathGlobal.h"

namespace P = Polycode;

HeliumTestBarrel::HeliumTestBarrel( double radius, double hight, 
                                    double position_x, double position_y, 
                                    double position_z) {

//    P::SceneMesh* model = new P::SceneMesh( g_helium_resource_path + "/barrel_3d/helium_barrel.mesh");
//    model->setScale(0.01, 0.01, 0.01);
//    model->rebuildTransformMatrix();
//    model->loadTexture( g_helium_resource_path + "/barrel_3d/1/diffus.png");
//    model->setPosition(position_x, position_z, position_y );
        
    P::ScenePrimitive* model = new P::ScenePrimitive( P::ScenePrimitive::TYPE_CYLINDER, 
                                                      hight, radius, 12 );

	model->loadTexture( g_helium_resource_path + "/ChrisGerrard_tooth_steampunk_gear.png");
	model->setPosition(position_x, position_z, position_y );
    
    heliumObject = new SceneObject(model);
    alife = 1;
    entityType = POLY_ENTITY_PHYSICAL;
    shapeType = P::PhysicsSceneEntity::SHAPE_CYLINDER;
    mass = 1;
}

HeliumTestFloor::HeliumTestFloor( double size_x, double size_y ) 
{   
    P::ScenePrimitive* ground = new P::ScenePrimitive( P::ScenePrimitive::TYPE_PLANE, 
                                                        size_x, size_y );

    ground->loadTexture(g_helium_resource_path + "/simple_stone_texture.png");
    heliumObject = new SceneObject(ground);
    alife = 1;
    entityType = POLY_ENTITY_PHYSICAL;
    shapeType = P::PhysicsSceneEntity::SHAPE_PLANE;
}

HeliumTestBox::HeliumTestBox( double size_x, double size_y, double size_z,
                                 double pos_x, double pos_y, double pos_z ) 
{   
    P::ScenePrimitive* box = new P::ScenePrimitive( P::ScenePrimitive::TYPE_BOX, 
                                                       size_x, size_y, size_z );

    box->loadTexture(g_helium_resource_path + "/flame1.png");
	box->setPosition(pos_x, pos_z, pos_y );
    heliumObject = new SceneObject(box);
    alife = 1;
    entityType = POLY_ENTITY_PHYSICAL;
    shapeType = P::PhysicsSceneEntity::SHAPE_BOX;
    mass = 0.5;
}

Helium556BulletBox::Helium556BulletBox(double pos_x, double pos_y, double pos_z, double size ) 
{   
    P::ScenePrimitive* box = new P::ScenePrimitive( P::ScenePrimitive::TYPE_BOX, 
                                                       size*5, size*3, size*3 );

    box->loadTexture(g_helium_resource_path + "/556bullet_box.png");
	box->setPosition(pos_x, pos_z, pos_y);
    heliumObject = new SceneObject(box);
    alife = 1;
    entityType = POLY_ENTITY_PHYSICAL;
    shapeType = P::PhysicsSceneEntity::SHAPE_BOX;
    mass = size;
}

HeliumSceneArchitecktHand::HeliumSceneArchitecktHand(IHeliumObjectsWorld::ObjectsIdType id)
    :   SceneObject(new P::ScenePrimitive(P::ScenePrimitive::TYPE_SPHERE, 0.25, 5, 5 )),
        creatingObject(id) {}

HeliumSceneArchitecktHand::~HeliumSceneArchitecktHand() {
}

void HeliumSceneArchitecktHand::lifeStep() {
    HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
    Polycode::Vector2 mouse = gm->getEngineCorePt()->getInput()->getMousePosition();
    Polycode::RayTestResult rayRez = gm->getSceneWorldPt()->rayTest(mouse);
    
    gm->getSceneWorldPt()->warpTo(creatingObject, rayRez.position);
    // rayRez.position.y += model->bBox.y/2;
    model->setPosition(rayRez.position);
    std::cout << rayRez.position.x << ' '
                << rayRez.position.y << ' '
                << rayRez.position.z << '\n';
}
    
void HeliumSceneArchitecktHand::mousePoint( int button, bool upDown, Polycode::Vector2 mouse ) {
    std::cout << "HeliumSceneArchitecktHand::mousePoint()\n";
    
    if( creatingObject ) {
        creatingObject = 0;
        //HeliumGlobal::getCurrentGame()->getSceneWorldPt()->delayedSignOut( this->getId() );
    }
    else {
        HeliumGameCore* gm = HeliumGlobal::getCurrentGame();
        Polycode::Vector2 mouse = gm->getEngineCorePt()->getInput()->getMousePosition();
        Polycode::RayTestResult rayRez = gm->getSceneWorldPt()->rayTest(mouse);
        creatingObject = gm->getSceneWorldPt()->getObjectIdByEntity(rayRez.entity);
    }
}
    
void HeliumSceneArchitecktHand::mouseDoubleClick() {
}

HeliumSceneArchitecktHandPack::HeliumSceneArchitecktHandPack( 
                                    IHeliumObjectsWorld::ObjectsIdType id) {
    heliumObject = new HeliumSceneArchitecktHand(id);
    alife = 1;
    entityType = POLY_ENTITY_IMMATERIAL;
    shapeType = P::PhysicsSceneEntity::SHAPE_BOX;
    addToMousePointQueue = true;
}

HeliumSceneArchitecktHandPack::~HeliumSceneArchitecktHandPack() {
}

