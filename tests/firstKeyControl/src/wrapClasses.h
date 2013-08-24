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
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"

#include "heliumGameCore.h"
#include "heliumSceneObjects.h"
#include "heliumScreenConsole.h"

#include "heliumUserInput.h"

class ProGameObject;

struct AddDice : public KeyHandler {
    void process(HeliumGameCore*);
};

struct AddBarrel : public KeyHandler {
    void process(HeliumGameCore*);
};

struct AddBoll : public KeyHandler {
    void process(HeliumGameCore*);
};

struct XCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

struct XNegativeCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

struct YCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

struct YNegativeCameraMove : public KeyHandler {
    void process(HeliumGameCore*);
};

class ProGameObject : public HeliumGameCore {
public:
    ProGameObject( Polycode::Core* );
    virtual ~ProGameObject();
    
private:
    KeyboardUserInput* keysHandler;
};

