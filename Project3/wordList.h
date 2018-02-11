#include <iostream>
#include <vector>
#include <string>
#ifndef WORDLIST_H
#define WORDLIST_H
using namespace std;

class wordList
{
    public:
        //wordList(vector <string> &temp):B(temp){};
        int getSize();
        void readIn();
        friend ostream& operator << (ostream &out, const wordList &list);
        void insertionSort(float &seconds);
        void mergeSort(vector <string> &B, int p, int r);
        void merge(vector <string> &B, int p, int q, int r);
        vector <string> * B;
        void setVector();
        void printVector();
        
    private:
        vector <string> dictionary;
};

#endif