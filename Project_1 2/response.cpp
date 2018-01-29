// File: response.cpp
// Response class implementation
#include <iostream>
#include "response.h"
using namespace std;

void response::setCorrect(int numCorrect)
{
    correct = numCorrect;
}

void response::setIncorrect(int numIncorrect)
{
    incorrect = numIncorrect;
}

int response::getCorrect()
{
    return correct;
}

int response::getIncorrect()
{
    return incorrect;
}

bool response::compare(response response1)
{
    if(response1.getCorrect() == getCorrect())
        return true;
    else
        return false;
}

void response::print()
{
    cout << "Response: (" << correct << ", " << incorrect << ")" << endl;
}