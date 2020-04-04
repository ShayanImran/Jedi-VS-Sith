#include "Cell.h"
#include "Characters.h"
#include <iostream>
using namespace std;
// Constructor takes in dimensions
Cell::Cell()
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
void Cell::hello()
{
    cout<<" hello world ";


}

void Cell::setImage(char pic)
{
    image = pic;
}
