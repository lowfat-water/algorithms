#include <vector>
#include <iostream>
#include <fstream>
#include  "d_matrix.h"
#include "board.h"

board::board(int squareSize)
{
    value.resize(1, 0);
}

void board::initialize(ifstream &fin)
{
    cout << "initializing board" << endl;
    char ch;
    fin >> ch;
    cout << "fin is " << ch << endl;
    int i = value.rows();
    cout << "i is " << i << endl;
    int j = value[i-1].size();
    cout << "j is " << j << endl;
    if (j < 9)
    {
        value.resize(i, j+1);
        cout << "number of rows is " << value.rows() << endl;
        cout << "number of cols is " << value.cols() << endl;
    }
    else if(j == 9)
    {
        //j = value[i].size()-1;
        value.resize(i+1, 9);
    }

    if(ch == '.')
    {
        cout << "character is " << ch << endl;
        setCell(i-1, j-1, 0);
    }

    else
    {
        int digit = ch - '0';
        cout << "digit is " << digit << endl;
        setCell(i-1, j-1, digit);
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