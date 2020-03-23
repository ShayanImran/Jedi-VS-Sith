#include "MainCharacter.h"
#include <wx/msgdlg.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> //Random
#include <time.h> //Time
#include <bits/stdc++.h>
#include "Characters.h"

// --- Variables ---
float forcePower;
float health;

int damageGiven;
int attackRange;
int movementSpeed;
int powerLevel;
int Jlvl,Slvl = 0; //This is to restrict level ups

bool JSpecialDone,SSpecialDone = false; //Determine if special was done (point of reset)
bool JlvlUp, SlvlUp = false; //Determine if jedi levels up
bool JediChar,SithChar = false;

char JediImage = 'J';
char SithImage = 'S';

// --- Default Constructor ---
MainCharacter::MainCharacter()
{
    // this.health = ##
    //this.damageGiven == ##    These are examples of how to initialize variables upon creation of the object

}

// --- Put functions in scope
void JediSpecialMove();
void SithSpecialMove();
void JediSMReset();
void SithSMReset();
void JediPowerLvlUp();
void SithPowerLvlUp();
void SidePick();
// --- Main Character Function ---
void MainCharacter::mainChar() //Make objects for sith and jedi
{

    //Character Object
    MainCharacter mChar; //Object character for Jedi
        mChar.health;
        mChar.damageGiven;
        mChar.movementSpeed;
        mChar.attackRange;
    SidePick(); //Call SidePick to determine stats of Character
    //Loop to determine stats of characters
    if (JediChar == true) //Jedi stats
    {
        mChar.health = 12;
        mChar.damageGiven = 3;
        mChar.movementSpeed = 2;
        mChar.attackRange = 2;
    }
    if (SithChar == true) //Sith stats
    {
        mChar.health = 10;
        mChar.damageGiven = 4;
        mChar.movementSpeed = 2;
        mChar.attackRange = 2;
    }
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
            damageGiven + 8;
            attackRange + 2;
            SM = false; //change to exit
            JSpecialDone = true; //To avoid Issue listed in instructions step 3
        }
        SMChance = 30; //Change SMChance to set number > 25 to exit if statement
    }
}
void JediSMReset() //Jedi Special Stats Remove
{
    //Reset stats, subtract difference that was added
    damageGiven - 8;
    attackRange - 2;
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
            damageGiven + 10;
            attackRange + 1;
            SM = false;
            SSpecialDone = true;
        }
        SMChance = 30; //Change SMChance to set number > 21 to exit if statement
    }
}
void SithSMReset() //Reset Sith Special Move
{
    //Take away difference that was added to reset
    damageGiven - 10;
    attackRange - 1;
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

// --- Level Up Functions ---
//Stats when charatcters level up
void JediPowerLvlUp()
{
    JlvlUp = true; //Sets JlvlUp true to run if statement

    //If statement for increasing stats
    while(JlvlUp = true)
    {
        Jlvl++;
        if (Jlvl < 3) //Sets limit so characters cannot become overpowered
        {
        health = health + 2; //This is to heal by 2
        damageGiven = damageGiven + 1;
        break; //Force exit loop after one run through
        }
        JlvlUp = false; //Exit while loop
    }
}
void SithPowerLvlUp()
{
    SlvlUp = true; //Sets SlvlUp true to run if loop

    //If statements to increase stats and heal
    while(SlvlUp = true)
    {
        Slvl++;
        if (Slvl < 3) //Sets limit so characters cannot become overpowered
        {
        health = health + 2; //This is to heal by 2
        damageGiven = damageGiven + 1;
        break; //Force exit if loop after one go through
        }
        SlvlUp = false; //Exit While Loop
    }
}
/*      INSTRUCTIONS ---
1) Have statement to determine when character levels up
2) In that statement, if it hits the conditions call function
    for example: if (KillCount == 5)
    {
    SithPowerLvlUp();
    }
// --- --- --- --- --- --- --- */

// --- Determine if Jedi or Sith
void SidePick()
{
    int rand();
    int side;

    //Random Generator
    srand((time(NULL)));
    side = rand() %1;

    if (side == 1)
    {
        JediChar = true;
    }
    else
        SithChar = true;
}


