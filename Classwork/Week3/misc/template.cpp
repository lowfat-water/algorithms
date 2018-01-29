#include <iostream>
using namespace std;

template <typename objectType>
objectType & getMax (objectType & value1, objectType & value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

int main()
{
    int nInteger1 = 25;
    int nInteger2 = 40;
    int nMaxValue = getMax <int> (nInteger1, nInteger2);
    double dDouble1 = 1.1;
    double dDouble2 = 1.001;
    double dMaxValue = getMax <double> (dDouble1, dDouble2);

    cout << "The max of the ints is " << nMaxValue << endl;
    cout << "The max of the doubles is " << dMaxValue << endl;
    
};

