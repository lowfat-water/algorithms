#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "d_matrix.h"

class board
// Stores the entire Sudoku board
{
    public:
        board(int squareSize);
        void clear();
        void initialize(ifstream &fin);
        void print();
        bool isBlank(int, int);
        int getCell(int, int);
        void setCell(int i,int j, int val);
    private:
    // The following matrices go from 1 to boardSize in each
    // dimension. I.e. they are each (boardSize+1) X (boardSize+1)
    matrix<int> value;
};

#endif