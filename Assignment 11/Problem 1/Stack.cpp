#include "Stack.h"



/**********************************************************************************************************************
    Name: Stack()
    Description:  This constructor will initialize the default values for the object.
    Incoming:  the maximum size of the array.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
Stack::Stack(int newMaxSize)
{
    maxSize = newMaxSize;
    doublePtr = new double[maxSize];
    topIndex = -1;
}



/**********************************************************************************************************************
    Name: ~Stack()
    Description:  This destructor will free up unused data in the stack.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
Stack::~Stack()
{
    delete[] doublePtr;
}



/**********************************************************************************************************************
    Name: push()
    Description:  This member function will push an item onto the stack.
    Incoming:  The new double to be pushed.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Stack::push(double newDouble)
{
    topIndex++;
    doublePtr[topIndex] = newDouble;
}



/**********************************************************************************************************************
    Name: pop()
    Description:  This member function will pop an item off the stack and return int.
    Incoming:  None.
    Outgoing:  None.
    Return:  The item that was popped off the stack.
***********************************************************************************************************************/
double Stack::pop()
{
    double temp = doublePtr[topIndex];
    topIndex--;
    return temp;
}
