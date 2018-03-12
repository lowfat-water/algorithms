/*
Project 4a
Alina Rossi-Conaway and Dan Bartels
Octavia Camps
EECE2560
*/

#include <iostream>
#include <vector>
#include "board.h"
#include "d_except.h"
#include <fstream>
#include <numeric>
using namespace std;

int main()
{
    ifstream fin;
    int squaresize = 3, counter = 0;
    vector <int> counters;
    board b1(squaresize); // squareSize=3 for a 9x9 board
    // Read the sample grid from the file.
    string fileName = "sudoku.txt"; // change this input name to read from other input files!
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
            b1.clear();
            b1.initialize(fin); //initializes board with input file
            b1.print(); //prints board
        //    b1.printConflicts(); //prints conflicts

            if (b1.solve(counter))
                b1.print();
    
        if (b1.isSolved()) //if board has been solved
        {    
            cout << "Board has been solved." << endl;
            cout << "Solving board took " << counter << " recursions." << endl << endl;
            counters.push_back(counter);
            counter = 0;
        }
        else cout << "Board has not been solved." << endl;
        }
    }

    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    fin.close(); //closes file


    int avg = (accumulate(counters.begin(), counters.end(), 0)) / counters.size();
    cout << "The average solving time for this board set is " << avg << " recursions." << endl;
    //b1.clearCell(4,5); //clears cell (4,5)
    //b1.print(); //prints updated board
    //b1.printConflicts(); //prints updated conflicts


}
