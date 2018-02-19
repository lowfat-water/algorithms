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


    private:
        vector<vector<T> > table;
        int nSlots, nCols;
};

template <typename T>
hashTable<T>::hashTable(vector <T> newVector)
{
    nSlots = newVector.size()/3;
    table.resize(nSlots);
}

template <typename T>
void hashTable<T>::addItem(T &item)
{
    int hashKey = hash(item);
}

template <typename T>
int hashTable<T>::hash(T &item)
{
    hash <T> h;
    const size_t value = h(item);
    return value % nSlots;
}
/*
template <typename T>
void hashTable<T>::resize(int numRows, int numCols)
{
    int i;

    if (numRows == nSlots && numCols == nCols)
        return;
    
    nSlots = numRows;
    nCols = numCols;

    hashTable.resize(nSlots);
}
*/
#endif