/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 8
    Date due: 03-09-2022
    Description: This program will create a linked list.  It will display a menu to the user with different options
                    to choose from.
                    1.) Display List
                    2.) Add To Head
                    3.) Add To Tail
                    4.) Search Given Type
                    5.) Delete Node Given Pet Name
                    6.) Print Average Age For All Pets (Iterative)
                    7.) Print Average Age For All Pets (Recursive)
                    8.) Quit
***********************************************************************************************************************/
#include <iostream>
#include "pets.h"
using namespace std;

int main()
{
    IntNodePtr head = nullptr;

    int input = 0;

    while(input != 8)
    {
        input = displayMenu();

        if(input == 1)
        {
            display(head);
        }
        else
        {
            if(input == 2)
            {
                headInsert(head);
            }
            else
            {
                if(input == 3)
                {
                    tailInsert(head);
                }
                else
                {
                    if(input == 4)
                    {
                        searchGivenType(head);
                    }
                    else
                    {
                        if(input == 5)
                        {
                            deleteNodeByName(head);
                        }
                        else
                        {
                            if(input == 6)
                            {
                                averageAgeIterative(head);
                            }
                            else
                            {
                                if(input == 7)
                                {
                                    averageAgeRecursive(head);
                                }
                                else
                                {
                                    if(input != 8)
                                    {
                                        cerr << "Invalid Input!!!" << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
