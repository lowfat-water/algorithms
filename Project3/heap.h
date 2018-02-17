#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class heap
{
    public:
        heap(int size, const T& initVal = T());
        int parent(int i); //returns index of parent for index i
        int left(int i); //returns index of left child for index i
        int right(int i); //returns index of left child for index i
        T getItem(int n); //returns nth item in the heap
        void assignVector(vector <T> &newVector);
        void print();
        const T& operator[](int i) const;
        /*void initializeMaxHeap(); //initializes heap to 0s?
        void maxHeapify(vector <T> &A, int i);
        void buildMaxHeap(vector <T> &A);
        void initializeMinHeap(); //initializes heap to 0s?
        void minHeapify(vector <T> &A, int i);
        void buildMinHeap(vector <T> &A);
        void heapSort;*/
    private:
        vector<T> heapVector;
};

#endif