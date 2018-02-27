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
    if (!fin) // error handling
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }
    try
    {
        while (fin && fin.peek() != 'Z') //while we're not at the end of the file
        {
            b1.initialize(fin); //initializes board with input file
            b1.print(); //prints board
            b1.printConflicts(); //prints conflicts
        }
    }

    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    fin.close(); //closes file

    b1.clearCell(4,5); //clears cell (4,5)
    b1.print(); //prints updated board
    b1.printConflicts(); //prints updated conflicts

    if (b1.isSolved()) //if board has been solved
        cout << "Board has been solved." << endl;
    else cout << "Board has not been solved." << endl;
}