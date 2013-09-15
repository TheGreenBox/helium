/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumPreparedMouseHandlers.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_PREPARED_MOUSE_HANDLERS_INCLUDED
#define  HELIUM_PREPARED_MOUSE_HANDLERS_INCLUDED 

#include <Polycode.h>

#include "heliumUserInputHandler.h"

struct CameraHorisontalMove : public MouseKeyHandler {
public:
    CameraHorisontalMove();
    virtual ~CameraHorisontalMove();
    void process(Polycode::Vector2 mousePosition);

    static int speed;
};

struct SceneObjectHorTransfer : public MouseKeyHandler {
    SceneObjectHorTransfer(Polycode::SceneEntity*);
    virtual ~SceneObjectHorTransfer();
    void process(Polycode::Vector2 mousePosition);

    Polycode::SceneEntity* model;
};

#endif   // HELIUM_PREPARED_MOUSE_HANDLERS_INCLUDED

