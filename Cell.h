#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include "Characters.h"
class Cell
{
    public:

        Cell();
        int** getOffset();
        void setOffset(int** aCoord);
        char getImage();
        void setImage(char image);
        //int test = 9;
        Characters currentCharacter;


    private:

        int** offset;
        char image;



    protected:
        //Somehow need to access the First Arena member, its not a simple declaration like Arena Arena1;

        //The methods below can be moved around to be placed where it's more convenient
        void display();
        void process();
        int** getEmptyNeighborCoord();
        int** getJediNeighborCoord();
        int** getSithNeighborCoord();
        Cell getCellAt(int** aCoord);
        void assignCellAt(int** aCoord, Cell aCell);
        Cell east();
        Cell west();
        Cell south();
        Cell north();



};

#endif // CELL_H_INCLUDED
