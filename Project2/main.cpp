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

int main()
{
    deck newDeck;
    //newDeck.printDeck();

    //deck deck1 = newDeck;
    card card1 = newDeck.deal();
    cout << " card1 is " << card1 << endl;
    card card2 = newDeck.deal();
    cout << " card2 is " << card2 << endl;
    
    //cout << "the curr pointer is pointing at " << newDeck.getCurr(newDeck).cardInfo << endl;

    /*
    card card1(14, "spades"), card2;
    cout << "card1 is " << card1 << endl;
    cout << "card2 is " << card2 << endl;

    card2 = card1;
    cout << "card1 is " << card1 << endl;
    cout << "card2 is " << card2 << endl;
    */
} 
