#include <iostream>
#include <vector>
#include <string>
#ifndef WORDLIST_H
#define WORDLIST_H
using namespace std;

class wordList
{
    public:
        void readIn();
        //friend ostream& operator << (ostream & out, const wordList &)
        void printList();
    private:
        vector <string> dictionary;
};

#endif