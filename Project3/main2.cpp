#include <iostream>
#include <string>
#include <functional>
#include "hashTable.h"
#include "wordList.h"
using namespace std;

int main()
{
    wordList list;
    list.readIn();
    hashTable <string> table(list.getVector());
    int size = list.getSize();
    for(int i = 0; i < size/3; i++)
        table.printVector(i);
    string item = "seduction";
    table.deleteItem(item);
    cout << " enter y to proceed " << endl;
    char input;
    cin >> input;
    if(input == 'y')
    {
        for(int i = 0; i < size/3; i++)
        table.printVector(i);
    }
    string item1 = "undifferentiated";
    table.inList(item);
    table.inList(item1);
    /*
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

    string item = "bear";
    strTable.deleteItem(item);

    for(int i = 0; i < arrSize1/3; i++)
    strTable.printVector(i);
    */

    
}