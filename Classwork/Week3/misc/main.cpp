#include <iostream>
#include "time24.h"
#include "d_except.h"

using namespace std;

int main()
{
time24 currentTime, nextTime, interval;

cout << "Enter current time and a later time: ";
cin >> currentTime >> nextTime;

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