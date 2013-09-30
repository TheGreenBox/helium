/* ========================================================
 * Organization: The Green Box
 *
 * Project name: Helium
 * File name:    heliumPrepared_2D_Button.h
 * Description:
 * Author:       AKindyakov
 * ========================================================
 */
#ifndef  HELIUM_PREPARED__2D__BUTTON_INCLUDED
#define  HELIUM_PREPARED__2D__BUTTON_INCLUDED

#include "Polycode.h"
#include "helium_2D_Button.h"
#include "helium_2D_ObjectPackaging.h"

namespace P = Polycode;

class HeliumGameCore;

struct HeliumPause_2D_Button : public Packaged_2D_Object {
    HeliumPause_2D_Button ( HeliumGameCore* gm );
    virtual ~HeliumPause_2D_Button ();
};

struct HeliumExit_2D_Button : public Packaged_2D_Object {
    HeliumExit_2D_Button ( HeliumGameCore* gm );
    virtual ~HeliumExit_2D_Button();
};

struct HeliumText_2D_Button : public Packaged_2D_Object {
    HeliumText_2D_Button ( HeliumGameCore* gm, P::String textValue, 
                           KeyHandler* buttonHandler, 
                           int b_x_size, int b_y_size, 
                           int x_pos, int y_pos, 
                           P::String font, int t_size );
    
    virtual ~HeliumText_2D_Button();
};


#endif // HELIUM_PREPARED__2D__BUTTON_INCLUDED

