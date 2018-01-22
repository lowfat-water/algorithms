// File: response.cpp
// Response class implementation
#include <iostream>
#include "response.h"
using namespace std;

response::response()
{

}

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
/*
bool response::compare()
{

}
*/
void response::print()
{
    cout << "Response: (" << correct << ", " << incorrect << ")" << endl;
}