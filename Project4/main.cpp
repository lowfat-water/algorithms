#include <iostream>
#include <vector>
#include "board.h"
#include "d_except.h"
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    int squaresize = 3;
    board b1(squaresize); // squareSize=3 for a 9x9 board
    // Read the sample grid from the file.
    string fileName = "sudoku1.txt";
    fin.open(fileName.c_str());
    if (!fin)
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }
    try
    {
        while (fin && fin.peek() != 'Z')
        {
            b1.initialize(fin);
            b1.print();
            b1.printConflicts();
        }
    }

    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    fin.close();

    b1.clearCell(4,5);
    b1.print();
    b1.printConflicts();

    if (b1.isSolved())
        cout << "Board has been solved." << endl;
    else cout << "Board has not been solved." << endl;
}