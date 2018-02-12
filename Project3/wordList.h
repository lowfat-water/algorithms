#include <iostream>
#include <vector>
#include <string>
#ifndef WORDLIST_H
#define WORDLIST_H
using namespace std;

class wordList
{
    public:
        //void setVector();
        //void printVector();
        int getSize();
        void readIn();
        friend ostream& operator << (ostream &out, const wordList &list);
        void insertionSort(float &seconds);
        void sort(int p, int r);
        void sort1(int p, int r);
        void exchange(vector <string> &A, int n, int m);
        void search(string key);

    private:
        vector <string> dictionary;
        void mergeSort(vector <string> &B, int p, int r);
        void merge(vector <string> &B, int p, int q, int r);
        void quickSort(vector <string> &A, int p, int r);
        int partition(vector <string> &A, int p, int r);
        int binarySearch (vector <string> &A, string key);
        int binarySearchAux (vector <string> &A, string key, int right, int left);
};

#endif
