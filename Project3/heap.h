#include <vector>
using namespace std;

template <class T>
class heap
{
    public:
        int parent(int i); //returns index of parent for index i
        int left(int i); //returns index of left child for index i
        int right(int i); //returns index of left child for index i
        int getItem(int n); //returns nth item in the heap
        void initializeMaxHeap(); //initializes heap to 0s?
        void maxHeapify(vector <T> &A, int i);
        void buildMaxHeap(vector <T> &A);
        void initializeMinHeap(); //initializes heap to 0s?
        void minHeapify(vector <T> &A, int i);
        void buildMinHeap(vector <T> &A);
        void heapSort;
    private:
        vector <T> heapVector;
}