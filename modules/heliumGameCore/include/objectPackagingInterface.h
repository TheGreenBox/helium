/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumObjectPackagingInterface.h 
 * Description:
 * Author:       
 * ========================================================
 */
#ifndef  HELIUM_OBJECTS_PACKAGING_INCLUDED 
#define  HELIUM_OBJECTS_PACKAGING_INCLUDED 

#include <Polycode.h>

/**
* @brief Interface for the different Helium Object packaging
*        pure virtual class
*/
class IHeliumPackaging {
public:
    
    virtual ~IHeliumPackaging (){}
    
    typedef enum {
        ENTITY_IMMATERIAL,
        ENTITY_COLLISION_ONLY,
        ENTITY_PHYSICAL,     
        ENTITY_EMPTY
    } ObjectEntityType;
    
    virtual ObjectEntityType getEntityType()const=0;
    
    virtual int getShapeType()const=0;
};

#endif // HELIUM_OBJECTS_PACKAGING_INCLUDED 

