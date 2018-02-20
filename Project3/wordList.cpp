#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <cmath>
#include "wordList.h"
#include "heap.h"

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

void wordList::exchange(vector <string> &A, int n, int m) //switch the positions of n and m
{
        string temp = A.at(n);
        A.at(n) = A.at(m);
        A.at(m) = temp;
}

void wordList::sort(int n, int p, int r)
{
    clock_t startTime = clock();

    if(n == 1) //calls insertionSort
    {
        insertionSort();
        float diff = clock() - startTime; //number of cycles that have passed since beginning of sort
        float seconds = diff/CLOCKS_PER_SEC; //converts cycles to seconds
        cout << "Sorting via insertionSort took " << seconds << " seconds." << endl;
    }
    else if(n == 2) //calls quickSort
    {
        quickSort(dictionary, p, r);
        float diff = clock() - startTime; //number of cycles that have passed since beginning of sort
        float seconds = diff/CLOCKS_PER_SEC; //converts cycles to seconds
        cout << "Sorting via quickSort took " << seconds << " seconds." << endl;
    }
    else if(n == 3) //calls mergeSort
    {
        mergeSort(dictionary, p, r);
        float diff = clock() - startTime;
        float seconds = diff/CLOCKS_PER_SEC;
        cout << "Sorting via mergeSort took " << seconds << " seconds." << endl;
    }
    else if(n == 4) //calls heapSort 
    {
        heapSort();
        float diff = clock() - startTime;
        float seconds = diff/CLOCKS_PER_SEC;
        cout << *this << endl; //prints sorted list
        cout << "Sorting vis heapSort took " << seconds << " seconds." << endl;
    }
    else
        cerr << "Invalid input parameter. Please input n=1, 2, 3, or 4." << endl;
}

void wordList::insertionSort() //takes in a reference to seconds as an argument to be printed in main
{
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
}

void wordList::inList(string key) //public function to call binarySearch
{
    int location = binarySearch(dictionary, key); //call to private binary search to search dictionary for key
    if(location != (-1))
        cout << "Word " << key << " located at location " << location << " in list." << endl;
}

vector <string> &wordList::getVector()
{
    return dictionary;
}

void wordList::quickSort(vector <string> &A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r); //calls partition
        quickSort(A, p, q-1); //calls itself for first half of list
        quickSort(A, q+1, r); //calls itself for 2nd half of list
    }
}

int wordList::partition(vector <string> &A, int p, int r) //partition and split the list
{

    string x = A.at(r); //pivot

    int i = p-1;

    for(int j = p; j < r; j++)
    {
        if (A.at(j) <= x) //if less than pivot
        {
            i = i + 1; //increase size of left list
            exchange(A, i, j); //put it on the left 
        }
    }
    exchange(A, i+1, r); //put pivot in middle
    return i+1; //pivot location
}

void wordList::mergeSort(vector <string> &B, int p, int r) 
{
    if (p < r)
    {
        int q = floor((p+r)/2);
        mergeSort(B, p, q); //call itself for first half of list
        mergeSort(B, q+1, r); //for second half
        merge(B, p, q, r); //merge two halves
    }
}

void wordList::merge(vector <string> &B, int p, int q, int r) //merge the lists back together
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector <string> L(n1+1); //new vectors for left and right lists
    vector <string> R(n2+1);

    for(int i = 0; i <= n1-1; i++) //copies left half into L
    {
        L.at(i) = B.at(p+i);
    }

    for(int j = 0; j <= n2-1; j++) //copies right half into R
    {
        R.at(j) = B.at(q+j+1);
    }
    
    L.at(n1) = "zzzzzzzzzzzz"; //puts "large word" for comparison at the end
    R.at(n2) = "zzzzzzzzzzzz";

    int i = 0, j = 0;

    for(int k = p; k <= r; k++) //combines L and R into B, sorted
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

void wordList::heapSort()
{
    heap <string> dictionaryHeap;
    dictionaryHeap.initializeHeap(dictionary);
    dictionaryHeap.buildMaxHeap();
    dictionaryHeap.heapSort();
    dictionary = dictionaryHeap.getVector();
}

int wordList::binarySearch(vector <string> &A, string key) //recursively binary search moving through the list
{
    return binarySearchAux(A, key, 0, A.size()-1); 
}

int wordList::binarySearchAux(vector <string> &A, string key, int left, int right) //searches sorted list by calling itself for smaller lists
{
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

ostream& operator << (ostream &out, wordList &list) //overloaded << operator
{
    cout << "printing . . ." << endl;
    for (int i = 0; i != list.getSize(); i++)
    {
        out << list.dictionary.at(i) << endl;
    }
    return out;
}
