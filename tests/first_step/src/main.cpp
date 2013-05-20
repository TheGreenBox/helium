/* ========================================================
 * Organization: The Green Box
 * 
 * Project name: Helium
 * File name:  first_step_main.cpp 
 * Description:
 * Author:  AKindyakov 
 * ========================================================
 */


int main (int argsNum, char** argAr)
{
    std::cout << "The arguments to " << pszArgs[0] <<  "are:\n";
    for (int i = 1; i < nNumberofArgs; i++)
    {
        std::cout << i << " : " << pszArgs[i] << "\n";
    }
    return 0;
}
