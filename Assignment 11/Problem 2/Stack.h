#include <iostream>
using namespace std;

class Stack
{
    private:
            int maxSize;
            int topIndex;
            char* charPtr;
    public:
            Stack(int newMaxSize);
            ~Stack();
            void push(char newChar);
            char pop();
            bool empty();
};
