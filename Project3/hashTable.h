#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <functional>
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
        void printVector(int index);


    private:
        vector<vector<T> > table;
        int nSlots, nCols;
};

template <typename T>
hashTable<T>::hashTable(vector <T> newVector)
{
    int nItems = newVector.size();
    nSlots = nItems/3;
    table.resize(nSlots);
    for(int i = 0; i < nItems; i++)
    {
        int index = hash(newVector.at(i));
        addItem(newVector.at(i));
        cout << "added item  " << newVector.at(i) << " to table at index " << index << endl;
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
int hashTable<T>::hash(T &item)
{
    std::hash<T> h;
    return h(item) % nSlots;
}

template <typename T>
void hashTable <T>::printVector(int index)
{
    if(index < nSlots)
    cout << "printing the values that have the key index " << index << endl;
    int size = table[index].size();
    for(int i = 0; i < size; i++)
    {
        cout << table[index].at(i) << " ";
    }
    cout << endl;
}

#endif