/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

Description:
This program defines the World class, which represents the 
\game world in a game simulation. The World class manages 
the game world's levels, grid size, and item distribution.


*/
#ifndef LEVEL_H
#define LEVEL_H

class World
{
public:
    ~World();
    World();

    World(int numberOfLevels, int gridSize, int percentCoins, int percentNothing, int percentGoombas, int percentKoopas, int percentMushrooms);
    int getNumOfLevels();
    char getAt(int level, int row, int col);
    void setAt(int level, int row, int col, char c);
    void printLevel(int level);
    void printWorld();
    int getGridSize();

    char *genWorld;
    int mNumOfLevels;
    int mGrideSize;
};

#endif