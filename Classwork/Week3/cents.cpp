#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;
    
public:
    Cents (int cents) { m_cents = cents;} 

    friend Cents operator + (const Cents &c1, const Cents &c2); //define it in header file
 

    int getCents() const { return m_cents; }
};

//class implementation
Cents operator + ( const Cents &c1, const Cents &c2) //no scope operator, no friend keyword
{
    //can access constructor and operator+(int, int)
    //can access m_cents directly because it is a friend
    return Cents(c1.m_cents + c2.m_cents);
}


int main()
{
    Cents cents1(6);
    Cents cents2(8);
    Cents centsSum = cents1 + cents2;

    cout << "i have " << centsSum.getCents() << " cents. " << endl;
}