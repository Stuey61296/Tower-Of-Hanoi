// Stuart Barclay 07/01/2019

#include "tower.h"

tower::tower(int poleCount, int nodeCount) : poleCount(poleCount)
{
    this->moveCount = 0;
    // ASCII for 'A'
    char name = 65;
    bool empty = false;
    this->poles = new towerPole *[poleCount];
    this->poles[0] = new towerPole(nodeCount, empty, name++);
    empty = true;
    for (int i = 1; i < poleCount; i++)
        this->poles[i] = new towerPole(nodeCount, empty, name++);
}

// Creates a 2D array to build the tower and then deletes the array when complete
void tower::printTower()
{
    cout << "________________________________________________________________________________\n\n";
    int **tower = new int *[this->poleCount];
    int nodes;
    poleNode *currentNode;
    for (int i = 0; i < poleCount; i++)
    {
        nodes = this->poles[i]->getNodeCount();
        tower[i] = new int[nodes];
        currentNode = this->poles[i]->getPole();
        for (int j = 0; j < nodes; j++)
        {
            tower[i][j] = currentNode->getValue();
            currentNode = currentNode->nextNode;
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        cout << "\t";
        for (int j = 0; j < poleCount; j++)
        {

            if (tower[j][i] == -1)
                cout << "|";
            else
                cout << tower[j][i];
            cout << "\t\t";
        }
        cout << endl;
    }

    cout << "\t";
    for (int j = 0; j < poleCount; j++)
        cout << "_\t\t";
    cout << endl
         << "\t";
    for (int j = 0; j < poleCount; j++)
        cout << this->poles[j]->getPoleName() << "\t\t";
    cout << endl;

    for (int i = 0; i < this->poleCount; ++i)
    {
        delete[] tower[i];
    }
    delete[] tower;
}

tower::~tower()
{
    for (int i = 0; i < poleCount; i++)
    {
        if (this->poles[i] != nullptr)
        {
            this->poles[i]->~towerPole();
            delete poles[i];
        }
    }
    delete[] poles;
    poles = nullptr;
}

void tower::playGame()
{
    this->moveCount = 0;
    while (!gameFinished())
    {
        char poleMoveFrom, poleMoveTo;
        cout << "Which pole would you like to move the top disk from (A - " << this->poles[this->poleCount - 1]->getPoleName() << ")? ";
        cin >> poleMoveFrom;
        cout << "Which pole would you like to move the top disk to (A - " << this->poles[this->poleCount - 1]->getPoleName() << ")? ";
        cin >> poleMoveTo;
        if (!this->poles[toupper(poleMoveFrom) - 65]->reallocatePole(this->poles[(toupper(poleMoveTo) - 65)]))
        {
            cout << "Invalid move!\n";
            this->printTower();
            continue;
        }
        ++this->moveCount;
        cout << "\n";
        this->printTower();
    }
    cout << "________________________________________________________________________________\n\t\tCongratulations! Game completed in " << this->moveCount << " moves.\n________________________________________________________________________________";
}

bool tower::gameFinished()
{
    poleNode *lastPole = this->poles[this->poleCount - 1]->getPole();
    while (lastPole)
    {
        if (lastPole->getValue() == -1)
            return false;
        lastPole = lastPole->nextNode;
    }
    return true;
}