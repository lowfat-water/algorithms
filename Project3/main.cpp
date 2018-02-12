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
    list.sort(2, p, r);
    grid input;
    input.readIn();
    cout << "the number of rows is " << input.getRows() << endl;
    cout << "the number of columns is " << input.getCols() << endl;
    cout << "the value at 2,3 is " << input.getChar(2,3) << endl;

    findMatches(list, input);
}

void findMatches(wordList &newList, grid &newGrid)
{   
    int nRows = newGrid.getRows();
    int nCols = newGrid.getCols();
    int m = 0, n = 0;
    vector <char> arr(1);
    //for (int m = 0; m < nRows; m++) //choosing starting point
    {
      //  for(int n = 0; n < nCols; n++) //choosing starting point
        {
            for(int i = m; i < nRows; i++) //go south
            {
                char letter = newGrid.getChar(i, n);
                arr.resize(i+1);
                arr.at(i) = letter;
                string word(arr.begin(), arr.end());
                cout << "word is " << word << endl;
                newList.search(word);
            }
            for(int j = n; j < nCols; j++) //go east
            {
                char letter = newGrid.getChar(m, j);
                arr.resize(j+1);
                arr.at(j) = letter;
                string word(arr.begin(), arr.end());
                cout << "word is " << word << endl;
                newList.search(word);
            }
            for (int j = n; j < nCols; j--) //go west
            {
                char letter = newGrid.getChar(m, j);
                
            }
        }
    }
 
}