#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED

//#include "Characters.h" //Causing issue

class MainCharacter //: public Characters
{
    public:

       MainCharacter();

       // --- Functions
       //void mainChar(MainCharacter Obj);
       //Special move + reset
       void JediSpecialMove();
       void JediSMReset();
       void SithSpecialMove();
       void SithSMReset();
       //Level up
       void JediPowerLvlUp();
       void SithPowerLvlUp();
       //Pick side
       void SidePick();
       //Attack function
       void CharAttack();
       //Spawn Legendary
       void LegendaryChar();

    private:

        // --- Variables
        float forcePower;
        float health;

        int damageGiven;
        int attackRange;
        int movementSpeed;
        int numLegJedi;
        int numLegSith;
        int Jlvl,Slvl = 0; //This is to restrict level ups

        bool JSpecialDone,SSpecialDone = false; //Determine if special was done (point of reset)
        bool JlvlUp, SlvlUp = false; //Determine if jedi levels up
        bool JediChar,SithChar = false;
        bool Legendary = false;
        //Images
        char JediImage = 'J';
        char SithImage = 'S';
        char LegJediImage = 'LJ';
        char LegSithImage = 'LS';

    protected:

        void specialMove();
        void process();
        void moveFrom(int** from, int** to);

};

#endif // MAINCHARACTER_H_INCLUDED
