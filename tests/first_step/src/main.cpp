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
#include "firstTestClass.h"

int main (int argsNum, char** argAr)
{
    std::cout << "The arguments to " << argAr[0] <<  "are:\n";
    for (int i = 1; i < argsNum; i++)
    {
        std::cout << i << " : " << argAr[i] << "\n";
    }
    
    return 0;
}
