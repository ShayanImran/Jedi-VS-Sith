#include "Cell.h"

Cell::Cell()
{

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
