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

#include <Polycode.h>

#include "heliumScreenConsole.h"

class FlatLifelessObject {
public:
    FlatLifelessObject(Polycode::ScreenEntity*);
    virtual ~FlatLifelessObject() {}
    Polycode::ScreenEntity* getModel();

protected:
    Polycode::ScreenEntity* model;
};

class FlatAlifeObject : public FlatLifelessObject {
public:
    FlatAlifeObject(Polycode::ScreenEntity*);
    virtual ~FlatAlifeObject() {}
    
    virtual void lifeStep()=0;
    virtual void mouseCursor()=0;
    virtual void mouseClick()=0;
    virtual void mouseDoubleClick()=0;
};

class ScreenObjects {
public:
    ScreenObjects();
    virtual ~ScreenObjects();
    
    void addAlifeObject( FlatAlifeObject* );
    
    void addLifelessObject( FlatLifelessObject* );
    
    void lifeStep();
    
    Polycode::Screen* getEngineScreenPt() { 
        return engineScreen;
    }

private:
    Polycode::Screen* engineScreen;   
    std::list< FlatLifelessObject* > lifelessObjects;
    std::list< FlatAlifeObject* >    aliveObjects;
};

#endif // HELIUM_SCREEN_OJECTS_INCLUDED

