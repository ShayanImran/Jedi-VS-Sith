#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED
#include "Cell.h"
#include <iostream>
class Arena
{
    public:
        Arena(int x,int y, int z);
        Cell ****cellArray; // Array of cells
        int getNumJedi();
        void setNumJedi(int num);
        int getNumSith();
        void setNumSith(int num);

        //test functions from assignment 3
        void create3DArray();
        void fill3DArray();
        void callTick();
        void deletePointers();
    private:

        int dimX;
        int dimY;
        int dimZ;
        int Size;
        int numJedi;
        int numSith;
        int numObstacles;
        int random;
        int numLandMines;

    protected:

        void generateObstacle();
        void spawnDebris();
        void initialize();
        void initCharacters();
        void addObstacle(int numObs);
        void addSith(int numSith);
        void addJedi(int numJedi);
        void displayBorder();
        void displayCharacters();
        void displayStats();
        void run();



};

#endif // ARENA_H_INCLUDED
