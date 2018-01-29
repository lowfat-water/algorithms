#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "node.h"

class deck
{
    public:
        deck();
        void addNode(card &newCard);
        void printDeck();
        //friend ostream& operator << (ostream& ostr, const deck &newDeck);
    private:
        node <card> * head;
        node <card> * curr;
        node <card> * temp;
};

#endif