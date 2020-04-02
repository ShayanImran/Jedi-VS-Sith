#include "Arena.h"
#include "Cell.h"
#include "Characters.h"
#include <time.h>
#include <iostream>


using namespace std;
Arena::Arena(int dimZ, int dimY, int dimX)
{
    this->dimX = dimX;
    this->dimY = dimY;
    this->dimZ = dimZ;

    srand(time(NULL));

}

Arena::~Arena()
{
 deletePointers();
}

void Arena::printArena()
{
     for (int i = 0; i < dimX; i++)
    {
        for(int j = 0; j < dimY; j++)
        {
            for(int k = 0; k < dimZ; k++)
                {
                    if(gameWorld[i][j][k]== NULL)
                    {
                         //cout << "[" << " "<< "]";
                    }
                    else
                        {
                            //cout << "[" << gameWorld[i][j][k]->teamIcon << "]";
                        }


                }
                //cout << endl;
        }
        //cout << endl;
    }


}

// Create 3D array dynamically with type "Cell"
void Arena::create3DArray()
{

    gameWorld = new Characters ***[dimX];
    for (int i = 0; i < dimX; i++)
    {
        gameWorld[i] = new Characters **[dimY];
        for (int j = 0; j < dimY; j++)
        {
            gameWorld[i][j] = new Characters *[dimZ];

        }
    }

}

// Fills array with "Cell" Objects
void Arena::fill3DArray()
{

    for (int i = 0; i < dimZ; i++)
    {
        for (int j = 0; j < dimX; j++)
        {
            for (int k = 0; k < dimY; k++)
                gameWorld[j][k][i] = new Characters(1,1,1,1,1,'j');//creates new cell obj?

        }
    }
}

// Fills array with "Character" Objects randomly
void Arena::fill3DArrayRandomly(int numSpawns)
{
                for(int r = 0; r < numSpawns; r++)
                {
                    randomX = rand() % dimX;
                    randomY = rand() % dimY;
                    randomZ = rand() % 3;
                    randomCharacterType = rand() % 2;

                    if(randomCharacterType==0)
                    {
                        gameWorld[randomX][randomY][randomZ] = new Characters(1,1,1,1,1,'j');//creates new character
                    }
                    else
                    {
                        gameWorld[randomX][randomY][randomZ] = new Characters(1,1,1,1,1,'s');
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
                //gameWorld[i][j][k].moveTo(i,j,z,3,3,3)
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Arena::deletePointers()
{/*
    //deletes pointers backwards
    for (int i = 0; i < dimX; i++)
    {
        for (int j = 0; j < dimY; j++)
        {

            delete[] gameWorld[i][j];
        }
        delete[] gameWorld[i];
    }

    delete[] gameWorld;
    */
}



