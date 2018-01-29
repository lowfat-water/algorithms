#include <iostream>
#include <string>
#include "card.h"

using namespace std;

card::card()
{
    value = 0;
    suit = "not initialized"; 
}

card::card(int newValue, string newSuit)
{
    value = newValue;
    suit = newSuit;
}

void card::get(int &returnValue, string &returnSuit) const
{
    returnValue = value;
    returnSuit = suit;
}

int card::getValue() const
{
    return value;
}

string card::getSuit() const
{
    return suit;
}

void card::set(int &newValue, string &newSuit)
{
    value = newValue;
    suit = newSuit;
}

void card::setValue(int &newValue)
{
    value = newValue;
}

void card::setSuit(string &newSuit)
{
    suit = newSuit;
}

ostream& operator << (ostream& ostr, const card &cards)
{
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