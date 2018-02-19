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
    newTable.printVector(1);


    string arrString[] = {"cat", "mouse", "bear", "zebra", "elephant", "lion", "eagle", "hippopotomus","lemur", "saggitarius", "capricorn"};
    int arrSize1 = sizeof(arrString)/sizeof(arrString[1]);
    vector <string> B(arrString, arrString+arrSize1);
    hashTable <string> strTable(B);
    for(int i = 0; i < arrSize1/3; i++)
        strTable.printVector(i);

    int item = 3000;

    hash<int> intHash;
    hash<string> strHash;
    size_t value1 = strHash(arrString[0]) % 3;
    
    size_t value = intHash(item) % 222;

    cout << "the hash value for " << item << " is " << value << endl;
    cout << "the hash value for " << arrString[1] << " is " << value1 << endl;
    
}