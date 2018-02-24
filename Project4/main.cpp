#include <iostream>
#include <vector>
#include "board.h"
#include "d_except.h"
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;

    // Read the sample grid from the file.
    string fileName = "sudoku1.txt";
    fin.open(fileName.c_str());
    int squareSize = 3;
    if (!fin)
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }
    try
    {
        board b1(squareSize); // squareSize=3 for a 9x9 board
        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            //b1.print();
            //b1.printConflicts();
        }
        b1.print();
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    fin.close();
}