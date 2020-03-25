#include "Arena.h"
#include "Cell.h"
#include <iostream>
using namespace std;
Arena::Arena(int x,int y, int z)
{
    dimX = x;
    dimY = y;
    dimZ = z;
    //ctor

}
// Create 3D array dynamically with type "Cell"
void Arena::create3DArray()
{

    cellArray = new Cell ***[dimX];
    for (int i = 0; i < dimX; i++)
    {
        cellArray[i] = new Cell **[dimY];
        for (int j = 0; j < dimY; j++)
        {
            cellArray[i][j] = new Cell *[dimZ];
        }
    }
}

// Fills array with "Cell" Objects
void Arena::fill3DArray()
{

    for (int i = 0; i < dimX; i++)
    {
        for (int j = 0; j < dimY; j++)
        {
            for (int k = 0; k < dimZ; k++)
                cellArray[i][j][k] = new Cell();//creates new cell obj?
        }
    }
}

// Prints array by calling the "tick()" function in the "Cell" class
void Arena::callTick()
{
    // Prints out Objects for testing
    for (int i = 0; i < dimZ; i++)
    {
        for (int j = 0; j < dimY; j++)
        {
            for (int k = 0; k < dimX; k++)
            {
              //  cellArray[0][0][0]->currentCharacter.attackRange = 0; // This line is throwing a seg fault #######FIX PLS#####
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Arena::deletePointers()
{
    //deletes pointers backwards
    for (int i = 0; i < dimX; i++)
    {
        for (int j = 0; j < dimY; j++)
        {

            delete[] cellArray[i][j];
        }
        delete[] cellArray[i];
    }

    delete[] cellArray;
}
