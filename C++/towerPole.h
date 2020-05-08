// Stuart Barclay 07/01/2019
#ifndef towerPole_H
#define towerPole_H

#include "poleNode.h"
#include <iostream>

using namespace std;

struct towerPole
{
private:
    poleNode *poleHead;
    char poleName;
    int nodeCount;

public:
    // Initialise Pole + Constructor
    towerPole(int nodeCount, bool empty, char name);
    // Destructor
    ~towerPole();
    // Return Pole
    poleNode *getPole();
    // Move values in pole to other poles,
    bool reallocatePole(towerPole *newPole);
    // Recursively delete nodes
    void recDel(poleNode *currentNode);
    // Returns node count
    int getNodeCount();
    // Returns Pole Name
    char getPoleName();
};

#endif