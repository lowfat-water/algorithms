// File mastermind.h
// mastermind class definition

#ifndef MASTERMIND_H // to avoid multiple definitions
#define MASTERMIND_H // compiler directive

#include "code.h"

class mastermind
{
public:
    mastermind();
    //void printSecret(code secretCode); // prints the secret code
    code humanGuess(); // reads a guess from the keyboard, returns code object that represents the guess
    int getResponse(code newSecret, code newGuess); // passed two codes, returns a response
    //void isSolved(); // passed a response, returns true if board has been solved

    void playGame(); // initializes a random code, prints it to the screen, and iteratively gets a guess until either player has won

private:
    code secret; //stores secret code as private data member (maybe not necessary?)
    code guess; //stores guess code as private data member (maybe not necessary?)
};


#endif