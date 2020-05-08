// Stuart Barclay 07/01/2019
#ifndef tower_H
#define tower_H

#include "towerPole.h"
class tower
{
    int poleCount;
    towerPole **poles;
    int moveCount;

public:
    // Constructor
    tower(int poleCount, int nodeCount);
    // Destructor
    ~tower();
    // Prints the shape of the tower
    void printTower();
    // Interface for playing the game
    void playGame();
    // Checks the completion of the game
    bool gameFinished();
};

#endif