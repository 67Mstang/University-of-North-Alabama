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
    strPtr = new string[maxSize];
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
    delete[] strPtr;
}




/**********************************************************************************************************************
    Name: push()
    Description:  This member function will push an item onto the stack.
    Incoming:  The new string to be pushed.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Stack::push(string newString)
{
    topIndex++;
    strPtr[topIndex] = newString;
}




/**********************************************************************************************************************
    Name: pop()
    Description:  This member function will pop an item off the stack and return int.
    Incoming:  None.
    Outgoing:  None.
    Return:  The item that was popped off the stack.
***********************************************************************************************************************/
string Stack::pop()
{
    string temp = strPtr[topIndex];
    strPtr[topIndex] = "NULL";
    topIndex--;
    return temp;
}




/**********************************************************************************************************************
    Name: isFull()
    Description:  This member function will check if the stack is full.
    Incoming:  None.
    Outgoing:  None.
    Return:  True if stack is full and false if stack is not full.
***********************************************************************************************************************/
bool Stack::isFull()
{
    if(topIndex == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}




/**********************************************************************************************************************
    Name: isEmpty()
    Description:  This member function will check if the stack is empty.
    Incoming:  None.
    Outgoing:  None.
    Return:  True if the stack is empty and false if the stack is not empty.
***********************************************************************************************************************/
bool Stack::isEmpty()
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




/**********************************************************************************************************************
    Name: print()
    Description:  This member function will print the entire stack.
    Incoming:  None.
    Outgoing:  Print the stack in the correct order stacked on top of each other.
    Return:  None.
***********************************************************************************************************************/
void Stack::print()
{
    cout << endl << endl;

    if(!isEmpty())
    {
        for(int i = maxSize - 1; i >= 0; i--)
        {
            if(strPtr[i] != "NULL")
            {
                cout << strPtr[i] << endl;
            }
        }
        cout << endl << endl;
    }
    else
    {
        cerr << "Stack is empty!!!" << endl << endl;
    }


    cout << endl << endl;
}
