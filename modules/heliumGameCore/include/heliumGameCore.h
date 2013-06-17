/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  ../include/heliumGameCore.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <Polycode.h>
#include "PolycodeView.h"

class HeliumGameCore
{
public:    
    HeliumGameCore(Polycode::Core* );
    virtual ~HeliumGameCore();
    int game();
    
private:
	Polycode::Core* engineCore;
};

