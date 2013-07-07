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
    virtual ~ListOfAllObjects();
   
	void addCommon( Polycode::PhysicsSceneEntity* );
    void addChar( Polycode::PhysicsCharacter* );

    void addGraphObj( Polycode::ScenePrimitive*);
private:
    std::list< Polycode::ScenePrimitive* >     graphObj;
    
    std::list< Polycode::PhysicsSceneEntity* > phObj;
	std::list< Polycode::PhysicsSceneEntity* > commonObj;
    std::list< Polycode::PhysicsCharacter* >   charObj;
	std::list< Polycode::PhysicsVehicle* >     vehiclesObj; 
    
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
                       ProHeliumGameState* pGameState );
    virtual ~KeyboardUserInput(){};
     
    void handleEvent(Polycode::Event *e);
    
private:
    void mouseKeyUP(Polycode::InputEvent*);
    void mouseKeyDOWN(Polycode::InputEvent*);
    void keyUP(Polycode::InputEvent*);
    void keyDOWN(Polycode::InputEvent*);
    
	Polycode::Core *core;
    ListOfAllObjects* worldObjects;
    ProHeliumGameState* gameState;
};

class ProGameobject
{
public:
    ProGameobject( Polycode::PolycodeView* );
    virtual ~ProGameobject();
    int update();
    
private:
	Polycode::Core *core;
	Polycode::PhysicsScene *scene;
    
    ListOfAllObjects worldobjects;
    KeyboardUserInput keysHandler;
    ProHeliumGameState gameState;

};

