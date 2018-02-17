#include <iostream>
#include <vector>
#include <cmath>
#include "heap.h"
using namespace std;

template <typename T>
heap<T>::heap(int size, const T& initVal)
{
    heapVector(size, initVal);
}

template <typename T>
const T& heap<T>::operator[] (int i) const
{
    return heapVector.at(i);
}

template <typename T>
int heap<T>::parent(int i)
{
    int n = floor(i/2);
    return n;
}

template <typename T>
int heap<T>::left(int i)
{
    int l = 2 * i + 1;
    return l;
}

template <typename T>
int heap<T>::right(int i)
{
    int r = 2 * i + 2;
    return r;
}

template <typename T>
T heap<T>::getItem(int n)
{
    return heapVector.at(n);
}

template <typename T>
void heap<T>::assignVector(vector <T> &newVector)
{
    int n = newVector.size();
    for(int i = 0; i < n; i++)
    {
        heapVector.at(i) = newVector.at(i);
    }
}

template <typename T>
void heap<T>::print()
{
    {
        for(int j = 0; j < heapVector.size(); j++)
        {
            cout << heapVector.at(j) << " ";
        }    
        cout << endl;
    }
}


