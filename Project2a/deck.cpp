//deck.cpp file
//deck class implementation

#include <iostream>
#include <string>
#include "card.h"
#include "node.h"
#include "deck.h"

using namespace std;

deck::deck()
{
    head = NULL; //initializes list pointers to NULL
    curr = NULL;
    temp = NULL;

    for(int i = 2; i <= 14; i++) //adds nodes to the list that contain cards of suit "Clubs"
    { 
        card newCard(i, "Clubs");
        addNode(newCard);
    }   

    for(int i = 2; i <= 14; i++) //adds nodes to the list that contain cards of suit "Diamonds"
    { 
        card newCard(i, "Diamonds");
        addNode(newCard);
    }  

    for(int i = 2; i <= 14; i++) //adds nodes to the list that contain cards of suit "Hearts"
    { 
        card newCard(i, "Hearts");
        addNode(newCard);
    }

    for(int i = 2; i <= 14; i++) //adds nodes to the list that contain cards of suit "Spades"
    { 
        card newCard(i, "Spades");
        addNode(newCard);
    }
}

void deck::addNode(card &newCard)
{
    node<card> *n = new node <card>; //dynamically allocates memory for a node n (with data type card) and creates a pointer to it
    n->next = NULL; //sets this node as the end of the list, with its "next" pointer pointing to NULL
    n->cardInfo = newCard; //stores the information from the argument (newCard) in the node's cardInfo

    if(head != NULL) //if the list isn't empty
    {
        curr = head; //assigns pointer curr to point where head is pointing (start of the list)
        while(curr->next != NULL) //while we're not at the end of the list
        {
            curr = curr->next; //advance through the list
        }
        curr->next = n; //assigns the next pointer of the curr node to our new node n, effectively 
    }
    else //if the list is empty
    {
        head = n; //assign head pointer to node n
    }
}

void deck::printDeck()
{
    curr = head; //starts at the beginning of the list
    while(curr != NULL) //while we're not at the end of the list
    {
        cout << curr->cardInfo << endl; //invokes overloaded print operator to print card information
        curr = curr->next; //advance through list
    }
}
