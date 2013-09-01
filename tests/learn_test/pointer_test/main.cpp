using namespace std;

#include <iostream>
#include "init.h"

int playWithString(char** strPointer) {
    return 0;
}

void printArray(int numberOfArguments, char** stringArray) {
    for (int index = 0; index < numberOfArguments; ++index) {
        std::cout << "Arg #" << index << ": " << stringArray[index] << "\n";
    }
    return;
}

void swapFirstAndLastElements(int arraySize, char** stringArray) {
    char* temp = stringArray[arraySize - 1];
    stringArray[arraySize - 1] = stringArray[0];
    stringArray[0] = temp;
    return;
}

/**
* @param int argsNum - number of cmd input arguments
* @param char** argAr - array of input string
*/
int main(int argsNum, char** argAr) {
    printArray(argsNum, argAr);
    swapFirstAndLastElements(argsNum, argAr);
    std::cout << "\nAfter swap:\n";
    printArray(argsNum, argAr);
    return 0;
}
