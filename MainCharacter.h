#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED

//#include "Characters.h"

class MainCharacter //: public Characters
{
    public:

       MainCharacter();

       // --- Functions
       void mainChar();
       void JediSpecialMove();
       void JediSMReset();
       void SithSpecialMove();
       void SithSMReset();
       void JediPowerLvlUp();
       void SithPowerLvlUp();
       void SidePick();
       void CharAttack();

    private:

        // --- Variables
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
