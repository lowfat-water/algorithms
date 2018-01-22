// File response.h
// response class definition

#ifndef RESPONSE_H // to avoid multiple definitions
#define RESPONSE_H // compiler directive

class response
{
public: 
    response();
    void setCorrect(int numCorrect);
    void setIncorrect(int numIncorrect);
    int getCorrect();
    int getIncorrect();
    bool compare(response response1); // compares responses and returns true if they are equal
    void print(); // prints a response
private:
    int correct;
    int incorrect;
};

#endif