#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <cmath>
#include "wordList.h"

using namespace std;

void wordList::setVector() //assigns reference member ptr to the private member dictionary for use later
{
    ptr = &dictionary;
}

void wordList::printVector()
{
    for(int i = 0; i < ptr->size(); i++)
    {
        cout << ptr->at(i) << endl;
    }
}

int wordList::getSize() //returns size of dictionary for use in initializing r
{
    return dictionary.size();
}

void wordList::readIn() //reads in from textfile "wordlist.txt"
{
    int i = 1;
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

void wordList::insertionSort(float &seconds) //takes in a reference to seconds as an argument to be printed in main
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
    dictionary = B;
}

void wordList::merge(vector <string> &B, int p, int q, int r)
{
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
    for (int i = 0; i != list.dictionary.size(); i++)
    {
        out << list.dictionary.at(i) << endl;
    }
    return out;
}
