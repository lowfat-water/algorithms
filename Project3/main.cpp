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

    findMatches(list, input);
}

void findMatches(wordList &newList, grid &newGrid)
{   
    int nRows = newGrid.getRows();
    cout << "nRows is " << nRows << endl;
    int nCols = newGrid.getCols();
    int m = 4, n = 7;
    vector <char> arr(0);
    for (int m = 0; m < nRows; m++) //choosing starting point
    {
        for(int n = 0; n < nCols; n++) //choosing starting point
        {
            int i = m, j = n;
            while(arr.size() < nRows) //go south
            {
                char letter = newGrid.getChar(i, n);
                arr.resize(arr.size()+1);
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
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
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
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
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
                newList.search(word);
                j++;
                if(j >= nCols)
                {
                    j = j % nCols;
                }
            }

            arr.resize(0);

            while(arr.size() < nCols) // go west
            {
                char letter = newGrid.getChar(m, j);
                arr.resize(arr.size()+1);
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
                newList.search(word);
                j--;
                if(j < 0)
                {
                    j = nCols + j;
                }
            }

            arr.resize(0);
            
            while(arr.size() < nRows) //go northeast
            {
                char letter = newGrid.getChar(i, j);
                arr.resize(arr.size()+1);
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
                newList.search(word);
                i--; j++;

                if(j < 0)
                {
                    j = nCols + j;
                }
                else if(j >= nCols)
                {
                    j = j % nCols;
                }
                if(i < 0)
                {
                    i = nRows + i;
                }
                else if(i >= nRows)
                {
                    i = i % nRows;
                }
            }

            arr.resize(0);

            while(arr.size() < nRows) //go northwest
            {
                char letter = newGrid.getChar(i, j);
                arr.resize(arr.size()+1);
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
                newList.search(word);
                i--; j--;

                if(j < 0)
                {
                    j = nCols + j;
                }
                else if(j >= nCols)
                {
                    j = j % nCols;
                }
                if(i < 0)
                {
                    i = nRows + i;
                }
                else if(i >= nRows)
                {
                    i = i % nRows;
                }
            }

            arr.resize(0);
            
            while(arr.size() < nRows) //go southeast
            {
                char letter = newGrid.getChar(i, j);
                arr.resize(arr.size()+1);
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
                newList.search(word);
                i++; j++;

                if(j < 0)
                {
                    j = nCols + j;
                }
                else if(j >= nCols)
                {
                    j = j % nCols;
                }
                if(i < 0)
                {
                    i = nRows + i;
                }
                else if(i >= nRows)
                {
                    i = i % nRows;
                }
            }
            
            arr.resize(0);

            while(arr.size() < nRows) //go southwest
            {
                char letter = newGrid.getChar(i, j);
                arr.resize(arr.size()+1);
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end());
                newList.search(word);
                i++; j--;
                if(j < 0)
                {
                    j = nCols + j;
                }
                else if(j >= nCols)
                {
                    j = j % nCols;
                }
                if(i < 0)
                {
                    i = nRows + i;
                }
                else if(i >= nRows)
                {
                    i = i % nRows;
                }
            }
        }
    }
}