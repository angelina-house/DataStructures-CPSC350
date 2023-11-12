/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

Description:
This program serves as the entry point for a game simulation. 
It creates a Game object and initializes the game using input 
parameters from the command line, including the input and output file names.


*/
#include "World.h"
#include "Mario.h"
#include "Game.h"
#include <iostream>

int main(int argc, char *argv[])
{
    // Checks to see if the user entered the correct number of arguments.
    if (argc != 3)
    {
        std::cout << "input and output file not entered\n";
        std::cout << "expected: main <inputfile> <outputfile>\n";
        exit(-1);
    }
    // Creates a game object and passes in the input and output file names.
    std::string charInputFileName(argv[1]);
    std::string charOutputFileName(argv[2]);
    Game game(charInputFileName, charOutputFileName);
}