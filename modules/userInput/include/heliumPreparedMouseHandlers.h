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

class CameraHorisontalMove : public MouseKeyHandler {
public:
    CameraHorisontalMove();
    virtual ~CameraHorisontalMove();
    void process(Polycode::Vector2 mousePosition);

    static int speed;
};

#endif   // HELIUM_PREPARED_MOUSE_HANDLERS_INCLUDED

