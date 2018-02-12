#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

void mergeSort(vector <string> &B, int p, int r);
void merge(vector <string> &B, int p, int q, int r);
void print(vector <string> &A);

int main()
{
    string B[]= {"st", "sb", "dd", "ff", "lg", "ah", "ej", "k"};
    vector <string> A(B, B+8);

    print(A);

    int p=0, r = A.size()-1;

    mergeSort(A, p, r);

    print(A);
}

void mergeSort(vector <string> &B, int p, int r)
{
    if (p < r)
    {
        int q = floor((p+r)/2);
       // cout << "q is " << q << endl;
        mergeSort(B, p, q);
        mergeSort(B, q+1, r);
        merge(B, p, q, r);
    }
}

void merge(vector <string> &B, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector <string> L(n1+1);
    vector <string> R(n2+1);

    for(int i = 0; i <= n1-1; i++)
    {
        L.at(i) = B.at(p+i);
    }

    for(int j = 0; j <= n2-1; j++)
    {
        R.at(j) = B.at(q+j+1);
    }
    L.at(n1) = "zzzzzzzzzzzz";
    R.at(n2) = "zzzzzzzzzzzz";

    int i = 0, j = 0;

    for(int k = p; k <= r; k++)
    {
        if (L.at(i) <= R.at(j))
        {
            B.at(k) = L.at(i);
            i = i + 1;
        }
        else
        {
            B.at(k) = R.at(j);
            j = j + 1;
        }
    }
}

void print(vector <string> &A)
{
    for(int j = 0; j < A.size(); j++)
        cout << A.at(j) << " ";
    cout << endl;
}
