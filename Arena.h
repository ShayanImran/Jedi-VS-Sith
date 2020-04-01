#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED
#include "Cell.h"
#include "Characters.h"
#include <iostream>

class Arena
{
    public:
        Arena(int dimX,int dimY, int dimZ);
        ~Arena();
        int getNumJedi();
        void setNumJedi(int num);
        int getNumSith();
        void setNumSith(int num);
        void printArena();
        int dimX;
        int dimY;
        int dimZ;
        int randomX, randomY, randomZ;
        int randomCharacterType; // Random roll for either a jedi or sith character type

       Characters ****gameWorld; //Array of characters

        //test functions from assignment 3
        void create3DArray();
        void fill3DArray();
        void callTick();
        void deletePointers();
        void fill3DArrayRandomly(int numSpawns);

    private:

        int Size;
        int numJedi;
        int numSith;
        int numObsticals;
        int random;
        int numLandMines;

    protected:

        void generateObsticals();
        void spawnDebris();
        void initialize();
        void initCharacters();
        void addObsticals(int numObs);
        void addSith(int numSith);
        void addJedi(int numJedi);
        void displayBorder();
        void displayCharacters();
        void displayStats();
        void run();



};

#endif // ARENA_H_INCLUDED
