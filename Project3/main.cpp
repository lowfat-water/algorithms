#include <iostream>
#include <string>
#include <time.h>
#include "wordList.h"
using namespace std;

int main()
{
    wordList practice;
    practice.readIn();
    cout << practice;
    int p = 0, r = practice.getSize()-1;

    cout << "r is " << r << endl;
    //practice.sort(p, r);

    clock_t startTime = clock(); //records start time before mergeSort
    cout << "start time: " << startTime << endl;
    //practice.sort(p,r);
    practice.sort1(p,r);
    //cout << practice;
    //float seconds;
    //practice.insertionSort(seconds);
    float diff = clock() - startTime; //number of cycles that have passed since beginning of sort
    cout << "end time: " << clock() << endl;
    float seconds = diff/CLOCKS_PER_SEC; //converts cycles to seconds
    //cout << practice;
    cout << "Sorting via quickSort took " << seconds << " seconds." << endl;
    

//  cout << practice << endl;
//   cout << "insertion sort took " << seconds << " seconds" << endl; 
}