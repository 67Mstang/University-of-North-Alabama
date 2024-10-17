#include <iostream>
using namespace std;

class Stack
{
    private:
            int maxSize;
            int topIndex;
            double* doublePtr;
    public:
            Stack(int newMaxSize);
            ~Stack();
            void push(double newString);
            double pop();
};
