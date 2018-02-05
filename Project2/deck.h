//deck.h file
//deck class definition

#ifndef DECK_H //compiler directives
#define DECK_H

#include "card.h"
#include "node.h"
#include "d_random.h"

class deck
{
    public:
        deck(); //default constructor
        deck(const deck &sampleDeck); //copy constructor
        void addNode(card &newCard); //function to insert a node into the list with the card newCard
        void printDeck(); //print function that invokes overloaded print operator to print cards
        //node <card> getCurr(const deck &sampleDeck);
        card deal();
        void replace(card &sampleCard);
        deck & operator = (const deck & sampleDeck);
        //deck shuffle(deck & sampleDeck);
        void shuffle();
        card searchCard (const card & sampleCard);
        ~deck();
    private:
        node <card> * head; //pointers to nodes with card data
        node <card> * curr;
        node <card> * temp;
};

#endif //compiler directive
