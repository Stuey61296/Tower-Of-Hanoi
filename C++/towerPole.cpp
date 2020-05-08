// Stuart Barclay 07/01/2019

#include "towerPole.h"

// Initialise Pole
towerPole::towerPole(int nodeCount, bool empty, char name) : poleName(name), nodeCount(nodeCount)
{
    this->poleHead = new poleNode();
    poleNode *currentNode = this->poleHead;
    if (!empty)
    {
        for (int i = 1; i <= this->nodeCount; i++)
        {
            currentNode->setValue(i);
            if (i != this->nodeCount)
            {
                currentNode->nextNode = new poleNode();
                currentNode = currentNode->nextNode;
            }
            else
            {
                currentNode->nextNode = nullptr;
            }
        }
    }
    else
    {
        for (int i = 1; i <= this->nodeCount; i++)
        {
            currentNode->setValue(-1);
            if (i != this->nodeCount)
            {
                currentNode->nextNode = new poleNode();
                currentNode = currentNode->nextNode;
            }
            else
            {
                currentNode->nextNode = nullptr;
            }
        }
    }
}

poleNode *towerPole::getPole()
{
    return this->poleHead;
}

bool towerPole::reallocatePole(towerPole *newPole)
{
    poleNode *currentNode = this->poleHead;
    poleNode *newPoleNode = newPole->poleHead;
    poleNode *newPoleNodeCopy = newPole->poleHead;
    int key, testKey;
    while (currentNode)
    {
        newPoleNodeCopy = newPole->poleHead;
        testKey = -1;
        key = currentNode->getValue();
        while (newPoleNodeCopy)
        {
            if (newPoleNodeCopy->getValue() != -1)
            {
                testKey = newPoleNodeCopy->getValue();
                break;
            }
            newPoleNodeCopy = newPoleNodeCopy->nextNode;
        }
        if (key != -1 && (testKey > key || testKey == -1))
        {
            newPoleNode->setValue(key);
            currentNode->setValue(-1);
            return true;
        }
        currentNode = currentNode->nextNode;
        newPoleNode = newPoleNode->nextNode;
    }
    return false;
}

towerPole::~towerPole()
{
    recDel(this->poleHead);
    poleHead = nullptr;
}

void towerPole::recDel(poleNode *currentNode)
{
    if (currentNode != nullptr)
        recDel(currentNode->nextNode);
    delete currentNode;
}

int towerPole::getNodeCount()
{
    return this->nodeCount;
}

char towerPole::getPoleName()
{
    return this->poleName;
}