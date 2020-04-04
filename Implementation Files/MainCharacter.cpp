#include "MainCharacter.h"
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> //Random
#include <time.h>   //Time
#include <bits/stdc++.h>
#include "Characters.h"
// --- Default Constructor ---
MainCharacter::MainCharacter(char teamIcon) : Characters()
{
    this->teamIcon = teamIcon;
    this->health;
    this->damageGiven;

    //Loop to determine stats of characters
    if (teamIcon == 'M')
    {

        this->health = 30;
        this->damageGiven = 20;
    }
}

//Destructor
MainCharacter::~MainCharacter()
{
}

// --- Special Move Functions ---
//Jedi Special Move, Works off % chance to determine if special move or not
void MainCharacter::JediSpecialMove() //Jedi Special Move
{
    //Variables
    int rand();
    int SMChance = 0;
    bool SM = false;

    //Random Chance Generator
    srand((time(NULL)));
    SMChance = rand() % 100 + 1; //% chance of special move

    //Determine if Special Attack, 25% chance
    if (SMChance <= 25)
    {
        SM = true; //Change to true to run while loop

        while (SM == true)
        {
            //Temp increase stats for special move
            damageGiven + 40;
            SM = false;          //change to exit
            JSpecialDone = true; //To avoid Issue listed in instructions step 3
        }

        SMChance = 30; //Change SMChance to set number > 25 to exit if statement
    }
}

void MainCharacter::JediSMReset() //Jedi Special Stats Remove
{
    //Reset stats, subtract difference that was added
    if (JSpecialDone == true) //Determine if special was done to avoid resetting unbuffed stats
    {

        damageGiven - 40;
        JSpecialDone = false;
    }
}

//Sith Special Moves, Same as Jedi but for Sith main characters
void MainCharacter::SithSpecialMove() //Sith Special Move
{
    //Variables
    int rand();
    int SMChance = 0; //Resets special move chance
    bool SM = false;

    //Random Generator
    srand((time(NULL)));
    SMChance = rand() % 100 + 1; //% chance of special move

    //Determine if special attack happens, 20% chance
    if (SMChance <= 20)
    {
        SM = true;

        //While loop to change stats
        while (SM == true)
        {
            //Temp increase stats
            damageGiven + 45;

            SM = false;
            SSpecialDone = true;
        }

        SMChance = 30; //Change SMChance to set number > 21 to exit if statement, should use break?
    }
}
void MainCharacter::SithSMReset() //Reset Sith Special Move
{
    //Take away difference that was added to reset
    if (SSpecialDone == true) //Determine if special was done to avoid resetting unbuffed stats
    {

        damageGiven - 45;
        SSpecialDone = false;
    }
}
/*      INSTRUCTIONS ---
1) Call Special Attack Move, if
2) Character Attacks (doDamage)
3) Call Reset Functions to Reset their stats back to before. Need loop to check
    if special attack was done, as if it wasnt in loop and reset was called this
    would subtract difference no matter, therefore calling reset would handicap
    character.
// --- --- --- --- --- --- --- */

// --- Level Up Functions ---
//Stats when charatcters level up
void MainCharacter::JediPowerLvlUp()
{
    JlvlUp = true; //Sets JlvlUp true to run if statement

    //If statement for increasing stats
    while (JlvlUp = true)
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

void MainCharacter::SithPowerLvlUp()
{
    SlvlUp = true; //Sets SlvlUp true to run if loop

    //If statements to increase stats and heal
    while (SlvlUp = true)
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
void MainCharacter::SidePick()
{
    int rand();
    int side;

    //Random Generator
    srand((time(NULL)));
    side = rand() % 2; //Generates random number either 0 or 1

    if (side == 1) //If = 1, Jedi
    {

        JediChar = true;
    }

    else
        SithChar = true; //If = 0, Sith
}

// --- Attack Functions
//Attack function for buff. Need to inherit doDamage() from Characters class but having issues
void MainCharacter::CharAttack()
{

    if (JediChar == true) //If jedi, apply possible special move and reset
    {

        JediSpecialMove();
        //doDamage();
        JediSMReset();
    }

    if (SithChar == true) //If sith, apply possible special move and reset
    {

        SithSpecialMove();
        //doDamage();
        JediSMReset();
    }
}

// --- --- --- --- --- --- --- ---

// --- Legendary Character Function
void MainCharacter::LegendaryChar()
{
    //Moved to default constructor. Kept just in case
}
/*      INSTRUCTIONS ---
1) Make button to spawn legendary (user only can spawn 2 per side)
    So when they click the button, say numLJedi and numLSith + 1,
    maxes out at 2 using loop. Need to have numLJedi++ and numLSith++
    when button has been pressed
2) When selecting button, should change LegJedi and LegSith to true,
    then spawn it
3) Fill random cell with them (or somehow drag and drop them in)?
// --- --- --- --- --- --- --- */
