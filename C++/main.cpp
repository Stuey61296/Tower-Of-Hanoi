// Stuart Barclay 07/01/2019

#include "tower.h"
#include <math.h>

using namespace std;

int main()
{
    int poleCounter;
    int diskCounter;
    cout << "-----------------------------------------------------------------\n\t\t\tTower of Hanoi\n-----------------------------------------------------------------\n\n";
    cout << "Game details:\tThe objective of this game is to\nmove the disks(in this case numbers) from pole A\nto the end pole. In this version a disk may be moved to any pole.\nDisks with larger numbers may not sit ontop of disks with\nsmaller numbers. A maximum of 5 poles may be used\nand a minimum of 3 poles may be used. A minimum of 2 disks may be used.\n------------------------------------------------------------------\n";
    cout << "How many poles would you like to have? ";
    cin >> poleCounter;
    cout << "How many disks would you like to have? ";
    cin >> diskCounter;
    if (poleCounter > 5)
        poleCounter = 5;
    if (poleCounter < 3)
        poleCounter = 3;
    if (diskCounter < 2)
        diskCounter = 2;
    tower *toh = new tower(int(poleCounter), int(diskCounter));
    toh->printTower();
    if (poleCounter == 3)
        cout << "Minimum moves to complete game: " << (pow(2, diskCounter) - 1) << endl;
    toh->playGame();
    delete toh;
    return 0;
}