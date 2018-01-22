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
    
    for (int i=0 ; i < 4 ; i++ ) 
    {
        item = r.random(6); // generates 4 rn in [0,5]
        value.push_back(item);
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

void code::clearValue()
{
    value.pop_back();
}

int code::checkCorrect(code guess) const
{
    int numberCorrect=0; //initializing value

    for(int i=0; i<4; i++)
    {
        if(guess.getValue(i) == value.at(i))
        {
            numberCorrect++;
        }
    }
    
    //cout << "The number of correct digits in the right place is " << numberCorrect << endl;
    return numberCorrect;
} 

int code::checkIncorrect(code guess) const
{
    int numberIncorrect=0;

    for(int i = 0; i < 6; i++)
    {
        if ((getValue(0) == i ||
                getValue(1) == i ||
                getValue(2) == i ||
                getValue(3) == i) &&
            (guess.getValue(0) == i ||
                getValue(1) == i ||
                getValue(2) == i ||
                getValue(3) == i ))
                numberIncorrect++;
    };

    return numberIncorrect;
}