#include <iostream>
using namespace std;

template <typename T>
class cMyFirstTemplateClass
{
    public:
        void setVariable(T& newValue) {m_Value =  newValue;};
        T& getValue() {return m_Value;};

    private:
        T m_Value;
}