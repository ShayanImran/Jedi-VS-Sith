#include <iostream>
#include <unistd.h>
#include "Arena.h"
#include <utility>
#include "MainCharacter.h"
using namespace std;

static int numS;
static int numJ;
bool isrun = true;
bool xT, yT, zT, nJT, nST, nMT, nOT = false;
int usrZ, usrY, usrX;
int nJ, nS, nM, nO;
int maxSpace, maxChar;
int numIterations;

void RunGame();
int LimitArena(), LimitCharactersAndIterations();

int main()
{
    cout << "- - - Jedi vs Sith - - - " << endl << endl;

    LimitArena();
    LimitCharactersAndIterations();

    return 0;
}
void RunGame()
{
    Arena arena1(usrZ, usrY, usrX); //Z, Y, X
    arena1.create3DArray();
    arena1.fill3DArrayRandomly(nJ, nS, nM, nO); //Jedi, Sith, monster, obstacles
        for (int i = 0; i < numIterations; i++)
            {
            arena1.callTick();
            arena1.printArena();
            sleep(1);
            }
}
int LimitArena()
{
    cout << "ARENA Size: " << endl << "-Note: Limits are X - 3 to 70, Y - 3 to 20, Z - 1 to 6" << endl;
    cout << " X: ";
    cin >> usrX;
    if (usrX < 3 || usrX > 70)
        {
            cout << "***Not Valid X***" << endl;
        }
    else
        xT = true;

    cout << " Y: ";
    cin >> usrY;
    if (usrY < 3 || usrY > 20)
    {
        cout << "***Not Valid Y***" << endl;
    }
    else
        yT = true;
    cout << " Z: ";
    cin >> usrZ;

    if (usrZ < 1 || usrZ > 6)
    {
        cout << "***Not Valid Z***" << endl;
    }
    else
        zT = true;

    if (!xT && !yT && !zT)
    {
        cout << "***Input Invalid...Please Restart.***";
    }

    maxSpace = usrZ * usrY * usrX;

    cout << endl;
}
int LimitCharactersAndIterations()
{

    while (xT && yT && zT)
    {
        cout << "Character Amount: " << endl
        << "-Note: Can't have too many characters." << endl
        << "--Consider arena size in respect to character amount" << endl;
        cout << " Amount Jedi: ";
        cin >> nJ;

        if (nJ < 1)
            {
                cout << "***Not Valid Amount***" << endl;
            }
        else
            nJT = true;

        cout << " Amount Sith: ";
        cin >> nS;
        if (nS < 1)
        {
        cout << "***Not Valid Amount***" << endl;
        }
        else
            nST = true;

        cout << " Amount Monster: ";
        cin >> nM;
        if (nM < 0)
        {
            cout << "***Not Valid Amount***" << endl;
        }
        else
            nMT = true;

        cout << " Amount Obstacles: ";
        cin >> nO;
        if (nO < 0)
        {
            cout << "***Not Valid Amount***" << endl;
        }
        else
            nOT = true;

        if (!nJT && !nST && !nMT && !nOT)
        {
            cout << "***At least one is NOT Valid...Please try again***" << endl;
        }

        maxChar = nJ + nS + nM + nO;

            while (nJT && nST && nMT && nOT)
            {
                if (maxSpace >= maxChar)
                {
                    cout << "Enter how many iterations." << endl << "-Note: Limits 100 to 10,000" << endl;
                    cin >> numIterations;

                    if (numIterations < 100 || numIterations > 10000)
                    {
                        cout << "***Incorrect Amount of Iterations***" << endl;
                    }
                    else
                    RunGame();
                }
            else
                cout << "***Too many characters***" << endl;
                return 0;
            }
    }
}
