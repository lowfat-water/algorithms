#include <iostream>
#include <vector>
#include <cmath>
#include "heap.h"
using namespace std;

int main()
{
    int array[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 28};
    int size = sizeof(array)/sizeof(array[0]);
    cout << "size is " << size << endl;
    vector <int> A(size);
    for(int i = 0; i < size; i++)
    {
        A.at(i) = array[i];
    }
    heap <int> newHeap;
    newHeap.assignVector(A);
}