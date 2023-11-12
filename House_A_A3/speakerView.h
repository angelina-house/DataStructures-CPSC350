/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A3

Description:
Creates speaker view constructor and destructor. Also creates FileProcessor method.

*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include <iostream>
#include <fstream>
#include "monoStack.h"
using namespace std;

// Creates speakerView class
class speakerView {
    public:
        speakerView();
        virtual ~speakerView();
        void FileProcessor(string fileName);
};

#endif