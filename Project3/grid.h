#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class grid
{
    public:
        grid(int numRows = 1, int numCols = 1, char element = 'a');
        vector <char> & operator[] (int i);
        const vector<char> & operator[](int i) const;
        void readIn();
        int getRows() const;
        int getCols() const;
        char getChar(int i, int j);
        //friend ostream& operator << (ostream &out, const wordList &list);
    private:
        int nRows, nCols;
        vector <vector <char> > mat;

};

#endif
