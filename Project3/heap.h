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
        void print();
        const T& operator[](int i) const;
        T& operator[](int i);
        heap<T> &operator=(heap<T> m); 
        void initializeMaxHeap(vector <T> &newVector); //initializes vector by taking in contents of another
        void maxHeapify(int i, int heapSize);
        void exchange(vector <T> &A, int n, int m);
        //void buildMaxHeap();
        //void initializeMinHeap(); //initializes heap to 0s?
        //void minHeapify(vector <T> &A, int i);
        //void buildMinHeap(vector <T> &A);
        //void heapSort;
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

template <typename T>
void heap<T>::initializeMaxHeap(vector <T> &newVector)
{
    
    int n = newVector.size();
    heapVector.resize(n);
    for(int i = 0; i < n; i++)
    {
        heapVector.at(i) = newVector.at(i);
    }
}

template <typename T>
void heap<T>::maxHeapify(int i, int heapSize)
{
    cout << "max heapify for index " << i << endl;
    int l = left(i);
    int r = right(i);
    
    int largest;
    if (l < heapSize && heapVector.at(l) > heapVector.at(i)) //if parent is smaller than left child
        largest = l;
    else 
        largest = i;
    if (r < heapSize && heapVector.at(r) > heapVector.at(largest)) //if right child is smaller than left child
        largest = r;
    if (largest != i)
    {
        exchange(heapVector, i, largest);
        maxHeapify(largest, heapSize);
    }
}

template <typename T>
void heap<T>::exchange(vector <T> &A, int n, int m)
{
        int temp = A.at(n);
        A.at(n) = A.at(m);
        A.at(m) = temp;
        cout << "exchanged items " << n << " and " << m << endl;
}

#endif