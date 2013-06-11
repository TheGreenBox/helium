/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumMainMenu.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

class I_HeliumMainMenu
{

public:    
    I_HeliumMainMenu();
    virtual ~I_HeliumMainMenu();
    virtual int load()=0;
};


class HeliumMainMenu : public I_HeliumMainMenu
{

public:    
    HeliumMainMenu(){};
    ~I_HeliumMainMenu(){};
    int load(){ return 0; };
};
