/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  firstTestClass.h 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */
#include <Polycode.h>
#include "PolycodeView.h"

using namespace Polycode;

class FirstStepTest {
public:
 	FirstStepTest(PolycodeView *view);
 	~FirstStepTest();
    
	bool Update();
    
private:

	ScreenImage *image;
	Core *core;
};
