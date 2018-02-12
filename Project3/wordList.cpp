#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <cmath>
#include "wordList.h"

using namespace std;

int wordList::getSize() //returns size of dictionary for use in initializing r
{
    return dictionary.size();
}

void wordList::readIn() //reads in from textfile "wordlist.txt"
{
    int i = 0;
    ifstream fin; //creates ifstream objects
    string word, fileName = "wordlist.txt";
    fin.open(fileName.c_str()); //opens file
    if(!fin) //error handling
    {
        cerr << "file does not exist" << endl;
    }
    while(fin >> word) //stores word from file in a string
    {
        dictionary.resize(i+1);
        dictionary.at(i)=word; //adds word to dictionary vector
        i+=1;
    }
    fin.close(); //closes file
}

void wordList::insertionSort() //takes in a reference to seconds as an argument to be printed in main
{
    clock_t startTime = clock(); //records start time
    for(int j = 1; j < dictionary.size(); j++) //outer loop iterates over vector
    {
        string key = dictionary.at(j); //stores key as element to be checked
        int i = j - 1;
        while (i >= 0 && dictionary.at(i) > key) //when items are larger than the key
        {
            dictionary.at(i+1) = dictionary.at(i); //shift them to the right of key
            i = i-1; //moves backwards
        }
        dictionary.at(i+1) = key; //if the value at i is smaller than the key, inserts key to the right of it
    }


    int diff = clock() - startTime; //number of cycles that have passed since beginning of sort
    seconds = diff/CLOCKS_PER_SEC; //converts cycles to seconds
}

void wordList::sort(int n, int p, int r)
{
    if(n == 1) //calls insertion sort
    {
        clock_t startTime = clock();
        insertionSort();
    }   
    int startTime = clock();
    mergeSort(dictionary, p, r);
    float diff = clock()-startTime;
    float seconds = diff/CLOCKS_PER_SEC;
    cout << "Sorting via mergeSort took " << seconds << " seconds." << endl;
}

void wordList::mergeSort(vector <string> &B, int p, int r)
{
    if (p < r)
    {
        int q = floor((p+r)/2);
       // cout << "q is " << q << endl;
        mergeSort(B, p, q);
        mergeSort(B, q+1, r);
        merge(B, p, q, r);
    }
}

void wordList::merge(vector <string> &B, int p, int q, int r)
{
    //cout << "sorting . . ." << endl;
    //cout << "p is " << p << endl;
    //cout << "q is " << q << endl;
    int n1 = q - p + 1;
    int n2 = r - q;

    vector <string> L(n1+1);
    vector <string> R(n2+1);

    for(int i = 0; i <= n1-1; i++)
    {
        L.at(i) = B.at(p+i);
    }

    for(int j = 0; j <= n2-1; j++)
    {
        R.at(j) = B.at(q+j+1);
    }
    L.at(n1) = "zzzzzzzzzzzz";
    R.at(n2) = "zzzzzzzzzzzz";

    int i = 0, j = 0;

    for(int k = p; k <= r; k++)
    {
        if (L.at(i) <= R.at(j))
        {
            B.at(k) = L.at(i);
            i = i + 1;
        }
        else
        {
            B.at(k) = R.at(j);
            j = j + 1;
        }
    }
}

ostream& operator << (ostream &out, const wordList &list)
{
    cout << "printing . . ." << endl;
    for (int i = 0; i != 3; i++)
    {
        out << list.dictionary.at(i) << endl;
    }
    return out;
}

void wordList::sort1(int p, int r)
{
    quickSort(dictionary, p, r);
}

void wordList::quickSort(vector <string> &A, int p, int r)
{
    cout << "sorting . . ." << endl << endl;
    cout << "p is " << p << endl;
    if (p < r)
    {
        int q = partition(A, p, r);
        cout << "q is " << q << endl;
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int wordList::partition(vector <string> &A, int p, int r)
{

    string x = A.at(r);

    int i = p-1;

    for(int j = p; j < r; j++)
    {
        //cout << "j is " << j << endl;

        if (A.at(j) <= x)
        {
            i = i + 1;
            exchange(A, i, j);
        }
    }
    exchange(A, i+1, r);
    return i+1; //pivot location
}
void wordList::search(string key)
{
    int location = binarySearch(dictionary, key);
    cout << "word " << key << " located at " << location;
}
int wordList::binarySearch(vector <string> &A, string key)
{
    return binarySearchAux(A, key, 0, A.size()-1);
}
int wordList::binarySearchAux(vector <string> &A, string key, int left, int right)
{
   // cout << "left is " << left << endl;
   // cout << "right is " << right << endl;
    if(right < left)
        return -1;
    int mid = (left+right)/2;
    if (key == A.at(mid))
        return mid;
    else if (key < A.at(mid))
        return binarySearchAux(A, key, left, mid-1);
    else
        return binarySearchAux(A, key, mid+1, right);
}
void wordList::exchange(vector <string> &A, int n, int m)
{
        string temp = A.at(n);
        A.at(n) = A.at(m);
        A.at(m) = temp;
}
