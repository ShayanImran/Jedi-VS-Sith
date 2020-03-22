#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED
#include "Characters.h"

class MainCharacter
{
    public:

       MainCharacter();
        //Object Variables
        //Object Variables
        float health;
        int damageGiven;
        int attackRange;
        int movementSpeed;

    private:

        float forcePower;


    protected:

        void specialMove();
        void process();
        void moveFrom(int** from, int** to);
};

#endif // MAINCHARACTER_H_INCLUDED
