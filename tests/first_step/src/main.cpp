/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  first_step_main.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */

#include <iostream> 
#include "Polycode.h"
#include "PolycodeView.h"

int main (int argsNum, char** argAr)
{
    std::cout << "The arguments to " << argAr[0] <<  "are:\n";
    for (int i = 1; i < argsNum; i++)
    {
        std::cout << i << " : " << argAr[i] << "\n";
    }
	ScreenImage *image;
	Core core;
	core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);
	Number elapsed = core->getElapsed();
	Screen *screen = new Screen();			
	image = new ScreenImage("Resources/polycode_logo.png");
	screen->addChild(image);	
    return 0;
}
