#include <iostream>
#include <vector>
#include <cmath>
#include "heap.h"
using namespace std;

int main()
{
    int size = 5, value = 2;
    heap <int> newHeap(size, value);
    cout << newHeap[1];
    //int item = newHeap.getItem(1);
}