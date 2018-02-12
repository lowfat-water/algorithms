#include <iostream>
#include <string>
#include <time.h>
#include "wordList.h"
#include "grid.h"
using namespace std;

void findMatches(wordList &newList, grid &newGrid);

int main()
{
    wordList list;
    list.readIn();
    int p = 0, r = list.getSize()-1;
    list.sort(p, r);
    grid input;
    input.readIn();
    cout << "the number of rows is " << input.getRows() << endl;
    cout << "the number of columns is " << input.getCols() << endl;
    cout << "the value at 2,3 is " << input.getChar(2,3) << endl;

    findMatches(list, input);

}

void findMatches(wordList &newList, grid &newGrid)
{
    char n = newGrid.getChar(0,0);
    vector <char> w1;
        w1.push_back(n);
    string word1(w1.begin(), w1.end());
    newList.search(word1);
    //going east   
}