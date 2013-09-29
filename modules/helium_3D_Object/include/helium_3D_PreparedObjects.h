/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumPrepared3DObjects.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_PREPARED_3D_OBJECTS_INCLUDED
#define HELIUM_PREPARED_3D_OBJECTS_INCLUDED

#include "heliumSceneObjects.h"

typedef enum {
    PREPARED_3D_UNKNOWN = 0,
    PREPARED_3D_HELIUM_556_BULLET_BOX = 1,
    PREPARED_3D_LAST
} HeliumPreparedSceneObjects; 


struct HeliumTestBarrel : public PackagedSceneObject {
    HeliumTestBarrel( double radius, double hight,
                      double position_x, double position_z, double position_y);
    ~HeliumTestBarrel() {}
};

struct HeliumTestFloor : public PackagedSceneObject {
    HeliumTestFloor( double size_x, double size_y );
    ~HeliumTestFloor() {}
};

struct HeliumTestBox : public PackagedSceneObject {
    HeliumTestBox( double size_x, double size_y, double size_z,
                   double pos_x, double pos_y, double pos_z ); 
    ~HeliumTestBox() {}
};

struct Helium556BulletBox : public PackagedSceneObject {
    Helium556BulletBox( double pos_x, double pos_y, double pos_z, double size );
};

class HeliumSceneArchitecktHand : public SceneObject {
public:
    
    /**
    * @brief Create null hand and if click - > object will be picked up from the scene
    */
    HeliumSceneArchitecktHand(IHeliumObjectsWorld::ObjectsIdType id=0);
    
    
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
    IHeliumObjectsWorld::ObjectsIdType creatingObject;
    
};

class HeliumSceneArchitecktHandPack : public PackagedSceneObject {
public:

    HeliumSceneArchitecktHandPack( IHeliumObjectsWorld::ObjectsIdType id=0);
    
    ~HeliumSceneArchitecktHandPack();
};

#endif // HELIUM_PREPARED_3D_OBJECTS_INCLUDED

