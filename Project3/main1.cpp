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
    int size = 5, value = 2;
    heap<int> newHeap;
    newHeap.assignVector(A);

    //heap newHeap(size, value);
    int n = newHeap.getItem(1);
    //cout << n << endl;
    cout << newHeap[7] << endl;
    //int item = newHeap.getItem(1);
}