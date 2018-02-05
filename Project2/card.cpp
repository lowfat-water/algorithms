//change to test commit
//card.cpp file
//class card implementation

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

card::card() //default constructor with no arguments
{
    value = 0;
    suit = "not initialized";
}

card::card(int newValue, string newSuit) //constructor which assigns arguments to private data members
{
    value = newValue;
    suit = newSuit;
}

card::card(const card & sampleCard)
{
    value = sampleCard.value;
    suit = sampleCard.suit;
//    cout << "copy constructor" << endl;
}

void card::get(int &returnValue, string &returnSuit) const //stores values in private data members in variables returnValue and returnSuit
{
    returnValue = value;
    returnSuit = suit;
}

int card::getValue() const //returns value
{
    return value;
}

string card::getSuit() const //returns suit
{
    return suit;
}

void card::set(int &newValue, string &newSuit) //assign values to private data members
{
    value = newValue;
    suit = newSuit;
}

void card::setValue(int &newValue) //assign value
{
    value = newValue;
}

void card::setSuit(string &newSuit) //assign suit
{
    suit = newSuit;
}

ostream& operator << (ostream& ostr, const card &cards) //overloaded print operator
{
    //for numeric cards, prints the value of the card and the suit
    //for face cards, prints a string that represents the card
    if(cards.getValue() == 11)
    {
        ostr << "Jack" << " of " << cards.getSuit();
        return ostr;
    }

    if(cards.getValue() == 12)
    {
        ostr << "Queen" << " of " << cards.getSuit();
        return ostr;
    }

    if(cards.getValue() == 13)
    {
        ostr << "King" << " of " << cards.getSuit();
        return ostr;
    }

    if(cards.getValue() == 14)
    {
        ostr << "Ace" << " of " << cards.getSuit();
        return ostr;
    }

    else
    {
        ostr << cards.getValue() << " of " << cards.getSuit();
        return ostr;
    }
}
card card::operator = (const card & sampleCard)
{
    value = sampleCard.value;
    suit = sampleCard.suit;
    return *this; //returns a reference to the object itself
}
