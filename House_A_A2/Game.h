/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

Description:
This program represents a game simulation that uses the Mario and World classes to simulate gameplay. 
The Game class serves as the entry point for running the game and managing game parameters.

*/

#include "Mario.h"
#include "World.h"
#include <fstream>
#include <iostream>

class Game
{
public:
    // Default constructor
    Game();

    // Destructor
    ~Game();

    /*
    Constructor for the Game class that initializes a game instance based on input parameters.

    Parameters:
    - file: A string containing the name of the input file to read game parameters from.
    - outputFile: A string containing the name of the output file to write game progress to.
    */
    Game(std::string file, std::string outputFile);
};
