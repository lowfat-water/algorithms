// File: mastermind.cpp
// Mastermind class implementation
#include <iostream>
#include <vector>
#include "mastermind.h"
#include "code.h"
#include "d_random.h"

using namespace std;

code::code()
{
}


void code::initRandom()
{
    long item;
    randomNumber r(0); // seed the generator
    cout << "Random code: " << endl;
    for (int i=0 ; i < 4 ; i++ ) 
    {
        item = r.random(6); // generates 4 rn in [0,5]
        value.push_back(item);
        cout << value.at(i);
    }

    cout << endl;
}

void code::setValue(int n)
{
    value.push_back(n);
}

int code::getValue(int n) const
{
    return value.at(n);
}

int checkCorrect(code guess)
{
    int numberCorrect=0; //initializing value

    for(int i=0; i<4; i++)
    {
        if((guess.getValue(i)) == (getValue(i))
        {
            numberCorrect++;
        }
    }
    cout << "The number of correct digits in the right place is " << numberCorrect << endl;
} 

