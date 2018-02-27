#include <vector>
#include <iostream>
#include <fstream>
#include  "d_matrix.h"
#include "board.h"

board::board(int squareSize)
{
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

bool board::square(int i, int j)
{
  int vsquare = i/3;
	int hsquare = j/3;
  for (int row = vsquare * 3; row < (vsquare*3 + 3); row++)
  {
    for (int col = hsquare * 3; col < (hsquare*3 + 3); col++)
    {
			if (!(row == vsquare && col == hsquare))
      {
				if (value[ i ][ j ] == sqConflicts[row][col])
        {
				return true;
      }
    }
  }
}
}

void board::setCell(int i, int j, int val)
{
    if(val == 0)
    {
        value[i][j] = val;
    }
    //cout << "val is " << val << endl;
    else if( !rowConflicts[i][val] && !colConflicts[val][j])
    {
        value[i][j] = val;
        rowConflicts[i][val] = true;
        colConflicts[val][j] = true;
        square(i,j);
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
