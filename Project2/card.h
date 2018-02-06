//card.h file
//definition of card class

#ifndef CARD_H //compiler directives
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class card
{
    public:
        card(); //default constructor
        card(int newValue, string newSuit); //constructor with inputs
        card(const card &sampleCard); //copy constructor
        void get(int &returnValue, string &returnSuit) const; //stores value and suit in variables returnValue and returnSuit
        int getValue() const; //returns value of card
        string getSuit() const; //returns suit of card
        void set(int &newValue, string &newSuit); //assigns values to private data members
        void setValue(int &newValue); //assign value individually
        void setSuit(string &newSuit); //assign suit individually
        friend ostream& operator << (ostream& ostr, const card &cards); //declaration of overloaded print operator
        card operator = (const card & sampleCard); // overloaded assignment operator
    private:
        int value;
        string suit;
};

#endif //compiler directive
