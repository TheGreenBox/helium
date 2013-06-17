/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  heliumCore.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */


#include <Polycode.h>
#include "PolycodeView.h"

#include "heliumGameCore.h"

class I_HeliumCore
{
public:
    
    /**
    * Constructor
    * @param nil
    */
    virtual I_HeliumCore( Polycode::PolycodeView* view );
    
    /**
    * Destructor
    * @param nil
    */
    virtual ~I_HeliumCore();
    
    /**
    * 
    * @param nil
    */
    virtual void loop()=0;

};


class HeliumCore : public I_HeliumCore
{
public:
    
    /**
    * Constructor
    * @param nil
    */
    HeliumCore( Polycode::PolycodeView* view );
    
    /**
    * Destructor
    * @param nil
    */
    ~HeliumCore();
    
    void loop();
    
private:
	Polycode::Core* engineCore;
    
    I_HeliumMainMenu* menu;    
    HeliumGameCore* gameCore;
};

