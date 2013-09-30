/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumSceneObjects.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_SCENE_OBJECTS_INCLUDED
#define HELIUM_SCENE_OBJECTS_INCLUDED

#include <list>
#include <set>
#include <map>

#include <Polycode.h>
#include "Polycode3DPhysics.h"

#include "objectPackagingInterface.h"

/**
*
*/
class Packaged_3D_Object : public IHeliumPackaging {
public:
    Packaged_3D_Object();
    virtual ~Packaged_3D_Object(){};

    /**
    * @brief return one of [ SHAPE_BOX, SHAPE_TERRAIN, SHAPE_SPHERE,
                SHAPE_MESH, CHARACTER_CONTROLLER, SHAPE_CAPSULE,
                SHAPE_PLANE, SHAPE_CONE, SHAPE_CYLINDER             ]
    */
    int getShapeType ();
    
    /**
    * @brief return mass of 3d object
    */  
    Number getMass ();
    
    /**
    * @brief return coefficient of friction
    */  
   	Number getFriction ();
    
    /**
    * @brief 
    */  
    Number getRestitution ();

    /**
    * @brief
    */  
    int getGroup ();

    /**
    * @brief
    */  
    bool getCompoundChildren ();
    
    /**
    * @brief
    */  
    ObjectEntityType getEntityType()const;
    
    /**
    * @brief
    */  
    //SceneObjectsWorld::AlifePairType getAlifePair()const;
    
    /**
    * @return Polycode::SceneEntity pointer
    */  
    Polycode::SceneEntity* getModel()const;
    
protected:
    //!> Pointer to PolySceneObject helium wrap
    HeliumCharacter* character;
    
    ObjectEntityType entityType;
    
    int    shapeType;
    Number mass;
    Number friction;
    Number restitution;
    int    group;
    bool   compoundChildren;
};

/*
* @brief Helium 3d objects factory interface
*/  
class SceneObjectsFactory {
public:
    /**
    * @brief
    * @param id of prepared helium scene objects
    */  
    static Packaged_3D_Object& make(int);
private:
    SceneObjectsFactory () {}
    ~SceneObjectsFactory () {}
};

#endif // HELIUM_SCENE_OBJECTS_INCLUDED

