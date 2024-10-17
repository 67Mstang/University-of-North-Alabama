#include "Customer.h"
#include <ctime>




/**********************************************************************************************************************
    Name: Customer()
    Description:  This constructor will initialize the default values for the object.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
Customer::Customer()
{
    string names[20] {"John", "Billy", "Joe", "Wayne", "Bobby", "Bill", "Nathan", "Ryan", "Chris", "Ashley", "Michelle", "Mike", "Jerry", "Tom",
                        "Gary", "Mary", "May", "Sarah", "Becky", "Anna"};


    srand(time(0));
    name = names[rand() % 20];
    arrival = (rand()  + 1) % 10;
    departure = (rand()  + 1) % 10;
    service = (rand()  + 1) % 10;
    process = (rand()  + 1) % 10;
}




/**********************************************************************************************************************
    Name: setName()
    Description:  This is the setter for the name member.
    Incoming:  the new name.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Customer::setName(string newName)
{
    name = newName;
}




/**********************************************************************************************************************
    Name: getName()
    Description:  This is the getter for the name member.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
string Customer::getName() const
{
    return name;
}




/**********************************************************************************************************************
    Name: setArrival()
    Description:  This is the setter for the arrival member.
    Incoming:  the new arrival time.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Customer::setArrival(int newArrival)
{
    arrival = newArrival;
}




/**********************************************************************************************************************
    Name: getArrival()
    Description:  This is the getter for the arrival time member.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
int Customer::getArrival() const
{
    return arrival;
}




/**********************************************************************************************************************
    Name: setDeparture()
    Description:  This is the setter for the departure member.
    Incoming:  the new departure time.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Customer::setDeparture(int newDeparture)
{
    departure = newDeparture;
}




/**********************************************************************************************************************
    Name: getDeparture()
    Description:  This is the getter for the departure time member.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
int Customer::getDeparture() const
{
    return departure;
}




/**********************************************************************************************************************
    Name: setService()
    Description:  This is the setter for the service member.
    Incoming:  the new service time.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Customer::setService(int newService)
{
    service = newService;
}




/**********************************************************************************************************************
    Name: getService()
    Description:  This is the getter for the service time member.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
int Customer::getService() const
{
    return service;
}




/**********************************************************************************************************************
    Name: setProcess()
    Description:  This is the setter for the process member.
    Incoming:  the new process time.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
void Customer::setProcess(int newProcess)
{
    process = newProcess;
}




/**********************************************************************************************************************
    Name: getProcess()
    Description:  This is the getter for the process time member.
    Incoming:  None.
    Outgoing:  None.
    Return:  None.
***********************************************************************************************************************/
int Customer::getProcess() const
{
    return process;
}




















