//deck.cpp file
//deck class implementation

#include <iostream>
#include <string>
#include "card.h"
#include "node.h"
#include "deck.h"
#include "d_except.h"
#include "d_random.h"
#include <time.h>

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

deck::deck(const deck &sampleDeck) //copy constructor
{
    temp = sampleDeck.head;

    while (temp != NULL) //traverses through original list to create new list with contents of original list
    {
        addNode(temp->cardInfo);
        temp = temp->next;
    }

    cout << "deck copy constructor invoked " << endl;
}

void deck::addNode(card &newCard)
{
    node<card> *n = new node <card>; //dynamically allocates memory for a node n (with data type card) and creates a pointer to it


    if(n == NULL) //throws error if the heap is out of memory
    {
        throw memoryAllocationError("Memory allocation error for card class");
    }

    n->next = NULL; //sets this node as the end of the list, with its "next" pointer pointing to NULL
    n->cardInfo = newCard; //stores the information from the argument (newCard) in the node's cardInfo

    if(head != NULL) //if the list isn't empty
    {
        curr = head; //assigns pointer curr to point where head is pointing (start of the list)
        while(curr->next != NULL) //while we're not at the end of the list
        {
            curr = curr->next; //advance through the list
        }
        curr->next = n; //assigns the next pointer of the curr node to our new node n, effectively inserting the card into the list
    }
    else //if the list is empty
    {
        head = n; //assign head pointer to node n
    }
}

void deck::printDeck()
{
    if (head == NULL) //won't print unless list has contents
    {
        cout << "list is empty" << endl;
    }
    curr = head; //starts at the beginning of the list
    while(curr != NULL) //while we're not at the end of the list
    {
        cout << curr->cardInfo << endl; //invokes overloaded print operator to print card information
        curr = curr->next; //advance through list
    }
}

card deck::deal() //deal function
{
        curr = head; 
        head = head->next;
        return curr->cardInfo; //returns card info for card at top of deck, removes it from list
}

void deck::replace(card &sampleCard) //adds node at end of list with sampleCard value
{
    addNode(sampleCard);
}

deck & deck::operator = (const deck & sampleDeck) //overloaded assignment operator
{
 
    if(sampleDeck.head == NULL) //throws error if the heap is out of memory
    {
        throw rangeError("original deck is empty");
    }

    head = NULL; //initializes list pointers to NULL
    curr = NULL;
    temp = NULL;


    temp = sampleDeck.head; //starts at beginning of list

        while (temp != NULL) //while we're not at the end of the list
        {
            addNode(temp->cardInfo); //creates node in new list with info from the node in the original list
            temp = temp->next; //advances through list
        }

        cout << "deck overloaded assignmwnt operator invoked " << endl;
    return *this; //returns a reference to object itself
}

deck::~deck() //destructor
{
    while (head != NULL) //while we're not at the end of this list
    {
        curr = head; //starts at beginning of list 
        head = head->next; //reassigns head to next node
        delete curr; //frees dynamically allocated memory for current node
    }
    cout << "destructor invoked" << endl;
}

void deck::shuffle()
{
    cout << "Shuffling. . . " << endl;
    randomNumber r(0); //seeds the generator
    for (int j = 0; j <= 1000; j++) //iterates the swap 1000 times
    {   
        
        int index1 = r.random(52), index2 = r.random(52); //two random indices on interval [0,52)
        node <card> *p1 = head, *p2 = head; //two pointers to nodes with data type card, both initialized to the head of the list

        for (int i = 0; i < index1; i++) //locates and stores the location of the node with index index1
        {
            p1 = p1->next;
        }

        for (int i = 0; i < index2; i++)
        {
            p2 = p2->next;
        }

    card value1 = p1->cardInfo, value2 = p2->cardInfo; //locates and stores the location of the node with index index2
        p1->cardInfo = value2; //swaps their card values
        p2->cardInfo = value1;
    }
}

