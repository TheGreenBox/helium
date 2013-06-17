/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumMainMenu.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#ifndef _HELIUM_MAIN_MENU_INCLUDED_
#define _HELIUM_MAIN_MENU_INCLUDED_

#include <Polycode.h>
#include "heliumGameCore.h"

class I_HeliumMainMenu
{

public:    
    I_HeliumMainMenu(){};
    virtual ~I_HeliumMainMenu(){};
    virtual int load( HeliumGameCore* game )=0;
};


class HeliumMainMenu : public I_HeliumMainMenu
{

public:    
    HeliumMainMenu(Polycode::Core* engineCore);
    virtual ~HeliumMainMenu();
    
    int load( HeliumGameCore* game );

private:
    Polycode::Core* engineCore;
};

#endif // _HELIUM_MAIN_MENU_INCLUDED_

