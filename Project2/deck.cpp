//deck.cpp file
//deck class implementation

#include <iostream>
#include <string>
#include "card.h"
#include "node.h"
#include "deck.h"
#include "d_except.h"

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

deck::deck(const deck &sampleDeck)
{
    temp = sampleDeck.head;

    while (temp != NULL)
    {
        addNode(temp->cardInfo);
        temp = temp->next;
    }

    cout << "deck copy constructor invoked " << endl;
    //cout << "the head of the new deck is " << head->cardInfo << endl;
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

card deck::deal()
{

        curr = head;
        head = head->next;
        return curr->cardInfo;
    //cout << " the head is " << head->cardInfo << endl;

    //return curr->cardInfo;
    //delete curr;
}
/*node <card> deck::getCurr(const deck &sampleDeck)
{
    return *curr;
}*/

void deck::replace(card &sampleCard)
{
    addNode(sampleCard);
}

deck & deck::operator = (const deck & sampleDeck)
{
 

    if(sampleDeck.head == NULL) //throws error if the heap is out of memory
    {
        throw rangeError("original deck is empty");
    }

    head = NULL; //initializes list pointers to NULL
    curr = NULL;
    temp = NULL;


    temp = sampleDeck.head;

        while (temp != NULL)
        {
            addNode(temp->cardInfo);
            temp = temp->next;
        }

        cout << "deck overloaded assignmwnt operator invoked " << endl;
    return *this;
}

deck::~deck()
{
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
    cout << "destructor invoked" << endl;
}
void shuffle()
{
    
}
/*
card searchCard (const card & searchCard)
{
  long value;
  long suit;
  randomNumber r(0); //seed the generator

  value = r.random(2:14); //generates random number (0-3)
  suit = r.random(4);
  if (suit == 0)
  {
    card newCard (value, "Clubs");
    searchCard = newCard;
  }

  if (suit == 1)
  {
    card newCard (value, "Diamonds");
    searchCard = newCard;
  }

  if (suit == 2)
  {
    card newCard (value, "Hearts");
    searchCard = newCard;
  }

  if (suit == 3)
  {
    card newCard (value, "Spades");
    searchCard = newCard;
  }
  return searchCard;
}

deck deck::shuffle(deck & sampleDeck)
{
  for (i=0, i<52, i++)
  {
    card key = searchCard;
    x = sampleDeck.head;
    while (x != NULL)
    {
      if (curr->nodeValue != key)
      {
        prev = curr;
        curr = next;
      }
      prev->next = curr->next;
      curr = front;
    }
  }
}*/

/*Sorting implementation:
 use rand to get a random number 0-3. If the card is 0, its clubs. 1 is diamonds.
 2 is hearts. 3 is spades. then randomly choose a number 2-14. Use these to create
 a card to look through the linked list for. Move that card to the front when it
 is found. Iterate 52 times. */
