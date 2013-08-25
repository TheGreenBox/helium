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
#include "heliumScreenObjects.h"

#include "heliumUserInput.h"

class ProGameObject;

struct AddDice : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct AddBarrel : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct AddBoll : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct XCameraMove : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct XNegativeCameraMove : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct YCameraMove : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

struct YNegativeCameraMove : public KeyHandler {
    void process(HeliumGameCoreObjects*);
};

class ProGameObject : public HeliumGameCore {
public:
    ProGameObject( Polycode::Core* );
    virtual ~ProGameObject();
};

