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
    newHeap.initializeHeap(A);
    newHeap.print();
    newHeap.buildMinHeap();
    newHeap.print();
}