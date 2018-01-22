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

void mastermind::printSecret(code secretCode)
{
    cout << "The secret code is: ";

    for (int i=0 ; i < 4 ; i++ ) 
    {
        cout << secretCode.getValue(i);
    }
    
    cout << endl << endl;
}

code mastermind::humanGuess()
{
    for (int i = 0; i<4; i++)
    {
        int digit;
        cin >> digit;
        if( digit < 0 || digit > 5)
        {
            //Throws an error if user inputs an out-of-range integer
                //need to figure out how to print what we want
                //need to figure out how to not make it quit the whole program
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
    if (numIncorrect < 0)
        numIncorrect = 0;
}

bool mastermind::isSolved(response newResponse)
{
    if (newResponse.getCorrect() == 4)
        return true;
    else
        return false;
}

void mastermind::playGame()
{
    int numTries = 0;
    int numberCorrect = 0;
    // Calls initRandom() to initialize a secret code
   
    cout << "To play mastermind, we first initialize the secret 4-digit code, with each digit being on the interval [0,5]" << endl;

    secret.initRandom();

    printSecret(secret);

    cout << "Now input a 4-digit guess code, with each digit being on the interval [0,5]" << endl;    

    response newResponse;
    
    while(numTries < 3 && !isSolved(newResponse))
    {   
        guess=humanGuess();

        int numberCorrect, numberIncorrect;
        
        getResponse(secret, guess, numberCorrect, numberIncorrect);

        //response newResponse;
        newResponse.setCorrect(numberCorrect);
        newResponse.setIncorrect(numberIncorrect);
        newResponse.print();
        
        numTries++;

        if(numTries < 3 && !isSolved(newResponse))
            cout << "Try again:" << endl;
        
        
    }

    if (numTries >=3)
        cout << "You lose! Out of tries" << endl;
    if (isSolved(newResponse))
        cout << "You win!" << endl;
}
    









