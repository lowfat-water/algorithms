#include <iostream>
#include <string>
#include <time.h>
#include "wordList.h"
using namespace std;

int main()
{
    //vector <string> temp(1);
    //temp.at(0) = "one";
    wordList practice;
    
    practice.readIn();
    cout << practice;
    //practice.setVector();
    //practice.printVector();

    
    int p = 0, r = practice.getSize()-1;
    cout << "r is " << r << endl;
    float seconds;
    //practice.insertionSort(seconds);
    clock_t startTime = clock(); //records start time before mergeSort

    practice.mergeSort(practice.dictionary, p, r);
    
        int diff = clock() - startTime; //number of cycles that have passed since beginning of sort
        //float seconds = diff/CLOCKS_PER_SEC; //converts cycles to seconds
    cout << practice;
        //cout << "Sorting via mergeSort took " << seconds << " seconds." << endl;
    
    //cout << "insertion sort took " << seconds << " seconds" << endl; 
}