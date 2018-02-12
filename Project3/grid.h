#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
#include "d_matrix.h"
using namespace std;

class grid
{
    public:
        void readIn();
        int getRows() const;
        int getCols() const;
        char getChar(int i, int j);
        //friend ostream& operator << (ostream &out, const wordList &list);
    private:
        matrix <char> charMatrix;

};

#endif
