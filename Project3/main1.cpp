#include <iostream>
#include <vector>
#include <cmath>
#include "heap.h"
using namespace std;

int main()
{
    int array[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 28};
    
    int arraySize = sizeof(array)/sizeof(array[1]);
    vector <int> A(array, array+arraySize);
    heap<int> newHeap;
    newHeap.initializeMaxHeap(A);
    newHeap.print();
    newHeap.maxHeapify(1, arraySize);
    newHeap.print();
    //heap newHeap(size, value);
    int n = newHeap.getItem(1);
    //cout << n << endl;
    cout << newHeap[7] << endl;
    //int item = newHeap.getItem(1);
}