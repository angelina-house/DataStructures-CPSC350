/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A3

Description: 
Main method. Creates an instance of speakerView and calls the FileProcessor method.
*/

#include "monoStack.h"
#include "speakerView.h"
#include <iostream>
#include <string>
using namespace std;
int main (int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./speakerView <input file>" << endl;
        return 1;
    }
    speakerView sp;
    sp.FileProcessor(argv[1]);
    return 0;

}