#include <iostream>
#include <vector>
#include <string>
#ifndef WORDLIST_H
#define WORDLIST_H
using namespace std;

class wordList
{
    public:
        int getSize();
        void readIn();
        void exchange(vector <string> &A, int n, int m);
        void sort(int n, int p, int r);
        void insertionSort();
        void search(string key);
        friend ostream& operator << (ostream &out, wordList &list);

    private:
        vector <string> dictionary;
        void quickSort(vector <string> &A, int p, int r);
        int partition(vector <string> &A, int p, int r);
        void mergeSort(vector <string> &B, int p, int r);
        void merge(vector <string> &B, int p, int q, int r);
        void heapSort();
        int binarySearch (vector <string> &A, string key);
        int binarySearchAux (vector <string> &A, string key, int right, int left);
};

#endif
