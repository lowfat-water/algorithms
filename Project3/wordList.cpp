#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "wordList.h"

using namespace std;

void wordList::readIn()
{
    ifstream fin;
    string word, fileName = "wordlist.txt";
    fin.open(fileName.c_str());
    if(!fin)
    {
        cerr << "file does not exist" << endl;
    }
    //string test; 
    //getline(fin, test);
    //cout << test << endl;
    while(fin >> word)
    {
        dictionary.push_back(word);
    }
    fin.close();
}

void wordList::printList()
{ 
    for (int i = 0; i != dictionary.size(); i++)
    {
        cout << dictionary.at(i) << endl;
    }
}