#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void quickSort(vector <int> &A, int p, int r);
int partition(vector <int> &A, int p, int r);
void exchange(vector <int> &A, int n, int m);
void print(vector <int> &A);

int main()
{
    int B[]= {23, 15, 9, 76, 32, 8, 2, 19};
    vector <int> A(B, B+8);
    
    print(A);

    int p=0, r = A.size()-1;   

    quickSort(A, p, r);

    print(A);
}

void quickSort(vector <int> &A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);

    }
}

int partition(vector <int> &A, int p, int r)
{

    int x = A.at(r);

    int i = p-1;
    
    for(int j = p; j < r; j++)
    {   
        //cout << "j is " << j << endl;
        
        if (A.at(j) <= x)
        {
//            cout << "i is " << i << endl;
            i = i + 1;
            //cout << "i now is " << i << endl;
            exchange(A, i, j);
        }
    }
    exchange(A, i+1, r);
    return i+1; //pivot location
}

void exchange(vector <int> &A, int n, int m)
{
        int temp = A.at(n);
        A.at(n) = A.at(m);
        A.at(m) = temp;
}

    
void print(vector <int> &A)
{
    for(int j = 0; j < A.size(); j++)
        cout << A.at(j) << " ";
    cout << endl;
}