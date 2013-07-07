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

#include <Polycode.h>
#include "Polycode3DPhysics.h"

class ListOfAllObjects
{
public:
	
    ListOfAllObjects(){};
    virtual ~ListOfAllObjects(){};
    
    void addCommon( Polycode::SceneEntity *entity, 
                    Number mass, 
                    Number friction, 
                    Number stepSize ){};
    
    void addChar( Polycode::SceneEntity *entity,
                  int type, 
                  Number mass, 
                  Number friction, 
                  Number restitution, 
                  bool compoundChildren = false ){};
    
	void addCommon( Polycode::PhysicsSceneEntity ){};
    void addChar( Polycode::PhysicsCharacter ){};

private:
    std::list< Polycode::PhysicsSceneEntity* > allObj;
	std::list< Polycode::PhysicsSceneEntity >  commonObj;
    std::list< Polycode::PhysicsCharacter >    charObj;
	std::list< Polycode::PhysicsVehicle >      vehiclesObj; 
    
};

class KeyboardUserInput
{
public:
    KeyboardUserInput( ListOfAllObjects* ){};
    virtual ~KeyboardUserInput(){};
    
private:
    ListOfAllObjects* worldObjects;
};

class ProGameobject
{
public:
    ProGameobject()
        : keysHandler(&worldobjects) {};
    virtual ~ProGameobject(){};
    
private:
    ListOfAllObjects worldobjects;
    KeyboardUserInput keysHandler;
};

