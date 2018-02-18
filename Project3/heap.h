#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class heap
{
    public:
        heap(int size = 1, const T& initVal = T());
        int parent(int i); //returns index of parent for index i
        int left(int i); //returns index of left child for index i
        int right(int i); //returns index of left child for index i
        T& getItem(int n); //returns nth item in the heap
        void assignVector(vector <T> &newVector);
        void print();
        const T& operator[](int i) const;
        T& operator[](int i);
        heap<T> &operator=(heap<T> m); 
        void initializeMaxHeap(); //initializes heap to 0s?
        void maxHeapify(vector <T> &A, int i);
        void buildMaxHeap(vector <T> &A);
        void initializeMinHeap(); //initializes heap to 0s?
        void minHeapify(vector <T> &A, int i);
        void buildMinHeap(vector <T> &A);
        void heapSort;
    private:
        vector<T> heapVector;
};

template <typename T>
heap<T>::heap(int size, const T& initVal):heapVector(size, initVal)
{}

template <typename T>
const T& heap<T>::operator[] (int i) const
{
    return heapVector.at(i);
}


template <typename T>
T& heap<T>::operator[] (int i)
{
    return heapVector.at(i);
}

template <typename T>
heap<T> &heap<T>::operator=(heap<T> m)
{
    for(int i = 0; i < m.heapVector.size(); i++)
    {    
        (*this)[i] = m[i];
    }
    return *this;
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
T& heap<T>::getItem(int n)
{
    return heapVector.at(n);
}

template <typename T>
void heap<T>::assignVector(vector <T> &newVector)
{
    
    int n = newVector.size();
    heapVector.resize(n);
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

#endif