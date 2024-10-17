#include <iostream>
using namespace std;

class Stack
{
    private:
        int maxSize;
        int topIndex;
        string* strPtr;

    public:
        Stack(int newMaxSize);
        ~Stack();
        void push(string newString);
        string pop();
        bool isFull();
        bool isEmpty();
        void print();
};
