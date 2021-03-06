#include "Arena.h"
#include "Characters.h"
#include "Jedi_VS_SithMain.h"
#include <time.h>
#include <iostream>
#include <vector>


Arena::Arena(int dimX, int dimY, int dimZ)
{
    this->dimX = dimX;
    this->dimY = dimY;
    this->dimZ = dimZ;

    //srand(time(NULL));
}

Arena::~Arena()
{
    //deletePointers();
}

void Arena::printArena(wxFrame frame)
{
    for (int i = 0; i < dimX; i++)
    {
        for (int j = 0; j < dimY; j++)
        {
            for (int k = 0; k < dimZ; k++)
            {
                if (gameWorld[i][j][k] == NULL)
                {
                    //cout << "["
                         //<< " "
                         //<< "]";
                }
                else
                {
                    //cout << "[" << gameWorld[i][j][k]->teamIcon << "]";
                }
            }
            //cout << endl;
        }
    }
}

// Create 3D array dynamically with type "Cell"
void Arena::create3DArray()
{

    gameWorld = new Characters ***[dimX];
    for (int i = 0; i < dimX; i++)
    {
        gameWorld[i] = new Characters **[dimY];
        for (int j = 0; j < dimY; j++)
        {
            gameWorld[i][j] = new Characters *[dimZ];
            for (int k = 0; k < dimZ; k++)
            {
                gameWorld[i][j][k] = 0;
            }
        }
    }
}

// Fills array with "Character" Objects randomly
void Arena::fill3DArrayRandomly(int numJedi, int numSith, int numMonsters, int numObstacles)
{
    this->numJedi = numJedi;
    this->numSith = numSith;
    this->numObstacals = numObstacles;
    this->numMonsters = numMonsters;

    for (int k = 0; k < numJedi; k++)
    {
        randomX = rand() % dimX;
        randomY = rand() % dimY;
        randomZ = rand() % dimZ;

        if (gameWorld[randomX][randomY][randomZ] == NULL)
        {
            gameWorld[randomX][randomY][randomZ] = new Characters('j'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
        else
        {
            while (gameWorld[randomX][randomY][randomZ] != NULL)
            {
                randomX = rand() % dimX;
                randomY = rand() % dimY;
                randomZ = rand() % dimZ;
            }
            gameWorld[randomX][randomY][randomZ] = new Characters('j'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;


        }
    }


    for (int k = 0; k < numMonsters; k++)
    {
        randomX = rand() % dimX;
        randomY = rand() % dimY;
        randomZ = rand() % dimZ;

        if (gameWorld[randomX][randomY][randomZ] == NULL)
        {
            gameWorld[randomX][randomY][randomZ] = new MainCharacter('M'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
        else
        {
            while (gameWorld[randomX][randomY][randomZ] != NULL)
            {
                randomX = rand() % dimX;
                randomY = rand() % dimY;
                randomZ = rand() % dimZ;
            }
            gameWorld[randomX][randomY][randomZ] = new MainCharacter('M'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
    }

    for (int k = 0; k < numSith; k++)
    {
        randomX = rand() % dimX;
        randomY = rand() % dimY;
        randomZ = rand() % dimZ;

        if (gameWorld[randomX][randomY][randomZ] == NULL)
        {
            gameWorld[randomX][randomY][randomZ] = new Characters('s'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
        else
        {
            while (gameWorld[randomX][randomY][randomZ] != NULL)
            {
                randomX = rand() % dimX;
                randomY = rand() % dimY;
                randomZ = rand() % dimZ;
            }
            gameWorld[randomX][randomY][randomZ] = new Characters('s'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
    }

    for (int k = 0; k < numObstacles; k++)
    {
        randomX = rand() % dimX;
        randomY = rand() % dimY;
        randomZ = rand() % dimZ;

        if (gameWorld[randomX][randomY][randomZ] == NULL)
        {
            gameWorld[randomX][randomY][randomZ] = new Characters('#'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
        else
        {
            while (gameWorld[randomX][randomY][randomZ] != NULL)
            {
                randomX = rand() % dimX;
                randomY = rand() % dimY;
                randomZ = rand() % dimZ;
            }
            gameWorld[randomX][randomY][randomZ] = new Characters('#'); //creates new character
            gameWorld[randomX][randomY][randomZ]->isCellOpen = false;
        }
    }
}

// Prints array by calling the "tick()" function in the "Cell" class
// Prints array by calling the "tick()" function in the "Cell" class
void Arena::callTick()
{
    // Random number to call a random directional movement
    srand(time(NULL));
    int randomDirection;
    bool attacked = false;
    // Prints out Objects for testing
    for (int i = 0; i < dimX; i++)
    {
        for (int j = 0; j < dimY; j++)
        {
            for (int k = 0; k < dimZ; k++)
            {

                randomDirection = rand() % 4;

                attacked = doDamage(i, j, k);

                if (!attacked && this->gameWorld[i][j][k] != 0 && this->gameWorld[i][j][k]->teamIcon != '#')
                {
                    moveRandomly(i, j, k, randomDirection);
                }

                if (this->gameWorld[i][j][k] != 0 && this->gameWorld[i][j][k]->teamIcon != '#')
                {

                    this->gameWorld[i][j][k]->health - 0.5;
                    if (gameWorld[i][j][k]->getHealth() <= 0.0)
                    {
                        if (this->gameWorld[i][j][k]->teamIcon == 's')
                        {
                            this->numSith--;
                        }
                        if (this->gameWorld[i][j][k]->teamIcon == 'j')
                        {
                            this->numJedi--;
                        }
                        if (this->gameWorld[i][j][k]->teamIcon == 'M')
                        {
                            this->numMonsters--;
                        }
                        this->gameWorld[i][j][k] = 0;
                    }
                }
            }
            //cout << endl;
        }
        //cout << endl;
    }
}

void Arena::deletePointers()
{/*
    //deletes pointers backwards
    for (int i = 0; i < dimX; i++)
    {
        for (int j = 0; j < dimY; j++)
        {

            delete[] gameWorld[i][j];
        }
        delete[] gameWorld[i];
    }

    delete[] gameWorld;*/
}

// intention is to pass array into here and do the swap on each loop iteration
void Arena::moveUp(int a, int b, int c)
{

    if (a - 1 < 0 && b == 0) // Checks to see if the character is in the last sub arena AND the last row
    {
        int WrapArena = dimX - 1;
        int WrapAround = dimZ - 1;
        std::swap(this->gameWorld[a][b][c], this->gameWorld[WrapArena][WrapAround][c]);

        /* Uses WrapArena to return the index of the 1st subarena,
        Uses WrapAround to get the row that it wraps to
        (for example if its in the FIRST row of an arena it will go to the LAST row of the next when moving up)
        */
    }
    else
    {
        // Checks if move is at edge of arena
        if (b - 1 < 0)
        {
            int WrapAround = dimZ - 1; // Calculates the index that would "wrap around" to the other side of the array
            std::swap(this->gameWorld[a][b][c], this->gameWorld[a - 1][WrapAround][c]);
        }
        // If the move is not at the edge it will go through as normal
        else
        {
            std::swap(this->gameWorld[a][b][c], this->gameWorld[a][b - 1][c]);
        }
    }
}
void Arena::moveDown(int a, int b, int c)
{
    if (a + 1 >= this->dimX && b == dimY - 1) // Checks to see if the character is in the last sub arena AND the last row
    {
        int WrapArena = (a + 1) % dimX;
        int WrapAround = (b + 1) % dimZ;
        std::swap(this->gameWorld[a][b][c], this->gameWorld[WrapArena][WrapAround][c]);

        /* Uses WrapArena to return the index of the 1st subarena,
        Uses WrapAround to get the row that it wraps to
        (for example if its in the LAST row of an arena it will go to the FIRST row of the next when moving down)
        */
    }
    else
    {
        // Checks if move is at edge of arena
        if (b + 1 >= this->dimY)
        {
            int WrapAround = (b + 1) % dimZ; // Calculates the index that would "wrap around" to the other side of the array
            std::swap(this->gameWorld[a][b][c], this->gameWorld[a + 1][WrapAround][c]);
        }
        // If the move is not at the edge it will go through as normal
        else
        {
            std::swap(this->gameWorld[a][b][c], this->gameWorld[a][b + 1][c]);
        }
    }
}
void Arena::moveLeft(int a, int b, int c)
{
    // Checks if move is at edge of arena
    if (c - 1 < 0)
    {
        int WrapAround = dimZ - 1; // Calculates the index that would "wrap around" to the other side of the array
        std::swap(this->gameWorld[a][b][c], this->gameWorld[a][b][WrapAround]);
    }
    // If the move is not at the edge it will go through as normal
    else
    {
        std::swap(this->gameWorld[a][b][c], this->gameWorld[a][b][c - 1]);
    }
}
void Arena::moveRight(int a, int b, int c)
{
    // Checks if move is at edge of arena
    if (c + 1 >= this->dimZ)
    {
        int WrapAround = (c + 1) % dimZ; // Calculates the index that would "wrap around" to the other side of the array
        std::swap(this->gameWorld[a][b][c], this->gameWorld[a][b][WrapAround]);
    }
    // If the move is not at the edge it will go through as normal
    else
    {
        std::swap(this->gameWorld[a][b][c], this->gameWorld[a][b][c + 1]);
    }
}
void Arena::moveRandomly(int a, int b, int c, int randomDirection)
{

    // Bools to check if there are open spaces around
    bool canMoveUp = true;
    bool canMoveRight = true;
    bool canMoveLeft = true;
    bool canMoveDown = true;

    //UP
    if (b - 1 < 0)
    {
        //You cant do that
        if (this->gameWorld[a][dimY - 1][c] != 0)
        {
            canMoveUp = false;
        }
    }
    else
    {
        if (this->gameWorld[a][b - 1][c] != 0)
        {
            canMoveUp = false;
        }
    }

    // LEFT
    if (c - 1 < 0)
    {
        //You cant do that
        if (this->gameWorld[a][b][dimZ - 1] != 0)
        {
            canMoveLeft = false;
        }
    }
    else
    {
        if (this->gameWorld[a][b][c - 1] != 0)
        {
            canMoveLeft = false;
        }
    }

    //RIGHT
    if (c + 1 == dimX)
    {
        //You cant do that
        if (this->gameWorld[a][b][0] != 0)
        {
            canMoveRight = false;
        }
    }
    else
    {
        if (this->gameWorld[a][b][c + 1] != 0)
        {
            canMoveRight = false;
        }
    }

    //DOWN
    if (b + 1 == dimY)
    {
        //You cant do that
        if (this->gameWorld[a][0][c] != 0)
        {
            canMoveDown = false;
        }
    }
    else
    {
        if (this->gameWorld[a][b + 1][c] != 0)
        {
            canMoveDown = false;
        }
    }

    if (randomDirection == 0 && canMoveUp)
    {
        moveUp(a, b, c);
    }
    if (randomDirection == 1 && canMoveRight)
    {
        moveRight(a, b, c);
    }
    if (randomDirection == 2 && canMoveDown)
    {
        moveDown(a, b, c);
    }
    if (randomDirection == 3 && canMoveLeft)
    {
        moveLeft(a, b, c);
    }
}

bool Arena::doDamage(int a, int b, int c)
{
    // Bools to check if there are open spaces around
    bool canAttackUp = false;
    bool canAttackRight = false;
    bool canAttackLeft = false;
    bool canAttackDown = false;
    bool hasAttacked = false;

    //UP
    if (b - 1 < 0)
    {
        //You cant do that
        // cout << "CANT MOVE UP YOU IDIOT" << endl;
        canAttackUp = false;
    }
    else
    {
        if (this->gameWorld[a][b - 1][c] != 0)
        {
            canAttackUp = true;
        }
    }

    // LEFT
    if (c - 1 < 0)
    {
        //You cant do that
        // cout << "CANT MOVE LEFT YOU IDIOT" << endl;
        canAttackLeft = false;
    }
    else
    {
        if (this->gameWorld[a][b][c - 1] != 0)
        {
            canAttackLeft = true;
        }
    }

    //RIGHT
    if (c + 1 == dimZ)
    {
        //You cant do that
        // cout << "CANT MOVE RIGHT YOU IDIOT" << endl;
        canAttackRight = false;
    }
    else
    {
        if (this->gameWorld[a][b][c + 1] != 0)
        {
            canAttackRight = true;
        }
    }

    //DOWN
    if (b + 1 == dimY)
    {
        //You cant do that
        // cout << "CANT MOVE DOWN YOU IDIOT" << endl;
        canAttackDown = false;
    }
    else
    {
        if (this->gameWorld[a][b + 1][c] != 0)
        {
            canAttackDown = true;
        }
    }

    if (canAttackUp && !hasAttacked && this->gameWorld[a][b][c] != 0 && this->gameWorld[a][b][c]->teamIcon != this->gameWorld[a][b - 1][c]->teamIcon && this->gameWorld[a][b - 1][c]->teamIcon != '#')
    {
        float temp = gameWorld[a][b][c]->doDamage(gameWorld[a][b][c]->getDamage(), gameWorld[a][b - 1][c]->getHealth());
        gameWorld[a][b - 1][c]->setHealth(temp);
        if (gameWorld[a][b - 1][c]->getHealth() <= 0.0)
        {
            if (this->gameWorld[a][b - 1][c]->teamIcon == 's')
            {
                this->numSith--;
            }
            if (this->gameWorld[a][b - 1][c]->teamIcon == 'j')
            {
                this->numJedi--;
            }
            if (this->gameWorld[a][b - 1][c]->teamIcon == 'M')
            {
                this->numMonsters--;
            }
            this->gameWorld[a][b - 1][c] = 0;
            this->gameWorld[a][b][c]->health * 2;
        }
        hasAttacked = true;
    }
    if (canAttackRight && !hasAttacked && this->gameWorld[a][b][c] != 0 && this->gameWorld[a][b][c]->teamIcon != this->gameWorld[a][b][c + 1]->teamIcon && this->gameWorld[a][b][c + 1]->teamIcon != '#')
    {
        float temp = gameWorld[a][b][c]->doDamage(gameWorld[a][b][c]->getDamage(), gameWorld[a][b][c + 1]->getHealth());
        gameWorld[a][b][c + 1]->setHealth(temp);
        if (gameWorld[a][b][c + 1]->getHealth() <= 0.0)
        {
            if (this->gameWorld[a][b][c + 1]->teamIcon == 's')
            {
                this->numSith--;
            }
            if (this->gameWorld[a][b][c + 1]->teamIcon == 'j')
            {
                this->numJedi--;
            }
            if (this->gameWorld[a][b][c + 1]->teamIcon == 'M')
            {
                this->numMonsters--;
            }
            this->gameWorld[a][b][c + 1] = 0;
            this->gameWorld[a][b][c]->health * 2;
        }
        hasAttacked = true;
    }
    if (canAttackDown && !hasAttacked && this->gameWorld[a][b][c] != 0 && this->gameWorld[a][b][c]->teamIcon != this->gameWorld[a][b + 1][c]->teamIcon && this->gameWorld[a][b + 1][c]->teamIcon != '#')
    {
        float temp = gameWorld[a][b][c]->doDamage(gameWorld[a][b][c]->getDamage(), gameWorld[a][b + 1][c]->getHealth());
        gameWorld[a][b + 1][c]->setHealth(temp);
        if (gameWorld[a][b + 1][c]->getHealth() <= 0.0)
        {
            if (this->gameWorld[a][b + 1][c]->teamIcon == 's')
            {
                this->numSith--;
            }
            if (this->gameWorld[a][b + 1][c]->teamIcon == 'j')
            {
                this->numJedi--;
            }
            if (this->gameWorld[a][b + 1][c]->teamIcon == 'M')
            {
                this->numMonsters--;
            }
            this->gameWorld[a][b + 1][c] = 0;
            this->gameWorld[a][b][c]->health * 2;
        }
        hasAttacked = true;
    }
    if (canAttackLeft && !hasAttacked && this->gameWorld[a][b][c] != 0 && this->gameWorld[a][b][c]->teamIcon != this->gameWorld[a][b][c - 1]->teamIcon && this->gameWorld[a][b][c - 1]->teamIcon != '#')
    {
        float temp = gameWorld[a][b][c]->doDamage(gameWorld[a][b][c]->getDamage(), gameWorld[a][b][c - 1]->getHealth());
        gameWorld[a][b][c - 1]->setHealth(temp);
        if (gameWorld[a][b][c - 1]->getHealth() <= 0.0)
        {
            if (this->gameWorld[a][b][c - 1]->teamIcon == 's')
            {
                this->numSith--;
            }
            if (this->gameWorld[a][b][c - 1]->teamIcon == 'j')
            {
                this->numJedi--;
            }
            if (this->gameWorld[a][b][c - 1]->teamIcon == 'M')
            {
                this->numMonsters--;
            }
            this->gameWorld[a][b][c - 1] = 0;
            this->gameWorld[a][b][c]->health * 2;
        }
        hasAttacked = true;
    }

    return hasAttacked;
}
