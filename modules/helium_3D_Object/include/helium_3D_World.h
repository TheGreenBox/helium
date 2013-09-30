/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_3D_World.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_3D_WORLD_INCLUDED
#define  HELIUM_3D_WORLD_INCLUDED

#include "Polycode.h"
#include "Polycode3DPhysics.h"

#include "objectsWorldIntefrace.h"

#include "helium_3D_Character.h"
#include "helium_3D_CharVitals.h"
#include "helium_3D_ObjectPackaging.h"

/**
* @brief contain all 3d objects in HeliumGameObject
*/
class Helium_3D_World : public IHeliumObjectsWorld {
public:

    /**
    * @brief default constrtuctor
    */  
    Helium_3D_World();
    virtual ~Helium_3D_World();
    
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
    * @brief Immediately delete helium scene object from scene and from memory
    * @param Object index
    */
    void signOutObject( Polycode::SceneEntity* );
    
    /**
    * @brief add helium scene object to sceneWorld
    * @param pointer to PackagedSceneObjects, you must to destruct after that
    */  
    Polycode::SceneEntity* addObject( Packaged_3D_Object* );
    
    /**
    * 
    */
    void setCameraHorizonMoving( Polycode::Vector2 dir );
    
    /**
    * @brief warp object to point, if it exist of course
    */
    void warpTo( Polycode::SceneEntity*,
                 Polycode::Vector3, bool resetRotation=true);  

    //!> short name for SceneEntity pointer 
    typedef typename Polycode::SceneEntity* ObjectId;
    
protected:
    Polycode::PhysicsScene* engineScene;
    
private:    
    void engineSceneWarpTo( Polycode::SceneEntity* obj, 
                            Polycode::Vector3 point, 
                            bool resetRotation );
    
    Polycode::RayTestResult rayTest( Polycode::Vector2 );
    inline void cameraStep();
    
    //!> container of char, have reactions and posible have behavior
    HeliumCharacterContainer characters;
    
    Polycode::Vector2 horisontalVectorMove;
};

#endif // HELIUM_3D_WORLD_INCLUDED

