/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    heliumObjectsWorldIntefrace.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_OBJECTS_WORLD_INTEFRACE_INCLUDED 
#define  HELIUM_OBJECTS_WORLD_INTEFRACE_INCLUDED 

#include <Polycode.h>

/**
* @brief Interface for the different Helium Object Worlds
*        pure virtual class
*/
class IHeliumObjectsWorld {
public:
    
    /**
    * @brief Step of behavior in game main loop
    */
    virtual void lifeStep()=0;

    /**
    * @brief Method that will be call when mouse click event was occured
    * @param button - number of mouse button [0,1,2]
    * @param upDown - pushed down the button - false, realised the button - true
    * @param position - screen coords that have mouse cursor when event was occured
    */
    virtual bool mouseClick( int button, bool upDown, Polycode::Vector2 position )=0;
    
    /**
    * @brief Temporaly swithched off the world and not render it
    * @param [ true-pause, false-work ]
    */
    virtual void setPause(bool)=0;
    
    /**
    * @brief Check pause state of object world
    */
    virtual bool getPause()=0;
};

#endif // HELIUM_OBJECTS_WORLD_INTEFRACE_INCLUDED 
 
