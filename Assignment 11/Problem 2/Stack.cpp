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
    charPtr = new char[maxSize];
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
    delete[] charPtr;
}



/**********************************************************************************************************************
    Name: push()
    Description:  This member function will push an item onto the stack.
    Incoming:  The new char to be pushed.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Stack::push(char newChar)
{
    topIndex++;
    charPtr[topIndex] = newChar;
}



/**********************************************************************************************************************
    Name: pop()
    Description:  This member function will pop an item off the stack and return char.
    Incoming:  None.
    Outgoing:  None.
    Return:  The item that was popped off the stack.
***********************************************************************************************************************/
char Stack::pop()
{
    char temp = charPtr[topIndex];
    topIndex--;
    return temp;
}



/**********************************************************************************************************************
    Name: empty()
    Description:  This member function will check if the stack is empty.
    Incoming:  None.
    Outgoing:  None.
    Return:  True if the stack is empty and false if the stack is not empty.
***********************************************************************************************************************/
bool Stack::empty()
{
    if(topIndex == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
