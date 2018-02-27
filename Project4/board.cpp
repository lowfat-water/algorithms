#include <vector>
#include <iostream>
#include <fstream>
#include  "d_matrix.h"
#include "board.h"

board::board(int squaresize)
{
    squareSize = squaresize;
    boardSize = squareSize * squareSize;
    value.resize(boardSize, boardSize);
    rowConflicts.resize(boardSize, boardSize);
    colConflicts.resize(boardSize, boardSize);
    sqConflicts.resize(boardSize, boardSize);

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            rowConflicts[i][j] = false;
            colConflicts[i][j] = false;
            sqConflicts[i][j] = false;
        }
    }
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

int board::getSquare(int i, int j)
{
    return squareSize * ( i / squareSize) + (j / squareSize);  
}

void board::setCell(int i, int j, int val)
{
    if(val == 0)
    {
        value[i][j] = val;
    }
    else if( !rowConflicts[i][val - 1] && !colConflicts[val - 1][j] && !sqConflicts[getSquare(i,j)][val-1])
    {
        value[i][j] = val;
        rowConflicts[i][val - 1] = true;
        colConflicts[val - 1][j] = true;
        sqConflicts[getSquare(i, j)][val - 1] = true;
    }
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
    cout << endl;
}

void board::printConflicts()
{
    cout << "Row Conflicts: " << endl;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(!rowConflicts[i][j])
                cout << 'F' << " ";
            else cout << 'T' << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Column Conflicts: " << endl;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(!colConflicts[i][j])
                cout << 'F' << " ";
            else cout << 'T' << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Square Conflicts: " << endl;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(!sqConflicts[i][j])
                cout << 'F' << " ";
            else cout << 'T' << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void board::clearCell(int i, int j)
{
    int temp = value[i][j];
    value[i][j] = 0;
    rowConflicts[i][temp - 1] = false;
    colConflicts[temp - 1][j] = false;
    sqConflicts[getSquare(i, j)][temp - 1] = false;
}
