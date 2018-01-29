#include <iostream>
#include "time24.h"

time24::time24(int h, int m) : hour(h), minute(m) //initialization list
{
    normalizeTime();
}

time24 time24::duration(const time24 & t)
{
    int currentTime = hour * 60 + minute;
    int tTime = t.hour * 60 + t.minute;

    return time24(0, tTime - currentTime);
}

void time24::normalizeTime()
{
    int extraHours = minute/60;

    minute %= 60;

    hour = (hour + extraHours) % 24;
}

