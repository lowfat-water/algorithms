#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "d_matrix.h"

template <typename T>
class board
// Stores the entire Sudoku board
{
    public:
        board(int);
        void clear();
        void initialize(ifstream &fin);
        void print();
        bool isBlank(int, int);
        T getCell(int, int);
        void setCell(int i,int j, T val);
    private:
    // The following matrices go from 1 to boardSize in each
    // dimension. I.e. they are each (boardSize+1) X (boardSize+1)
    matrix<T> value;
};