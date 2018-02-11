#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include <cmath>
#include "wordList.h"

using namespace std;

/*wordList::wordList()
{
    vector <string> temp = {"one","two"};
    B = temp;
}
*/
void wordList::setVector()
{
    cout << "assigning vector . . ." << endl;
    B = dictionary;

    cout << "vector assigned" << endl;
}

void wordList::printVector()
{
    for(int i = 0; i < B.size(); i++)
    {
        cout << B.at(i) << endl;
    }
}

int wordList::getSize()
{
    return dictionary.size();
}

void wordList::readIn()
{
    ifstream fin;
    string word, fileName = "test.txt";
    fin.open(fileName.c_str());
    if(!fin)
    {
        cerr << "file does not exist" << endl;
    }
    while(fin >> word)
    {
        dictionary.push_back(word);
    }
    fin.close();
}

void wordList::insertionSort(float &seconds)
{
    clock_t startTime = clock(), endTime;
    for(int j = 1; j < dictionary.size(); j++)
    {
        string key = dictionary.at(j);
        int i = j - 1;
        while (i >= 0 && dictionary.at(i) > key)
        {
            dictionary.at(i+1) = dictionary.at(i);
            i = i-1;
        }
        dictionary.at(i+1) = key;
    }

    cout << "the starting time was: " << startTime << endl;
    cout << "the clock now is: " << clock() << endl;
    int diff = clock() - startTime;
    //cout << diff << endl;
    seconds = diff/CLOCKS_PER_SEC;
    cout << seconds << endl;
}

void wordList::mergeSort(vector <string> &B, int p, int r)
{ 
    if (p < r)
    {
        int q = floor((p+r)/2);
       // cout << "q is " << q << endl;
        mergeSort(B, p, q);
        mergeSort(B, q+1, r);
        merge(B, p, q, r);
    }
    dictionary = B;
}

void wordList::merge(vector <string> &B, int p, int q, int r)
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

ostream& operator << (ostream &out, const wordList &list)
{
    cout << "printing . . ." << endl;
    for (int i = 0; i != list.dictionary.size(); i++)
    {
        out << list.dictionary.at(i) << endl;
    }
    return out;
}
