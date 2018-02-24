#include <vector>
#include <iostream>
#include <fstream>
#include  "d_matrix.h"
#include "board.h"

board::board(int squareSize)
{
    boardSize = squareSize * squareSize;
    value.resize(boardSize, boardSize);
}

void board::initialize(ifstream &fin)
{
    char ch;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            fin >> ch;

            if(ch != '.')
            {
                setCell(i, j, ch - '0');
            }

            else setCell(i, j, 0);
        }
    }
}

void board::setCell(int i, int j, int val)
{
    cout << "val is " << val << endl;
    value[i][j] = val;
}

void board::print()
{
    int i, j;
    for(i = 0; i < value.rows(); i++)
    {
        for(j = 0; j < value.cols(); j++)
        {
             cout << value[i][j] << " ";
        }
        cout << endl;
    }
}