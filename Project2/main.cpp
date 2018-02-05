/*
Project 2a
Alina Rossi-Conaway and Dan Bartels
Octavia Camps
EECE2560
*/

#include <iostream>
#include <string>
#include "card.h"
#include "node.h"
#include "deck.h"


using namespace std;

void playFlip();

int main()
{
    playFlip();
}

void playFlip()
{
    cout << "Let's play flip!" << endl;
    deck newDeck;
    int numPoints = 0;
    char response = 'Y';

    for (int i = 0; i<=2; i++)
        newDeck.shuffle();

    
    while (response == 'Y' || response == 'y')
    {
        cout << "Would you like to flip a card? [Y/N]" << endl;
    
        cin >> response;
    
        card card1 = newDeck.deal();

        cout << "Your card is " << card1 << endl;

        if (card1.getValue() == 14)
        {
            cout << "You get 10 points!" << endl;
            numPoints += 10;
            cout << "Your new score is " << numPoints << endl;
        }

        else if (card1.getValue()== 11 || card1.getValue()== 12 || card1.getValue()== 13)
        {
            cout << "You get 5 points!" << endl;
            numPoints += 5;
            cout << "Your new score is " << numPoints << endl;
        }

        else if (card1.getValue()== 8 || card1.getValue()== 9 || card1.getValue()== 10)
        {
            cout << "You get 0 points" << endl;
            numPoints += 0;
            cout << "Your new score is " << numPoints << endl;
        }

        else if (card1.getValue()== 7)
        {
            cout << "You lose half your points :(" << endl;
            numPoints = numPoints/2;
            cout << "Your new score is " << numPoints << endl;
        }

        else if (card1.getValue()== 2 || card1.getValue()== 3 || card1.getValue()== 4 || card1.getValue()== 5 || card1.getValue()== 6)
        {
            cout << "You lose all your points :(" << endl;
            numPoints = 0;
            cout << "Your new score is " << numPoints << endl;
        }

        if(card1.getSuit() == "Hearts")
        {
            cout << "You get one extra point!" << endl;
            numPoints += 1;
            cout << "Your new score is " << numPoints << endl;
        }
        
        newDeck.replace(card1);
    }
    if (response == 'N' || response == 'n')
    {
        cout << "Game is over." << endl;
    }
    else
    {
        cout << "Invalid response. Please input Y or N." << endl;
    }
}