// File: mastermind.cpp
// Mastermind class implementation
#include <iostream>
#include "mastermind.h"
#include "code.h"
#include "d_except.h"
#include "response.h"
using namespace std;

mastermind::mastermind()
{}

void mastermind::playGame()
{
    
    // Calls initRandom() to initialize a secret code
   
    cout << "To play mastermind, we first initialize the secret 4-digit code, with each digit being on the interval [0,5]" << endl;

    secret.initRandom();

    guess=humanGuess();

    int numberCorrect, numberIncorrect;
    
    getResponse(secret, guess, numberCorrect, numberIncorrect);

    /*
    cout << "number correct: " << numberCorrect << endl;


    cout << "number incorrect: " << numberIncorrect << endl;
    */
    response newResponse;
        newResponse.setCorrect(numberCorrect);
        newResponse.setIncorrect(numberIncorrect);
        newResponse.print(); 


}

code mastermind::humanGuess()
{
    cout << "Now input a 4-digit guess code, with each digit being on the interval [0,5]" << endl;

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
            guess.setValue(digit);
    }
    
    //Prints guess code
    cout << "Your guess code is ";
    for (int i = 0; i<4; i++)
        cout << guess.getValue(i);
    
    cout << endl;
    return guess;
}

void mastermind::getResponse(code newSecret, code newGuess, int &numCorrect, int &numIncorrect)
{
    numCorrect = newSecret.checkCorrect(newGuess);
    numIncorrect = newSecret.checkIncorrect(newGuess); 
    numIncorrect = numIncorrect - numCorrect;
}


