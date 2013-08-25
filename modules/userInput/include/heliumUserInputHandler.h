/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:    modules/userInput/include/heliumUserInputHandler.h 
 * Description:
 * Author:       AKindyakov 
 * ========================================================
 */
#ifndef  HELIUM_USER_INPUT_HANDLER_INCLUDED
#define  HELIUM_USER_INPUT_HANDLER_INCLUDED

class KeyHandler {
public:
    KeyHandler(){};
    virtual ~KeyHandler(){};
    virtual void process(HeliumGameCoreObjects*)=0;
};

#endif // HELIUM_USER_INPUT_HANDLER_INCLUDED

