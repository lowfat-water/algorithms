#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "grid.h"
#include "d_matrix.h"

using namespace std;

void grid::readIn(string fileName) //reads in from textfile "input.txt", specified by user
{
    ifstream fin; //creates ifstream objects
    int numRows, numCols;
    vector <char> row;
    char letter;
    fin.open(fileName.c_str()); //opens file
    if(!fin) //error handling
    {
        cerr << "file does not exist" << endl;
    }

    fin >> numRows >> numCols;
    charMatrix.resize(numRows, numCols);
    for(int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            fin >> charMatrix[i][j];
        }
    }
    fin.close(); //closes file
}

int grid::getRows() const //return the rows of the grid
{
    return charMatrix.rows();
}

int grid::getCols() const //return columns of the grid
{
    return charMatrix.rows();
}

char grid::getChar(int i, int j) //get the character at the current point in the grid
{
    return charMatrix[i][j];
}
