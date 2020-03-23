#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED

#include "Characters.h"

class MainCharacter
{
    public:

       MainCharacter();
       void mainChar();
    //void MainCharacter()
    private:

        float forcePower;
        float health;
        int damageGiven;
        int attackRange;
        int movementSpeed;

    protected:

        void specialMove();
        void process();
        void moveFrom(int** from, int** to);
};

#endif // MAINCHARACTER_H_INCLUDED
