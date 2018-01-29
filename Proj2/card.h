#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class card
{
    public:
        card();
        card(int newValue, string newSuit);
        void get(int &returnValue, string &returnSuit) const;
        int getValue() const;
        string getSuit() const;
        void set(int &newValue, string &newSuit);
        void setValue(int &newValue);
        void setSuit(string &newSuit);

        friend ostream& operator << (ostream& ostr, const card &cards);
    private:
        int value;
        string suit;
};

#endif