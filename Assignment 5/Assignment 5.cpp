/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 5
    Date due: 02-14-2022
    Description: This program will use pointers to manipulate a dynamically allocated 2 dimensional array.
***********************************************************************************************************************/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <climits>
using namespace std;

typedef int* IntArrayPtr;

void getConstraints(int& row, int& column, int& maximum);
void fillArray(int** students, int row, int column, int maximum);
bool isDuplicate(int** students, int row, int column, int randomNum);
void printArray(int** students, int row, int column);
void printStats(int** students, int row, int column);
void freeSpace(int** students, int row, int column);

int main()
{
    int row = 0;
    int column = 0;
    int maximum = 0;

    getConstraints(row, column, maximum);

    IntArrayPtr *students = new IntArrayPtr[row];
    for(int i = 0; i < row; i++)
    {
        students[i] = new int[column];
    }

    fillArray(students, row, column, maximum);
    printArray(students, row, column);
    printStats(students, row, column);
    freeSpace(students, row, column);

    return 0;
}

/**********************************************************************************************************************
    Name:  getConstraints()
    Description:  This function will get the number of desks and the max random number to generate from the user
    Incoming:  The row, column, and maximum variables all passed by reference
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
void getConstraints(int& row, int& column, int& maximum)
{
    cout << "How many rows of desks are in your class?: " << endl;
    cin >> row;
    cout << endl;

    cout << "How many desks are in each row?: " << endl;
    cin >> column;
    cout << endl;

    cout << "The range of numbers to be assigned will be from 1 to __?:" << endl;
    cin >> maximum;
    cout << endl;

    while(maximum < (row * column))
    {
        cout << "Invalid input! Please try again." << endl << endl;
        cout << "The range of numbers to be assigned will be from 1 to __?:" << endl;
        cin >> maximum;
        cout << endl << endl;
    }
}

/**********************************************************************************************************************
    Name:  fillArray()
    Description:  This function will fill the empty array with random values for each desk in
                    the classroom and check to make sure none of the assigned numbers are
                    duplicates.
    Incoming:  The pointer that gives accesss to the array, and row, column, and maximum variables
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
void fillArray(int** students, int row, int column, int maximum)
{
    int randomNum = 0;

    srand(time(0));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            randomNum = rand() % maximum + 1;

            if(isDuplicate(students, row, column, randomNum))
            {
                j--;
            }
            else
            {
                students[i][j] = randomNum;
            }
        }
    }
}

/**********************************************************************************************************************
    Name:  isDuplicate()
    Description:  This function will take in the random numbers and check to make sure they are
                    not being duplicated
    Incoming:  The pointer that gives accesss to the array, and row, column, and randomNum variables
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
bool isDuplicate(int** students, int row, int column, int randomNum)
{

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(randomNum == students[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

/**********************************************************************************************************************
    Name:  printArray()
    Description:  This function will print out the contents of the array in the layout that
                    the desks would be in in the classroom
    Incoming:  The pointer that gives accesss to the array, and row and column variables
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
void printArray(int** students, int row, int column)
{
    cout << "*****************************************" << endl;
    cout << "Random number assigned to each desk: " << endl;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            cout << setw(5) << right << students[i][j] << " ";
        }
        cout << endl;
    }
    cout << "*****************************************" << endl;
    cout << endl;
}

/**********************************************************************************************************************
    Name:  printStats()
    Description:  This function will find and print out the smallest and largest number generated, and
                    the mean number that was generated
    Incoming:  The pointer that gives accesss to the array, and row, column variables
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
void printStats(int** students, int row, int column)
{
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int sum = 0;
    int counter = 0;
    int mean = 0;

    cout << "*****************************************" << endl;
    cout << "Stats on the array of random numbers: " << endl;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(students[i][j] < minimum)
            {
                minimum = students[i][j];
            }

            if(students[i][j] > maximum)
            {
                maximum = students[i][j];
            }

            sum += students[i][j];
            counter++;
        }
    }
    mean = sum / counter;

    cout << "The smallest value generated was: " << minimum << endl;
    cout << "The largest value generated was: " << maximum << endl;
    cout << "The mean value generated was: " << mean << endl;
    cout << "*****************************************" << endl;
    cout << endl;
}

/**********************************************************************************************************************
    Name:  freeSpace()
    Description:  This function will free up the space that was used when the array was allocated
                    and return it to the program for use in other places
    Incoming:  The pointer that gives accesss to the array, and row, and column variables
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
void freeSpace(int** students, int row, int column)
{
    cout << "Freeing up the space allocated for the array: " << endl;
    for(int i = 0; i < row; i++)
    {
        delete[] students[i];
    }
    delete[] students;
    cout << "The space has been freed and the array has been destroyed!" << endl;
}





