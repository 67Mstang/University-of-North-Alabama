#include <iostream>
#include "Customer.h"
#ifndef _QUEUE_H
#define _QUEUE_H
using namespace std;

const int SIZE = 4;

class Customer;

class Queue
{
    private:
        Customer array[SIZE];
        int front;
        int rear;
        int count;

    public:
        Queue();
        void enqueue();
        void dequeue();
        bool isEmpty();
        void printQueue();

};



#endif
