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
    void process();
};

struct AddBarrel : public KeyHandler {
    void process();
};

struct AddBoll : public KeyHandler {
    void process();
};

struct XCameraMove : public KeyHandler {
    void process();
};

struct XNegativeCameraMove : public KeyHandler {
    void process();
};

struct YCameraMove : public KeyHandler {
    void process();
};

struct YNegativeCameraMove : public KeyHandler {
    void process();
};

class ProGameObject : public HeliumGameCore {
public:
    ProGameObject( Polycode::Core* );
    virtual ~ProGameObject();
};

