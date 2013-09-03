/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumScreenObjects/include/heliumScreenOjects.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef HELIUM_SCREEN_OJECTS_INCLUDED
#define HELIUM_SCREEN_OJECTS_INCLUDED

#include <list>
#include <Polycode.h>
#include <PolyPhysicsScreen.h>

class ScreenObject {
public:
    ScreenObject(Polycode::ScreenEntity*);
    virtual ~ScreenObject() {}
    Polycode::ScreenEntity* getModel();

protected:
    Polycode::ScreenEntity* model;
};

class AlifeScreenObject : public ScreenObject {
public:
    AlifeScreenObject(Polycode::ScreenEntity*);
    virtual ~AlifeScreenObject() {}
    
    virtual void lifeStep()=0;
    virtual void mouseCursor()=0;
    virtual void mouseClick( bool upDown )=0;
    virtual void mouseDoubleClick()=0;
};

class ScreenObjectsWorld {
public:
    ScreenObjectsWorld();
    virtual ~ScreenObjectsWorld();
    
    void addObject( ScreenObject* );
    void signOutObject( ScreenObject* );
    
    void addAlifeObject( AlifeScreenObject* );
    
    void lifeStep();

    bool mouseClick( int button, bool upDown, Polycode::Vector2 position );
    
    void setPause(bool);
    bool getPause();
    
    Polycode::Screen* getEngineScreenPt() { 
        return engineScreen;
    }

private:
    AlifeScreenObject* getAlifeObject( Polycode::ScreenEntity* );
    Polycode::PhysicsScreen* engineScreen;   
    std::list< ScreenObject* >      objects;
    std::list< AlifeScreenObject* > aliveObjects;
};

#endif // HELIUM_SCREEN_OJECTS_INCLUDED

