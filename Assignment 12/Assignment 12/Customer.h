#include <iostream>
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
using namespace std;

class Customer
{
    private:
        string name;
        int arrival;
        int departure;
        int service;
        int process;

    public:
        Customer();
        void setName(string newName);
        string getName() const;
        void setArrival(int newArrival);
        int getArrival() const;
        void setDeparture(int newDeparture);
        int getDeparture() const;
        void setService(int newService);
        int getService() const;
        void setProcess(int newProcess);
        int getProcess() const;
};



#endif
