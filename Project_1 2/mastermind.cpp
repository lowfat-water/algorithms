// File: mastermind.cpp
// Mastermind class implementation
#include <iostream>
#include "mastermind.h"
#include "code.h"


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
//    getResponse(secret, guess);

}

code mastermind::humanGuess()
{
    cout << "Now input a 4-digit guess code, with each digit being on the interval [0,5]" << endl;
    code newGuess;

    for (int i = 0; i<4; i++)
    {
        int digit;
        cin >> digit;
        newGuess.value.push_back(digit);
    }
        

    //Prints guess code
    
    cout << "Your guess code is ";
    for (int i = 0; i<4; i++)
        cout << newGuess.value.at(i);

    guess = newGuess;
    
    cout << endl;
    return newGuess;
}

/*
int mastermind::getResponse(code newSecret, code newGuess)
{
    newSecret.checkCorrect(newGuess);
    
}
*/

