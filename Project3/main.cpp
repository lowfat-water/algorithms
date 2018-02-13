/*
Project 3a
Alina Rossi-Conaway and Dan Bartels
Octavia Camps
EECE2560
*/

#include <iostream>
#include <string>
#include <time.h>
#include "wordList.h"
#include "grid.h"
using namespace std;

void findMatches(wordList &newList, grid &newGrid); //searches the matrix for matches to the dictionary
string search(int sortMethod, wordList &newList, grid &newGrid, int r, int p); //takes in the grid file to search

int main()
{
    wordList list;
    list.readIn();
    grid input; //"input" is a grid
    int p = 0, r = list.getSize()-1;
    string file = search(2, list,  input, r, p); //1 for insertionSort, 2 for quickSort, 3 for mergeSort

    input.readIn(file); //read in the file


    findMatches(list, input); // run findMatches
}

string search(int sortMethod, wordList &newList, grid &newGrid, int r, int p) //sort the wordList, then print out words found in matrix
{
    newList.sort(sortMethod, p, r);
    cout << "Enter the name of the grid file you'd like to search: " << endl;
        string fileName;
    cin >> fileName; //input the fileName
    return fileName;
}

void findMatches(wordList &newList, grid &newGrid) //find wordList words in the grid
{
    clock_t startTime = clock(); //start counting

    int nRows = newGrid.getRows();
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
                char letter = newGrid.getChar(i, n); //find the character at each place in the grid
                arr.resize(arr.size()+1); //move forward in the grid
                arr.at(arr.size()-1) = letter;
                string word(arr.begin(), arr.end()); //print out the word
                newList.search(word);
                i++;
                if(i >= nRows)
                {
                    i = i % nRows; //wrap around the grid
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

    float diff = clock() - startTime; //calculate the time it took
    float seconds = diff / CLOCKS_PER_SEC;
    cout << "Searching this list took " << seconds << " seconds." << endl; //print out length of time
}
