/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

Description:
This program reads input data from a file and simulates a game using the provided parameters, 
such as grid size, percentage of coins, and character attributes. It then outputs game progress 
to the console or a specified output file.

*/
#include <cstdlib>
#include <ostream>
#include <fstream>
#include "Game.h"

Game::~Game() {}

Game::Game(std::string file, std::string outputFile)
{

    std::string fileString;
    std::ifstream MyReadFile(file);

    int numberOfLevels = 2;
    int gridSize = 5;
    int numberOfLives = 3;
    int percentCoins = 20;
    int percentNothing = 20;
    int percentGoomba = 20;
    int percentKoopa = 20;
    int percentMushroom = 20;
    int counter = 0;
    int keepLevel = 0;

    std::ofstream passedInOutputFile;
    if (outputFile.empty() == false)
    {
        passedInOutputFile.open(outputFile);
    }

    std::ostream &outputStream = passedInOutputFile.is_open() ? passedInOutputFile : std::cout;

    // Read from the text file
    while (getline(MyReadFile, fileString))
    {
        if (counter == 0) //number of levels
        {
            numberOfLevels = stoi(fileString);
            counter++;
        }
        else if (counter == 1) //dimension of grid
        {
            gridSize = stoi(fileString);
            counter++;
        }
        else if (counter == 2) //initial number of lives
        {
            numberOfLives = stoi(fileString);
            counter++;
        }
        else if (counter == 3) //percent of coins
        {
            percentCoins = stoi(fileString);
            counter++;
        }
        else if (counter == 4) //percent of nothing
        {
            counter++;
            percentNothing = stoi(fileString);
        }
        else if (counter == 5) //percent of goomba
        {
            counter++;
            percentGoomba = stoi(fileString);
        }
        else if (counter == 6) //percent of koopa
        {
            counter++;
            percentKoopa = stoi(fileString);
        }
        else if (counter == 7) //percent of mushroom
        {
            counter++;
            percentMushroom = stoi(fileString);
        }
    }
    
    srand(time(NULL));
    World world(numberOfLevels, gridSize, percentCoins, percentNothing, percentGoomba, percentKoopa, percentMushroom);
    Mario mario(numberOfLives);
    std::string pause;

    // START WORLD
    mario.start(world);

    // GAME LOOP
    while (mario.isAlive() == true && mario.hasPrincess(world) == false)
    {
        outputStream << "Level: " << mario.getCurrentLevel() << std::endl;
        mario.printCoords(outputStream);
        outputStream << "Power Level: " << mario.getPowerLevel() << std::endl;
        MarioDirection direction = mario.takeAction(outputStream, world);
        outputStream << "Number of lives: " << mario.getNumOfLives() << std::endl;
        outputStream << "Number of Coins: " << mario.getNumOfCoins() << std::endl;
        if (direction == 0)
        {
            outputStream << "Next move: up\n";
        }
        else if (direction == 1)
        {
            outputStream << "Next move: down\n";
        }
        else if (direction == 2)
        {
            outputStream << "Next move: left\n";
        }
        else if (direction == 3)
        {
            outputStream << "Next move: right\n";
        }
        else if (direction == 4)
        {
            outputStream << "Next move: no movement \n";
        }
        if (mario.getCurrentLevel() != numberOfLevels)
            mario.printLevel(outputStream, world);
            outputStream << "---------------------------------------\n\n";
            
        mario.move(world, direction);
    }

}