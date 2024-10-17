/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 11
    Date due: 03-25-2022
    Description: This program utilize a stack to store the numbers in the middle of the string, then it
                    will pop them off, convert them to int, and multiply them by a scalar and sum the
                    numbers.  Then it will print out the total debt.
***********************************************************************************************************************/
#include "Stack.h"

int main()
{
    string input = "NULL";
    int length = 0;
    int sum = 0;
    int scalar = 1;

    getline(cin, input);
    length = input.length();
    Stack stack(length);
    int array[length];

    for(int i = 0; i < length; i++)
    {
        if(isdigit(input[i]))
        {
            stack.push(input[i]);
        }
    }

    while(!stack.empty())
    {
        int temp = stack.pop();

        temp -= '0';

        sum += temp * scalar;
        scalar *= 10;
    }

    cout << endl << endl << "Total debt is: " << sum << endl;

    return 0;
}
