#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include "wordList.h"

using namespace std;

void wordList::readIn()
{
    ifstream fin;
    string word, fileName = "wordList.txt";
    fin.open(fileName.c_str());
    if(!fin)
    {
        cerr << "file does not exist" << endl;
    }
    while(fin >> word)
    {
        dictionary.push_back(word);
    }
    fin.close();
}

void wordList::insertionSort(float &seconds)
{
    clock_t startTime = clock(), endTime;
    for(int j = 1; j < dictionary.size(); j++)
    {
        string key = dictionary.at(j);
        int i = j - 1;
        while (i >= 0 && dictionary.at(i) > key)
        {
            dictionary.at(i+1) = dictionary.at(i);
            i = i-1;
        }
        dictionary.at(i+1) = key;
    }

    cout << "the starting time was: " << startTime << endl;
    cout << "the clock now is: " << clock() << endl;
    int diff = clock() - startTime;
    //cout << diff << endl;
    seconds = diff/CLOCKS_PER_SEC;
    cout << seconds << endl;
}

ostream& operator << (ostream &out, const wordList &list)
{
    cout << "printing . . ." << endl;
    for (int i = 0; i != list.dictionary.size(); i++)
    {
        out << list.dictionary.at(i) << endl;
    }
    return out;
}