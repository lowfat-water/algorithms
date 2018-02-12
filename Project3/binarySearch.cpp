#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

string binarySearch (vector <string> &B, string key);
string binarySearchAux (vector <string> &B, string key, string right, string left);

int main()
{
    //string B[]= {"st", "sb", "dd", "ff", "lg", "ah", "ej", "k"};
    string B[]= {"ah", "dd", "ej", "ff", "k", "lg", "sb", "st"};
    vector <string> A(B, B+8);

    //print(A);

    int p=0, r = A.size()-1;

    binarySearch(A, "st");

    //print(A);
}

string binarySearch (vector <string> &A, string key)
{
  int left = 0;
  int right = A.size()-1;
  while (left <= right)
  {
    int mid = (left + right)/ 2;
    if (A.at(mid) == key)
    {
      return A.at(mid);
    }
    else if (A.at(mid) < key)
    {
      left = mid+1;
    }
    else
    {
      right = mid+1;
    }
  }
  return "nope 1";
}

string binarySearchAux (vector <string> &A, string key, int right, int left)
{
  if (right < left)
  {
    return "nope 2";
  }
  int mid = (left+right)/2;
  if (key == A.at(mid))
  {
    return A.at(mid);
  }
  else if (key < A.at(mid))
  {
    return binarySearchAux (A, key, left, mid-1);
  }
  else
  {
    return binarySearchAux (A, key, mid+1, right);
  }
}
