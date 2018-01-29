#include <iostream>
#include <string>
#include "card.h"
#include "node.h"
#include "deck.h"

using namespace std;

deck::deck()
{
    head = NULL;
    curr = NULL;
    temp = NULL;

    for(int i = 2; i <= 14; i++)
    { 
        card newCard(i, "Clubs");
        addNode(newCard);
    }   

    for(int i = 2; i <= 14; i++)
    { 
        card newCard(i, "Diamonds");
        addNode(newCard);
    }  

    for(int i = 2; i <= 14; i++)
    { 
        card newCard(i, "Hearts");
        addNode(newCard);
    }

    for(int i = 2; i <= 14; i++)
    { 
        card newCard(i, "Spades");
        addNode(newCard);
    }
//    printDeck();

}

void deck::addNode(card &newCard)
{
    node<card> *n = new node <card>;
    n->next = NULL;
    n->cardInfo = newCard;

    if(head != NULL)
    {
        curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else 
    {
        head = n;
    }
}

void deck::printDeck()
{
    curr = head;
    while(curr != NULL)
    {
        cout << curr->cardInfo << endl;
        curr = curr->next;
    }
}

/*
ostream& operator << (ostream& ostr, const deck &newDeck)
{
    curr = head;
    while(curr != NULL)
    {
        ostr << curr->card << endl;
        curr = curr->next;
    }
}
*/