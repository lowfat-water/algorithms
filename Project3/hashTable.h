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

    private:
        vector<vector<T> > table;
        int nSlots, nItems;
};

template <typename T>
hashTable<T>::hashTable(vector <T> newVector) //constructor that takes in vector as argument
{
    nItems = newVector.size();
    nSlots = nItems/3; //average of 3 collisions per slot
    table.resize(nSlots); 
    for(int i = 0; i < nItems; i++)
    {
        addItem(newVector.at(i)); //uses member funciton addItem to insert elements from vector
    }
}

template <typename T>
void hashTable<T>::addItem(T &item)
{
    int hashKey = hash(item); //computes hashKey
    if (hashKey < nSlots) //error handling
    {
        table[hashKey].push_back(item);
    }
    else
        cerr << "HashKey is out of range." << endl;
}

template <typename T>
void hashTable<T>::deleteItem(T &item)
{
    int hashKey = hash(item); //computes hashKey
    int index = 0;
    int size = table[hashKey].size(); //number of items with this hashKey
    while(table[hashKey].at(index) != item) //traverses through vector of items with this hashKey to find item
        index++;
    table[hashKey].erase(table[hashKey].begin() + index); //deletes item
    table[hashKey].resize(size-1); //resizes
    cout << "erased item " << item <<  " from hashKey " << hashKey << " in index " << index << endl;
}

template <typename T>
void hashTable<T>::inList(T &item)
{
    int hashKey = hash(item); //computes hashKey
    if(hashKey < nSlots) //error handling
    {
        int index = 0;
        int size = table[hashKey].size(); //number of elements with this hashKey

        while (index < size)
        {
            if(table[hashKey].at(index) != item) //traverses until it finds item
                index+=1;
            else
                break;
        }
        if (index < size) //if item was in list
        {
            if(table[hashKey].at(index) == item)
                cout << "Word " << item << " located with hashKey " << hashKey << " in index " << index << endl;
        }
    }
    else
    {   
        cerr << "Hashkey is out of range." << endl;
    }
}

template <typename T>
int hashTable<T>::hash(T &item) //computes hashKey using built-in hash function
{
    std::hash<T> h;
    return h(item) % nSlots;
}

#endif