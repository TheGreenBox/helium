/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
  File name:  wrapClasses.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <list>
#include <map>

#include <Polycode.h>
#include "PolycodeView.h"
#include "PolyCollisionScene.h"
#include "Polycode3DPhysics.h"

class Helium3DModel
{
public:
	
    Helium3DModel( Polycode::Mesh* pmh );
    virtual ~Helium3DModel();
    
private:
    
};

class HeliumPhysical3DModel
{
public:
	
    HeliumPhysical3DModel( Polycode::Mesh* pmh );
    virtual ~HeliumPhysical3DModel();
    
private:
    
};

