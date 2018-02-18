#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class heap
{
    public:
        heap(int size = 1, const T& initVal = T()); //default constructor
        int parent(int i); //returns index of parent for index i
        int left(int i); //returns index of left child for index i
        int right(int i); //returns index of left child for index i
        T& getItem(int n); //returns nth item in the heap
        void initializeHeap(vector <T> &newVector); //initializes vector by taking in contents of another
        void maxHeapify(int i, int heapSize);
        void buildMaxHeap();
        void minHeapify(int i, int heapSize);
        void buildMinHeap();
        void heapSort();
        vector <T> &getVector();
 //       const T& operator[](int i) const;
 //       T& operator[](int i);
//        vector<T> &operator=(heap<T> m); 

        void printHeap();
        void exchange(vector <T> &A, int n, int m);
    private:
        vector<T> heapVector;
};

template <typename T>
heap<T>::heap(int size, const T& initVal):heapVector(size, initVal)
{}

/*
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
vector <T> &heap<T>::operator=(heap<T> m)
{
    for(int i = 0; i < m.heapVector.size(); i++)
    {    
        (*this)[i] = m[i];
    }
    return this->heapVector;
}
*/

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
void heap<T>::initializeHeap(vector <T> &newVector)
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
    //cout << "max heapify for index " << i << endl;
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
void heap<T>::buildMaxHeap()
{
    int heapSize = heapVector.size();
    for (int i =(floor(heapSize/2)); i >= 0; i--)
    {
        maxHeapify(i, heapSize);
    }
    //print(A);
    //cout << "max heap created." << endl;
}

template <typename T>
void heap<T>::minHeapify(int i, int heapSize)
{
    //cout << "min heapify for index " << i << endl;
    int l = left(i);
    int r = right(i);
    
    int smallest;
    if (l < heapSize && heapVector.at(l) < heapVector.at(i)) //if parent is smaller than left child
        smallest = l;
    else 
        smallest = i;
    if (r < heapSize && heapVector.at(r) < heapVector.at(smallest)) //if right child is smaller than left child
        smallest = r;
    if (smallest != i)
    {
        exchange(heapVector, i, smallest);
        minHeapify(smallest, heapSize);
    }
}

template <typename T>
void heap<T>::buildMinHeap()
{
    int heapSize = heapVector.size();
    for (int i =(floor(heapSize/2)); i >= 0; i--)
    {
        minHeapify(i, heapSize);
    }
    //print(A);
    cout << "min heap created." << endl;
}

template <typename T>
void heap<T>::heapSort()
{
    cout << "Sorting via heapSort. . ." << endl;
    int heapSize = heapVector.size();
    buildMaxHeap();

    for(int i = heapSize-1; i >= 0; i--)
    {
        exchange(heapVector, 0, i);
        heapSize -= 1;
        maxHeapify(0, heapSize);
    }
}

template<typename T>
vector <T> &heap<T>::getVector()
{
    return heapVector;
}

template <typename T>
void heap<T>::printHeap()
{
    for(int j = 0; j < heapVector.size(); j++)
    {
        cout << heapVector.at(j) << " ";
    }    
    cout << endl;
}

template <typename T>
void heap<T>::exchange(vector <T> &A, int n, int m)
{
        T temp = A.at(n);
        A.at(n) = A.at(m);
        A.at(m) = temp;
        //cout << "exchanged items " << n << " and " << m << endl;
}

#endif