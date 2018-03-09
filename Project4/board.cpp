#include <vector>
#include <iostream>
#include <fstream>
#include  "d_matrix.h"
#include "board.h"

board::board(int squaresize)
{
    squareSize = squaresize; //initializing member variables
    boardSize = squareSize * squareSize;
    value.resize(boardSize, boardSize); //resizes board matrix
    rowConflicts.resize(boardSize, boardSize); //resizes conflict matrices
    colConflicts.resize(boardSize, boardSize);
    sqConflicts.resize(boardSize, boardSize);

    for (int i = 0; i < boardSize; i++) //initializes conflict matrices to false
    {
        for (int j = 0; j < boardSize; j++)
        {
            rowConflicts[i][j] = false;
            colConflicts[i][j] = false;
            sqConflicts[i][j] = false;
        }
    }
}

void board::clear()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            value[i][j] = 0;
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
            fin >> ch; //reads in from file

            if(ch != '.') //if there is a number
            {
                setCell(i, j, ch - '0'); //sets cell to the integer that ch represents
            }

        //      else setCell(i, j, 0); //sets cell to 0 if ch is a .
        }
    }
}

int board::getSquare(int i, int j)
{
    return squareSize * ( i / squareSize) + (j / squareSize); //returns square number based on cell indices
}

void board::setCell(int i, int j, int val)
{
    cout << "assigning value " << val << " to cell " << i << ", " << j << endl;
    if(val == 0)
    {
        value[i][j] = val;
    }
    else if (val != 0)//if(checkCell(i, j, val)) // checks conflicts for value
    {
        value[i][j] = val; // sets cell 
        rowConflicts[i][val - 1] = true; //updates conflicts
        colConflicts[val - 1][j] = true;
        sqConflicts[getSquare(i, j)][val - 1] = true;
    }
}

bool board::checkCell(int i, int j, int val)
{
    cout << "checking cell " << i << ", " << j << " for value " << val << endl;
    if( !rowConflicts[i][val - 1] && !colConflicts[val - 1][j] && !sqConflicts[getSquare(i,j)][val-1])
    {    
        cout << "valid." << endl;
        return true;
    }
    else 
    {
        cout << "invalid." << endl;
        return false;
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
    int temp = value[i][j]; //stores value
    value[i][j] = 0; //clears cell 
    rowConflicts[i][temp - 1] = false; //updates conflicts
    colConflicts[temp - 1][j] = false;
    sqConflicts[getSquare(i, j)][temp - 1] = false;
}

bool board::isBlank(int i, int j)
{
    if (i < 0 || j < 0 || i >= boardSize || j >= boardSize)
        throw rangeError("Index out of range");
    if (value[i][j] == 0)
        return true;
    else return false;
}

bool board::isSolved() //checks if board is solved
{
    bool solved;

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (isBlank(i, j))
                return false;
        }
    }

    return true;
}

bool board::solve()
{
    int row, col;

    if (!findEmpty(row, col))
    {
        return true; //done!   
    }        
//    cout << "row is " << row << endl;
//    cout << "col is " << col << endl;

    for (int digit = 1; digit <= boardSize; digit++)
    {
        if(checkCell(row, col, digit) == true)
        {
            setCell(row, col, digit);

            if (solve() == true)
            {    
                return true;
            }
            cout << "backtracking for cell " << row << ", " << col << endl;
            clearCell(row, col);
        }   
    }
   return false;

}

bool board::findEmpty(int &row, int &col)
{
    for (row = 0; row < boardSize; row++)
    {   
        for (col = 0; col < boardSize; col++)
        {
            if (getCell(row, col) == 0)
                return true;
        }
    }
    return false;
}

int board::getCell(int row, int col)
{
    return value[row][col];
}