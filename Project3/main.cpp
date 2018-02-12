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
    cout << "nRows is " << nRows << endl;
    int nCols = newGrid.getCols();
    int m = 9, n = 0;
    vector <char> arr(0);
    //for (int m = 0; m < nRows; m++) //choosing starting point
    {
      //  for(int n = 0; n < nCols; n++) //choosing starting point
        {
            int i = m, j = n;
            while(arr.size() < nRows) //go south
            {
                char letter = newGrid.getChar(i, n);
                arr.resize(arr.size()+1);
              //  cout << "array size is " << arr.size() << endl;
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
             //   cout << "word is " << word << endl;
                newList.search(word);
                i++;
                if(i >= nRows)
                {
                    i = i % nRows;
                }
            }

            arr.resize(0);

            while(arr.size() < nRows) //go north
            {
                char letter = newGrid.getChar(i, n);
                arr.resize(arr.size()+1);
              //  cout << "array size is " << arr.size() << endl;
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
             //   cout << "word is " << word << endl;
                newList.search(word);
                i--;
                if(i < 0)
                {
                    i = nRows + i;
                }
            }

            arr.resize(0);

            while(arr.size() < nCols) //go east
            {
                char letter = newGrid.getChar(m, j);
                arr.resize(arr.size()+1);
               // cout << "array size is " << arr.size() << endl;
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
              //  cout << "word is " << word << endl;
                newList.search(word);
                j++;
                if(j >= nCols)
                {
                    j = j % nCols;
                }
            }

            arr.resize(0);
        }
    }
 
}