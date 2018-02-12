#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "grid.h"

using namespace std;

grid::grid(int numRows, int numCols, char element)
{
    nRows = numRows;
    nCols = numCols;
    //mat(numRows, numCols, element);
}

vector<char>& grid::operator[](int i)
{
    if (i < 0 || i >= nRows)
    {
        cerr << "invalid row index" << endl;
    }
    return mat[i];
}

const vector<char>& grid::operator[] (int i) const
{
    if (i < 0 || i >= nRows)
    {
        cerr << "invalid row index" << endl;
    }
    return mat[i];
}

void grid::readIn() //reads in from textfile "wordlist.txt"
{
    ifstream fin; //creates ifstream objects
    int i=0, num; 
    string line;
    vector <char> row;
    string fileName = "input15.txt";
    char letter;
    fin.open(fileName.c_str()); //opens file
    if(!fin) //error handling
    {
        cerr << "file does not exist" << endl;
    }

    fin >> nRows >> nCols;
    for(i = 0, i < nRows; i++)
    {
        for (j = 0, j < nCols, j++)
        {
            fin >> charMatrix[i][j];
        }
    }
    while(fin) //stores word from file in a string
    {
        if(fin >> num)
        {
            nRows = num;
            nCols = num;
        }
        else
        {
            getline(fin, line);
            vector <char> row(line.begin(),line.end());
            mat[i] = row;
            i++;
        }
    } 
    fin.close(); //closes file
}

int grid::getRows() const
{
    return nRows;
}
int grid::getCols() const
{
    return nCols;
}
char grid::getChar(int i, int j)
{
    return mat[i][j];
}
