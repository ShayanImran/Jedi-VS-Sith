#include "MainCharacter.h"
//#include "Characters.h"
#include <wx/msgdlg.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> //Random
#include <time.h> //Time
#include <bits/stdc++.h>

// --- Variables ---
float forcePower;

int JdamageGiven = 2;
int JattackRange = 3;
int SdamageGiven = 3;
int SattackRange = 2;
int powerLevel;

bool JSpecialDone,SSpecialDone = false;

//Default Constructor
MainCharacter::MainCharacter(/*Can define parameters if you want*/)
{
    // this.health = ##
    //this.damageGiven == ##    These are examples of how to initialize variables upon creation of the object

}


// --- Main Character Function ---
void mainChar() //Make objects for sith and jedi
{
    //Jedi
    MainCharacter Jedi; //Object character for Jedi

        Jedi.health = 10;
        Jedi.damageGiven = 2;
        Jedi.movementSpeed = 5;
        Jedi.attackRange = 2;
    //Sith
    MainCharacter Sith; //Object character for Sith
        Sith.health = 12;
        Sith.damageGiven = 3;
        Sith.movementSpeed = 4;
        Sith.attackRange = 3;
}
/*
~mainChar()
{

}
*/
// --- --- --- --- --- ---

// --- Special Move Functions ---
//Jedi Special Move, Works off % chance to determine if special move or not
void JediSpecialMove() //Jedi Special Move
{
    //Variables
    int rand();
    int SMChance;
    bool SM = false;

    //Random Chance Generator
    srand((time(NULL)));
    SMChance = rand() %101; //% chance of special move

    //Determine if Special Attack, 25% chance
    if (SMChance <= 25)
    {
        SM = true; //Change to true to run while loop
        while (SM == true)
        {
            //Temp increase stats for special move
            JdamageGiven + 8;
            JattackRange + 2;
            SM = false; //change to exit
            JSpecialDone = true; //To avoid Issue listed in instructions step 3
        }
        SMChance = 30; //Change SMChance to set number > 25 to exit if statement
    }
}
void JediSMReset() //Jedi Special Stats Remove
{
    //Reset stats, subtract difference that was added
    JdamageGiven - 8;
    JattackRange - 2;
    JSpecialDone = false;
}

//Sith Special Moves, Same as Jedi but for Sith main characters
void SithSpecialMove() //Sith Special Move
{
    //Variables
    int rand();
    int SMChance;
    bool SM = false;

    //Random Generator
    srand((time(NULL)));
    SMChance = rand() %101; //25% chance of special move

    //Determine if special attack happens, 20% chance
    if (SMChance <= 20)
    {
        SM = true;
        //While loop to change stats
        while (SM == true)
        {
            //Temp increase stats
            SdamageGiven + 10;
            SattackRange + 1;
            SM = false;
            SSpecialDone = true;
        }
        SMChance = 30; //Change SMChance to set number > 21 to exit if statement
    }
}
void SithSMReset() //Reset Sith Special Move
{
    //Take away difference that was added to reset
    SdamageGiven - 10;
    SattackRange - 1;
    SSpecialDone = false;
}
/*      INSTRUCTIONS ---
1) Call Spcial Attack Move, if
2) Character Attacks (doDamage)
3) Call Reset Functions to Reset their stats back to before. Need loop to check
    if special attack was done, as if it wasnt in loop and reset was called this
    would subtract difference no matter, therefore calling reset would handicap
    character.
    Loop should be as follows:
    if (SSpecialDone == true) **For Jedi need corresponding
    {
        voidSithSMReset();
    }
// --- --- --- --- --- --- --- */
