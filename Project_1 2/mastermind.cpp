// File: mastermind.cpp
// Mastermind class implementation
#include <iostream>
#include "mastermind.h"
#include "code.h"
#include "d_except.h"


using namespace std;

mastermind::mastermind()
{}

void mastermind::playGame()
{
    
    // Calls initRandom() to initialize a secret code
   
    cout << "To play mastermind, we first initialize the secret 4-digit code, with each digit being on the interval [0,5]" << endl;
    code newSecret;

    newSecret.initRandom();
    secret = newSecret;

    humanGuess();

    getResponse(newSecret, humanGuess());
}

code mastermind::humanGuess()
{
    cout << "Now input a 4-digit guess code, with each digit being on the interval [0,5]" << endl;
    code newGuess;

    for (int i = 0; i<4; i++)
    {
        int digit;
        cin >> digit;
        if( digit < 0 || digit > 5)
        {
            //Throws an error if user inputs an out-of-range integer
                //need to figure out how to print what we want
            throw baseException("Error: Must be on the interval[0, 5]"); 
        }
        else
            newGuess.setValue(digit);
    }
    
    //Prints guess code
    cout << "Your guess code is ";
    for (int i = 0; i<4; i++)
        cout << newGuess.getValue(i);

    guess = newGuess;
    
    cout << endl;
    return newGuess;
}

int mastermind::getResponse(code newSecret, code newGuess)
{
    newSecret.checkCorrect(newGuess);
}


