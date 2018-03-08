#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "d_matrix.h"

class board
// Stores the entire Sudoku board
{
    public:
        int squareSize;
        int boardSize;
        board(int squaresize);
        void initialize(ifstream &fin);
        int getSquare(int i, int j);
        void setCell(int i,int j, int val);
        bool checkCell(int i, int j, int val);
        void print();
        void printConflicts();
        void clearCell(int i, int j);
        bool isBlank(int, int);
        bool isSolved();
        bool solve();
        bool findEmpty(int &row, int &col);

        int getCell(int, int);
        void clear();

    private:
    // The following matrices go from 1 to boardSize in each
    // dimension. I.e. they are each (boardSize+1) X (boardSize+1)
        matrix<int> value;
        matrix <bool> rowConflicts;
        matrix <bool> colConflicts;
        matrix <bool> sqConflicts;
};

#endif
