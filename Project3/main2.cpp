#include <iostream>
#include <string>
#include <functional>
#include "hashTable.h"
using namespace std;

int main()
{
    int arr[] = {26, 37, 32, 12, 15, 28, 45, 6, 7};
    int arrSize = sizeof(arr)/sizeof(arr[1]);
    vector <int> A(arr, arr + arrSize);
    hashTable<int> newTable(A);


}