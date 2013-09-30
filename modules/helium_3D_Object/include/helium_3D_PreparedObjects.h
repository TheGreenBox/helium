/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    helium_3D_PreparedObjects.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_PREPARED_3D_OBJECTS_INCLUDED
#define HELIUM_PREPARED_3D_OBJECTS_INCLUDED

#include "helium_3D_Character.h"
#include "helium_3D_ObjectPackaging.h"

typedef enum {
    PREPARED_3D_UNKNOWN = 0,
    PREPARED_3D_HELIUM_556_BULLET_BOX = 1,
    PREPARED_3D_LAST
} HeliumPreparedSceneObjects; 


struct HeliumTestBarrel : public Packaged_3D_Object {
    HeliumTestBarrel( double radius, double hight,
                      double position_x, double position_z, double position_y);
    ~HeliumTestBarrel() {}
};

struct HeliumTestFloor : public Packaged_3D_Object {
    HeliumTestFloor( double size_x, double size_y );
    ~HeliumTestFloor() {}
};

struct HeliumTestBox : public Packaged_3D_Object {
    HeliumTestBox( double size_x, double size_y, double size_z,
                   double pos_x, double pos_y, double pos_z ); 
    ~HeliumTestBox() {}
};

struct Helium556BulletBox : public Packaged_3D_Object {
    Helium556BulletBox( double pos_x, double pos_y, double pos_z, double size );
};

class HeliumSceneArchitecktHand : public HeliumCharacter {
public:
    
    /**
    * @brief Create null hand and if click - > object will be picked up from the scene
    */
    HeliumSceneArchitecktHand(Polycode::SceneEntity*);
    
    ~HeliumSceneArchitecktHand();

    void lifeStep();
    
    /**
    * @brief
    */  
    void mousePoint( int button, bool upDown, Polycode::Vector2 mouse );
    
    /**
    * @brief
    */  
    void mouseDoubleClick();
    
private:
    Polycode::SceneEntity*  creatingObject;
    
};

class HeliumSceneArchitecktHandPack : public Packaged_3D_Object {
public:
    HeliumSceneArchitecktHandPack( Polycode::SceneEntity* );
    ~HeliumSceneArchitecktHandPack();
};

#endif // HELIUM_PREPARED_3D_OBJECTS_INCLUDED

