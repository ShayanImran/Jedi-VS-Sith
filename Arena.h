#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED

class Arena
{
    public:

        int getNumJedi();
        void setNumJedi(int num);
        int getNumSith();
        void setNumSith(int num);

    private:

        int dimX;
        int dimY;
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
