#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void buildMaxHeap(vector <int> &A);
void maxHeapify(vector <int> &A, int i);
void exchange(vector <int> &A, int n, int m);
int left(int i);
int right(int i);
void print(vector <int> &A);
void heapSort(vector <int> &A);

int main()
{
    vector <int> A(11);
    int array[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 28};
    for(int i = 0; i < 11; i++)
    {
        A.at(i) = array[i];
    }
    print(A);
    //buildMaxHeap(A);
    heapSort(A);
    print(A);
}

void buildMaxHeap(vector <int> &A)
{
    int heapSize = A.size();
    for (int i =(floor(heapSize/2)); i >= 0; i--)
    {
        maxHeapify(A,i);
    }
    //print(A);
    cout << "max heap created." << endl;
}

void maxHeapify(vector <int> &A, int i)
{
    cout << "max heapify for index " << i << endl;
    int l = left(i);
    int r = right(i);
    
    int largest;
    if (l < A.size() && A.at(l) > A.at(i))
        largest = l;
    else 
        largest = i;
    if (r < A.size() && A.at(r) > A.at(largest))
        largest = r;
    if (largest != i)
    {
        exchange(A, i, largest);
        maxHeapify(A, largest);
    }
    print(A);
}

void heapSort(vector <int> &A)
{
    vector <int> *heapSize;
    heapSize = &A.at(A.size() - 1);;
    buildMaxHeap(A);

    for(int i = A.size()-1; i > 0; i--)
    {
        exchange(A, 0, i);
        heapSize -= 1;
        maxHeapify(*heapSize, 0);
    }
}

void exchange(vector <int> &A, int n, int m)
{
        int temp = A.at(n);
        A.at(n) = A.at(m);
        A.at(m) = temp;
        cout << "exchanged items " << n << " and " << m << endl;
}

int left(int i)
{
    int l = 2 * i + 1;
    return l;
}

int right(int i)
{
    int r = 2 * i + 2;;
    return r;
}

void print(vector <int> &A)
{
    for(int j = 0; j < A.size(); j++)
        cout << A.at(j) << " ";
    cout << endl;
}