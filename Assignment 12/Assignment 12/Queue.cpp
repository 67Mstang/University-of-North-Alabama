#include "Queue.h"




/**********************************************************************************************************************
    Name: Queue()
    Description:  This constructor will initialize the default values for the object.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
Queue::Queue()
{
    front = -1;
    rear = -1;
    count = 0;

    for(int i = 0; i < SIZE; i++)
    {
        array[i].setName("NULL");
    }
}




/**********************************************************************************************************************
    Name: enqueue()
    Description:  This method will add a Customer object to the Queue.
    Incoming:  the new customer.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Queue::enqueue()
{
    if(count == (SIZE))
    {
        cerr << endl << "Queue is full!!!" << endl;
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }

        Customer myCustomer;

        rear = (rear + 1) % SIZE;
        array[rear] = myCustomer;
        count++;
    }
}




/**********************************************************************************************************************
    Name: dequeue()
    Description:  This method will remove a Customer object to the Queue.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is empty!!!" << endl;
    }
    else
    {
        array[front] = Customer();

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        count--;
    }
}




/**********************************************************************************************************************
    Name: isEmpty()
    Description:  This method will check if the queue is empty.
    Incoming:  None.
    Outgoing:  None.
    Return:  bool.
***********************************************************************************************************************/
bool Queue::isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}



/**********************************************************************************************************************
    Name: printQueue()
    Description:  This method will print each member of each Customer.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Queue::printQueue()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(!(array[i].getName() == "NULL"))
        {
            cout << array[i].getName() << endl;
            cout << "   " << array[i].getArrival() << endl;
            cout << "   " << array[i].getDeparture() << endl;
            cout << "   " << array[i].getService() << endl;
            cout << "   " << array[i].getProcess() << endl;
        }
    }
    cout << endl << endl << endl;
}








