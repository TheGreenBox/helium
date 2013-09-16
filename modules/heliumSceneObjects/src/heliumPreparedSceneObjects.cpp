/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/heliumSceneObjects/src/heliumPrepared3DObjects.cpp 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
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
    friction = 1;
    restitution = 0;
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
    
    mass = 0.0;
    friction = 1;
    restitution = 0;
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
    friction = 1;
    restitution = 0;
}
