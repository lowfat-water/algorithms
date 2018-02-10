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

ostream& operator << (ostream &out, const wordList &list)
{
    for (int i = 0; i != list.dictionary.size(); i++)
    {
        out << list.dictionary.at(i) << endl;
    }
    return out;
}