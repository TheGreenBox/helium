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
    PREPARED_3D_LAST
} HeliumPrepared3D; 


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

#endif // HELIUM_PREPARED_3D_OBJECTS_INCLUDED

