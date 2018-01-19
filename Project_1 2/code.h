// File code.h
// code class definition

#ifndef CODE_H // to avoid multiple definitions
#define CODE_H // compiler directive

#include <vector>

using namespace std;

class code //stores code (guess or secret) as a vector
{
    public:
        code();
        void initRandom(); //initializes a random code
        int checkCorrect(code guess) const; //passed a guess and returns number of correct digits in the correct location
        int checkIncorrect(code guess) const; //passed a guess and returns number of correct digits in the correct location
    private: //does this need to be private?
        vector<int> value;
        
};

#endif

