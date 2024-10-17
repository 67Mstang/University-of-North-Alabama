/******************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 1
    Date due: 01-12-2022
    Description: This program will use functions to read from the file and fill parallel arrays with names
                    and ID's, print the contents of the arrays in a nice output, sort the arrays
                    alphabetically, and search the arrays by ID number and return the position where it
                    was found.  The main will support the use of each of these functions.
*******************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



// declare functions
void fillArray(string names[], int nums[], int size, int& students);

void print(string names[], int nums[], int size, int& students);

void sortName(string names[], int nums[], int students);

int linearSearch(int nums[], int students, int key);



/******************************************************************************************************************/
int main()
{
    // declare variables
    const int SIZE = 100;

    string names[SIZE];
    int nums[SIZE];

    int students = 0;
    int key = -100;
    int result = -100;



    // call the fillArray() function to fill the parallel arrays with values from the file
    fillArray(names, nums, SIZE, students);



    // call the sortName() function to sort the parallel arrays alphabetically by first name
    sortName(names, nums, students);



    // call the print function to print the sorted arrays in an easy to read list with headers
    print(names, nums, SIZE, students);



    // prompt the user for the ID they would like to search for
    cout << "Please enter a Student ID to search for: ";
    cin >> key;
    cout << endl << endl;



    // call the linearSearch() function to search for the key from the user and save into result
    result = linearSearch(nums, students, key);



    // print the correct output for if the ID was present in the array or not
    if(result == -1)
    {
        cerr << "ERROR!!!" << endl << "Student ID: " << key << " is not found!!!" << endl << endl;
    }
    else
    {
        cout << "Success!!!" << endl;
        cout << "Student ID: " << key << " was found at index " << result << "!" << endl;
        cout << "Student Name: " << names[result] << endl << endl;
    }



    return 0;
}
/******************************************************************************************************************/





/******************************************************************************************************************
    Function Name: fillArray()
    Function Description: This function will read from the file to fill the parallel arrays and keep track of
                            the number of students that are read in from the file.
    Incoming: Array of names, array of numbers, size of array, student counter pass by reference.
    Outgoing: None.
    Return:   None.
*******************************************************************************************************************/
void fillArray(string names[], int nums[], int size, int& students)
{

    ifstream in;
    in.open("students.txt");

    string input = "NULL";
    int input1 = -1;

    for(int i = 0; i < size; i++)
    {
        names[i] = "NULL";
        nums[i] = -1;
    }

    for(int i = 0; i < size; i++)
    {
        in >> input;

        if(input != "NULL")
        {
            names[i] = input;
            in >> input1;
            nums[i] = input1;
            students++;
        }

        input = "NULL";
    }

    in.close();

}





/******************************************************************************************************************
    Function Name: print()
    Function Description: This function will print out the contents of the parallel arrays in an easy to
                            read format.
    Incoming: Array of names, array of numbers, size of array, student counter pass by reference.
    Outgoing: List of names and their corresponding ID numbers evenly spaced with headers.
    Return:   None.
*******************************************************************************************************************/
void print(string names[], int nums[], int size, int& students)
{
    cout << "***************************************" << endl;
    cout << setw(20) << setfill(' ') << left << "Names:" << "Numbers:" << endl;
    cout << "***************************************" << endl;

    for(int i = 0; i < students; i++)
    {
        cout << setfill(' ') << setw(20) << left << names[i] << setfill('0') << setw(5) << right << nums[i] << endl;
    }

    cout << "***************************************" << endl;
}





/******************************************************************************************************************
    Function Name: sortName()
    Function Description: This function will sort the parallel arrays into alphabetical order by
                            first name.
    Incoming: Array of names, array of numbers, student counter.
    Outgoing: None.
    Return:   None.
*******************************************************************************************************************/
void sortName(string names[], int nums[], int students)
{
    string temp = "-1";
    int temp1 = 0;
    int minIndex = 0;

    for(int i = 0; i < students - 1; i++)
    {
        minIndex = i;

        for(int j = i + 1; j < students; j++)
        {
            if(names[j] < names[minIndex])
            {
                minIndex = j;
            }

            temp = names[i];
            temp1 = nums[i];

            names[i] = names[minIndex];
            nums[i] = nums[minIndex];

            names[minIndex] = temp;
            nums[minIndex] = temp1;
        }
    }
}





/******************************************************************************************************************
    Function Name: linearSearch()
    Function Description: This function will search the ID array for a user entered ID, if the
                            ID is present it will return the position of the number, and if the
                            ID is not present it will return -1.
    Incoming: Array of numbers, student counter, user entered key.
    Outgoing: None.
    Return:   If the key is present in the ID array it will return the position of the ID,
                and if the key is not present in the ID array it will return -1.
*******************************************************************************************************************/
int linearSearch(int nums[], int students, int key)
{
    bool found = false;
    int position = 0;

    while(!found && position < students)
    {
        if(nums[position] == key)
        {
            found = true;
        }
        else
        {
            position++;
        }
    }

    if(found)
    {
        return position;
    }
    else
    {
        return -1;
    }
}
