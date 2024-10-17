/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 10
    Date due: 03-23-2022
    Description: This program will create an array based implementation of a stack.
***********************************************************************************************************************/
#include <iostream>
#include "Stack.h"
using namespace std;

void printMenu();

void getChoice(Stack &stack);


int main()
{
    Stack stack(6);
    getChoice(stack);
    return 0;
}


/**********************************************************************************************************************
    Name:  printMenu()
    Description:  This function will print the menu for the user to select an option from
    Incoming:  None.
    Outgoing:  Print the heading and the menu for the user to choose from
    Return:  None.
***********************************************************************************************************************/
void printMenu()
{
	cout << "Please enter the number of the option you would like to select: " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "1.  Push an item onto stack: " << endl;
    cout << "2.  Pop an item from stack: " << endl;
    cout << "3.  Display the full stack: " << endl;
    cout << "4.  Quit: " << endl;
}



/**********************************************************************************************************************
    Name:  getChoice()
    Description:  This function will manipulate the stack based on the user's input
    Incoming:  The stack
    Outgoing:  Print to the screen the respective outputs
    Return:  None.
***********************************************************************************************************************/
void getChoice(Stack &stack)
{
	int input = 0;
	string temp = " ";

	while (input != 4)
	{
		printMenu();
		cin >> input;

		if (input == 1)
		{
			if(!stack.isFull())
			{
                cout << endl << endl << "Enter the string you want to push: ";
                cin >> temp;
                cout << endl << endl << endl << endl;
                stack.push(temp);
			}
			else
			{
                cerr << "The stack is full!!!" << endl << endl << endl << endl;
			}
		}

		else if (input == 2)
		{
			if (stack.isEmpty())
			{
				cout << "Cannot pop from an empty stack!!!" << endl << endl << endl << endl;
            }
			else
			{
				temp = stack.pop();
				cout << endl << endl << temp << " was popped off the stack!!!" << endl << endl << endl << endl;
            }

		}

		else if (input == 3)
		{
			stack.print();
		}

		else if (input == 4)
		{
			exit(1);
        }

		else
		{
			cerr << "Invalid Input!!!" << endl << endl << endl << endl;
        }
	}
}
