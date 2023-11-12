/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

Description:
This program defines the World class, which represents 
the game world in a game simulation. The World class generates 
and manages the game world, including levels, grid size, and item distribution.

*/
#include "World.h"
#include "Mario.h"
#include <iostream>
#include <cstdlib>

World::~World()
{
    delete[] genWorld;
}
// Constructor for the world.
World::World(int numberOfLevels, int gridSize, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms)
{
    mGrideSize = gridSize;
    mNumOfLevels = numberOfLevels;
    // Creates a 3D array of the world.
    genWorld = new char[numberOfLevels * gridSize * gridSize];
    for (int h = 0; h < numberOfLevels; ++h)
    {
        for (int i = 0; i < gridSize; ++i)
        {
            for (int j = 0; j < gridSize; ++j)
            {
                int randomlyDispurseEnemies = rand() % 100;
                if (randomlyDispurseEnemies < percentNothing)
                {
                    setAt(h, i, j, 'x');
                }
                else if (randomlyDispurseEnemies < (percentMushrooms + percentNothing))
                {
                    setAt(h, i, j, 'm');
                }
                else if (randomlyDispurseEnemies < (percentCoins + percentMushrooms + percentNothing))
                {
                    setAt(h, i, j, 'c');
                }
                else if (randomlyDispurseEnemies < (percentGoombas + percentCoins + percentMushrooms + percentNothing))
                {
                    setAt(h, i, j, 'g');
                }
                else if (randomlyDispurseEnemies < (percentKoopas + percentGoombas + percentCoins + percentMushrooms + percentNothing))
                {
                    setAt(h, i, j, 'k');
                }
            }
        }
        if (h < numberOfLevels - 1)
        {
            int warpCoordX = rand() % gridSize;
            int warpCoordY = rand() % gridSize;
            setAt(h, warpCoordX, warpCoordY, 'w');
        }
        int bossCoordX = rand() % gridSize;
        int bossCoordY = rand() % gridSize;
        setAt(h, bossCoordX, bossCoordY, 'b');
    }
}
// Returns the size of the grid.
int World::getNumOfLevels()
{
    return mNumOfLevels;
}

char World::getAt(int level, int row, int col)
{
   
    int position = level * (mGrideSize * mGrideSize) + row * mGrideSize + col;
    return genWorld[position];
}

void World::setAt(int level, int row, int col, char c)
{

    int position = level * (mGrideSize * mGrideSize) + row * mGrideSize + col;
    genWorld[position] = c;
}

void World::printLevel(int level)
{
    std::cout << "Level: " << level << std::endl;
    for (int i = 0; i < mGrideSize; ++i)
    {
        for (int j = 0; j < mGrideSize; ++j)
        {
            std::cout << getAt(level, i, j) << " ";
        }
        std::cout << "\n";
    }
    
    std::cout << std::endl;
}

void World::printWorld()
{
    for (int level = 0; level < mNumOfLevels; ++level)
    {
        printLevel(level);
    }
}

int World::getGridSize()
{
    return mGrideSize;
}
