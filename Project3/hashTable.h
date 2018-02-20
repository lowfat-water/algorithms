#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <functional>
#include "d_except.h"
using namespace std;

template <typename T>
class hashTable
{
    public:
        hashTable(vector <T> newVector);
        void addItem(T &item);
        void deleteItem(T &item);
        void inList(T &item);
        int hash(T &item);
        void resize(int numRows, int numCols);
        void printVector(int hashKey);


    private:
        vector<vector<T> > table;
        int nSlots, nItems;
};

template <typename T>
hashTable<T>::hashTable(vector <T> newVector)
{
    nItems = newVector.size();
    nSlots = nItems/3;
    table.resize(nSlots);
    for(int i = 0; i < nItems; i++)
    {
        addItem(newVector.at(i));
    }
}

template <typename T>
void hashTable<T>::addItem(T &item)
{
    int hashKey = hash(item);
    if (hashKey < nSlots)
    {
        table[hashKey].push_back(item);
    }
}

template <typename T>
void hashTable<T>::deleteItem(T &item)
{
    int hashKey = hash(item);
    int index = 0;
    int size = table[hashKey].size();
    while(table[hashKey].at(index) != item)
        index++;
    table[hashKey].erase(table[hashKey].begin() + index);
    table[hashKey].resize(size-1);
    cout << "erased item " << item <<  " from hashKey " << hashKey << " in index " << index << endl;
}

template <typename T>
void hashTable<T>::inList(T &item)
{
    int hashKey = hash(item);
    if(hashKey < nSlots) //error handling
    {
        int index = 0;
        int size = table[hashKey].size();
        cout << "size is " << size << endl;

        while (index < size)
        {
            if(table[hashKey].at(index) != item)
                index+=1;
            else
                break;
        }
        if (index < size)
        {
            if(table[hashKey].at(index) == item)
                cout << "Word " << item << " located with hashKey " << hashKey << " in index " << index << endl;
        }
        else
        {
            cout << "Word " << item << " is not in list." << endl;
        }
    }
    else
    {   
        cerr << "Hashkey is out of range." << endl;
    }
}

template <typename T>
int hashTable<T>::hash(T &item)
{
    std::hash<T> h;
    return h(item) % nSlots;
}

template <typename T>
void hashTable <T>::printVector(int hashKey)
{
    if(hashKey < nSlots)
    cout << "printing the values that have the hashKey index " << hashKey << endl;
    int size = table[hashKey].size();
    for(int i = 0; i < size; i++)
    {
        cout << table[hashKey].at(i) << " ";
    }
    cout << endl;
}

#endif