// File: mastermind.cpp
// Mastermind class implementation
#include <iostream>
#include "mastermind.h"
#include "code.h"
#include "d_except.h"
#include "response.h"
using namespace std;

// member function to print secret code
void mastermind::printSecret(code secretCode)
{
    cout << "The secret code is: ";

    // iterates through vector, calls code member function getValue() to retrieve private data and print secret code
    for (int i=0 ; i < 4 ; i++ ) 
    {
        cout << secretCode.getValue(i);
    }
    
    cout << endl << endl;
}

// iteratively reads in guess from keyboard
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
            guess.setValue(digit); // calls code member function setValue() to store user-input code in private data member
    }
    return guess;
}

// compares guess code with secret code, returns numCorrect and numIncorrect
void mastermind::getResponse(code newSecret, code newGuess, int &numCorrect, int &numIncorrect)
{
    numCorrect = newSecret.checkCorrect(newGuess); // number of correct digits in the correct location
    int totalCorrect = newSecret.checkIncorrect(newGuess); // intermediate variable to store total number of shared digits
    numIncorrect = totalCorrect - numCorrect; // the number of correct digits in the incorrect location is the difference of the total number of shared digits and numCorrect
    if (numIncorrect < 0)
        numIncorrect = 0; // numIncorrect must be > 0
}

// returns true if the puzzle has been solved, i.e. if numCorrect = 4
bool mastermind::isSolved(response newResponse)
{
    if (newResponse.getCorrect() == 4)
        return true;
    else
        return false;
}

// iteratively asks user for guesses
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
    
    while(numTries < 10 && !isSolved(newResponse))
    {   
        guess = humanGuess();

        cout << "Your guess code is ";
        for (int i = 0; i<4; i++)
            cout << guess.getValue(i); // calls code member function getValue() to retrieve private data and print guess code
        cout << endl;

        int numberCorrect, numberIncorrect;
        
        getResponse(secret, guess, numberCorrect, numberIncorrect);
        
        newResponse.setCorrect(numberCorrect);
        newResponse.setIncorrect(numberIncorrect);
        newResponse.print();
        

        numTries++;

        if(numTries < 3 && !isSolved(newResponse))
            cout << "Try again:" << endl;
        
        for(int j = 0; j < 4; j++) // clears the vector so that it can be re-initiated
        {
            guess.clearValue();
        }           
    }
    if (numTries >=10)
        cout << "You lose! Out of tries" << endl;
    if (isSolved(newResponse))
        cout << "You win!" << endl;
}
    









