#include "Cell.h"
#include "Characters.h"
#include <iostream>
using namespace std;
// Constructor takes in dimensions
Cell::Cell() : currentCharacter(10,0,0,0,0) // Looks weird but basically when you use an OBJECT that has a constructor with parameters as a member variable of the header file, you need to initialize it using this style
{

   // gameBoard = new Characters ***[x];
//    Characters character = new Characters(10.0,1,1,1,1);


}

int** Cell::getOffset()
{
    return offset;
}

void Cell::setOffset(int** aCoord)
{
    offset = aCoord;
}

char Cell::getImage()
{
    return image;
}

void Cell::setImage(char pic)
{
    image = pic;
}
