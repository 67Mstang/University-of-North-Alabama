/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 11
    Date due: 04-19-2022
    Description: This program will utilize a queue to store in Customers in a grocery store check out line.
    			 The duration of the simulation, average number of arriving customers, average check out time,
    			 number of lines, and whether or not a clock is displayed will be passed in as arguments
    			 from the command line.
***********************************************************************************************************************/

#include <iostream>
#include "unistd.h"
#include "Queue.h"
#include "Customer.h"
using namespace std;

int main()
{
    int clock = 0;
    int additions = 0;

    while(clock < 60)
    {
        cout << "Minute  " << clock << ":   " << endl;
        sleep(2);
        clock++;
    }



    /*const int MAX = 4;

    Queue queues[MAX];

    for(int i = 0; i < MAX; i++)
    {
        queues[i].printQueue();
    }*/

    return 0;
}
