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

#include <set>
#include <map>

#include <Polycode.h>
#include "Polycode3DPhysics.h"

#include "heliumObjectsWorldIntefrace.h"

class ObjectBehavior;
class ObjectVitalSings;
class SceneObject;
class SceneObjectsWorld;
class PackagedSceneObject;
class SceneObjectsFactory;

/**
*
*/  
class ObjectBehavior {
public:
    /**
    *
    */  
    ObjectBehavior();
    virtual ~ObjectBehavior();
    
    /**
    *
    */  
    void thinkAndDo();
private:
    
};

/**
*
*/  
class ObjectVitalSings {
public:
    /**
    *
    */  
    ObjectVitalSings();
    virtual ~ObjectVitalSings();
    
    /**
    * @brief
    */  
    void takeThePulse();
    
    /**
    * @brief
    * @param
    */  
    void getHarm(long int);
    
private:
    long int health;
    long int damage;
};

/**
* @brief Helium screen object interface
*/  
class SceneObject {
public:
    /**
    * Constructor from 3d model
    */  
    SceneObject(Polycode::ScreenEntity*);
    
    virtual ~SceneObject() {}
    
    /**
    * @brief
    */  
    virtual void lifeStep() {}
    
    /**
    * @brief
    */
    virtual void getHarm() {}
    
    /**
    * @brief
    */  
    virtual void mouseCursor() {}
    
    /**
    * @brief
    */  
    virtual void mouseClick( bool upDown ) {}
    
    /**
    * @brief
    */  
    virtual void mouseDoubleClick() {}
    
    /**
    * @brief
    */  
    Polycode::SceneEntity* getModel() {
        return model;
    }
    
protected:
    Polycode::SceneEntity* model;
};

/**
* @brief contain all 3d objects in HeliumGameObject
*/
class SceneObjectsWorld : public IHeliumObjectsWorld {
public:

    /**
    * @brief default constrtuctor
    */  
    SceneObjectsWorld();
    virtual ~SceneObjectsWorld();
    
    /**
    * @brief Step of behavior in game main loop
    */
    void lifeStep();

    /**
    * @brief Method that will be call when mouse click event was occured
    * @param button - number of mouse button [0,1,2]
    * @param upDown - pushed down the button - false, realised the button - true
    * @param position - screen coords that have mouse cursor when event was occured
    */
    bool mouseClick( int button, bool upDown, Polycode::Vector2 position );
    
    /**
    * @brief Temporaly swithched off the world and not render it
    * @param [ true-pause, false-work ]
    */
    void setPause(bool);
    
    /**
    * @brief Check pause state of object world
    */
    bool getPause();
    
    
    /**
    * @brief Delete object from scene and from memory
    * @param Object index
    */
    void signOutObject( IHeliumObjectsWorld::ObjectsIdType );
    
    /**
    * @brief add helium scene object to sceneWorld
    * @param pointer to PackagedSceneObjects, you must to destruct after that
    */  
    IHeliumObjectsWorld::ObjectsIdType addObject( PackagedSceneObject* );
    
    //!> 
    typedef std::pair< IHeliumObjectsWorld::ObjectsIdType, SceneObject* > AlifePairType;

    
private:
    Polycode::PhysicsScene* engineScene;
    
    //!> dead objects, no behavior, no reactions, no life
    std::set< IHeliumObjectsWorld::ObjectsIdType > objects;
    typedef std::set< IHeliumObjectsWorld::ObjectsIdType >::iterator ObjectIterator;
    
    //!> container of alife objects, have reactions and posible have behavior
    std::map< IHeliumObjectsWorld::ObjectsIdType, SceneObject* > alifeObjects;
    typedef std::map< IHeliumObjectsWorld::ObjectsIdType, SceneObject* >::iterator AlifeIterator;
};

/**
*
*/
class PackagedSceneObject {
public:
    PackagedSceneObject() {}
    virtual ~PackagedSceneObject(){};

    /**
    * @brief return type of life, 0 - object is dead
    */  
    int isAlife ()const;

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
    
    //!> The way, we push object to poly scene 
    typedef enum {
        POLY_ENTITY_IMMATERIAL,
        POLY_ENTITY_COLLISION_ONLY,
        POLY_ENTITY_PHYSICAL,     
        POLY_ENTITY_EMPTY
    } PolySceneEntityType;
        
    /**
    * @brief
    */  
    SceneObjectsWorld::AlifePairType getAlifePair()const;
    
    /**
    * @brief
    */  
    IHeliumObjectsWorld::ObjectsIdType getId()const;
    
    /**
    * @brief
    */  
    Polycode::SceneEntity* getModel()const;

protected:
    //!> Pointer to PolySceneObject helium wrap
    SceneObject* heliumAlife;
    
    int alife;
    
    int    shapeType;
    Number mass;
    Number friction;
    Number restitution;
    int    group;
    bool   compoundChildren;
};

/**
* @brief Helium 3d objects factory interface
*/  
class SceneObjectsFactory {
public:
    /**
    *
    */  
    SceneObjectsFactory () {}
    
    ~SceneObjectsFactory () {}
    
    /**
    * @brief
    * @param id of prepared helium scene objects
    */  
    static PackagedSceneObject& make(int);
private:
};

#endif // HELIUM_SCENE_OBJECTS_INCLUDED

