#include <iostream>
#include "d_except.h"
using namespace std;

int main()
{
 /*
    int x;

    cin >> x;
    
    if (x<5)
        throw rangeError("x is too small");
    else
        cout << "good" << endl;
*/

try
{
    interval = currentTime.duration(nextTime);
    cout << "The interval between the two times is " << interval << endl;
}

catch (const rangeError& re)
{
    cerr << re.what() << endl;
    exit(1);
}


};