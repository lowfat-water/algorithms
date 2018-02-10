#include <iostream>
#include <string>
#include "wordList.h"
using namespace std;

int main()
{
    wordList practice;
    practice.readIn();
    //practice.printList();
    float seconds;
    practice.insertionSort(seconds);
    cout << practice;
    cout << "insertion sort took " << seconds << " seconds" << endl; 
}