#ifndef CENTS_H
#define CENTS_H

class Cents
{
private:
	int m_cents;
 
public:
	Cents(int cents) { m_cents = cents; }
	int getCents() const { return m_cents; }
};

#endif