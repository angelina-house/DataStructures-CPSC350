/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

Description:
This header file defines the Mario class, which represents the main character 
in a game simulation. Mario can interact with the game world, collect items, 
and perform various actions.

*/
#ifndef MARIO_H
#define MARIO_H

#include <ostream>
#include "World.h"

enum MarioDirection //enum for Mario's direction
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    noMvmt = 4
};
class Mario   
{
public:
    Mario();
    ~Mario();
    Mario(int numofLives);
    void coinLife();
    void setCoins(int coins);
    void setPowerLevel(int powerLevel);
    void setLives(int lives);
    int getPowerLevel();
    int getNumOfLives();
    int getNumOfMoves();
    bool isAlive();
    bool hasPrincess(World &World);
    void move(World &world, MarioDirection direction);
    MarioDirection takeAction(std::ostream &outputStream, World &world);
    MarioDirection getRandomDirection();
    void start(World &world);
    void printCoords(std::ostream &outputStream);
    int getNumOfCoins();
    int getCurrentLevel();
    void getCurrentCol();
    void getCurrentRow();
    void printLevel(std::ostream &outputStream, World &world);

    void incrementNumOfEnemiesDefeated();
    void incrementPowerLevel();
    void decrementPowerLevel();
    void decrementBossPowerLevel();
    void incrementCurrentLevel();
    int mNumOfLives;
    int mNumOfCoins;
    int mPowerLevel;
    int mCurrentLevel;
    int mCurrentRow;
    int mCurrentCol;
    int mNumOfMoves;
    int mNumOfEnemiesDefeated;
};

#endif
