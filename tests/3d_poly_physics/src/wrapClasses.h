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
    std::list< Polycode::ScenePrimitive* >     graphObj;
    
    std::list< Polycode::PhysicsSceneEntity* > allObj;
	std::list< Polycode::PhysicsSceneEntity >  commonObj;
    std::list< Polycode::PhysicsCharacter >    charObj;
	std::list< Polycode::PhysicsVehicle >      vehiclesObj; 
    
};

struct ProHeliumGameState
{
    std::list<Polycode::PolyKEY> clampedKeys; 
    std::list<Polycode::PhysicsSceneEntity*> highlightingObjects; 
    ListOfAllObjects *worldobjects;
};


class KeyboardUserInput
{
public:
    KeyboardUserInput( Polycode::Core *engCore,
                       ListOfAllObjects*   pallObj,
                       ProHeliumGameState* pGameState ){};
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event *e);
    
private:
    void mouseKeyUP(Polycode::InputEvent*);
    void mouseKeyDOWN(Polycode::InputEvent*);
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
	Polycode::Core *core;
    ListOfAllObjects* worldObjects;
};

class ProGameobject
{
public:
    ProGameobject( Polycode::PolycodeView* );
    virtual ~ProGameobject();
    int Update(){};
    
private:
	Polycode::Core *core;
	Polycode::PhysicsScene *scene;
    
    ListOfAllObjects worldobjects;
    KeyboardUserInput keysHandler;
    ProHeliumGameState gameState;

};

