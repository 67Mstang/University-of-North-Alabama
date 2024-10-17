/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 11
    Date due: 03-25-2022
    Description: This program will utilize a stack to take in a user entered number of user entered doubles,
                    and print them as output in the reverse of the order they were entered.
***********************************************************************************************************************/
#include "Stack.h"

int main()
{
    int numEntry = 0;

    cout << "How many decimal numbers? ";
    cin >> numEntry;
    cout << endl << endl;

    Stack stack(numEntry);

    for(int i = 0; i < numEntry; i++)
    {
        double num = 0;

        cout << "Input #" << i + 1 << "? ";
        cin >> num;

        stack.push(num);
    }

    cout << endl << endl << "Output: ";

    for(int i = 0; i < numEntry; i++)
    {
        double temp = 0;
        temp = stack.pop();

        cout << temp << " ";
    }

    cout << endl << endl;

    return 0;
}
