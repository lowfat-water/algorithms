#include <iostream>
#include <string>
#include "wordList.h"
using namespace std;

int main()
{
    //vector <string> temp(1);
    //temp.at(0) = "one";
    wordList practice;
    
    practice.readIn();
    practice.setVector();
    practice.printVector();
    int p = 0, r = practice.getSize()-1;
    cout << "r is " << r << endl;
 //   float seconds;
    //practice.insertionSort(seconds);

    practice.mergeSort(practice.(*B), p, r);

    practice.printVector();

    cout << practice;
    //cout << "insertion sort took " << seconds << " seconds" << endl; 
}