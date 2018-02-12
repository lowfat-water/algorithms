#include <iostream>
#include <string>
#include <time.h>
#include "wordList.h"
#include "grid.h"
using namespace std;

int main()
{
    grid matrix;
    matrix.readIn();
    cout << "the number of rows is " << matrix.getRows() << endl;
    cout << "the number of columns is " << matrix.getCols() << endl;
    cout << "the value at 2,3 is " << matrix.getChar(2,3) << endl;
}