/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 2
    Date due: 01-19-2022
    Description: This program will read in quarter backs and their stats from a text file and fill an array
                    of structs with the given stats.  Then it will calculate the needed percentages and print
                    the data in a chart.  Then sort the data ascending by last name and print the chart again,
                    then it will sort the data descending by rating and print the data one last time.
***********************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;




const int MAX_BACKS = 500;          // declare constant variables




// declare a struct for qb stats and give it all the needed members
struct stats
{
  string firstName;
  string lastName;

  int attempts;
  int completions;
  int passingYards;
  int touchdowns;
  int interceptions;
  double rating;
};




// function declarations / prototypes
void readFromFile(stats backs[], int &num);
void print(stats backs[], int num);
double completionPercentage(int completions, int attempts);
double qbRating(int completions, int passingYards, int touchdowns, int attempts, int interceptions);
void sortLastNameAscending(stats backs[], int num);
void sortRatingDescending(stats backs[], int num);




int main()
{
    int numBacks = 0;           // make the counter to keep track of how many qb's there are
    stats backs[MAX_BACKS];         // make an array of structs to keep track of all the players

    readFromFile(backs, numBacks);          // call the function to read from the file and fill the array
    print(backs, numBacks);         // print the chart with all of the qb information

    cout << endl << endl << endl << endl << "SORTED ASCENDING BY LAST NAME:" << endl << endl;

    sortLastNameAscending(backs, numBacks);         // sort the data by last name ascending
    print(backs, numBacks);         //  print the chart after being sorted

    cout << endl << endl << endl << endl << "SORTED DESCENDING BY QB RATING" << endl << endl;

    sortRatingDescending(backs, numBacks);      //  sort the data by rating descending
    print(backs, numBacks);         // print the chart again after being sorted

    cout << endl << endl << endl << endl;

    return 0;
}




/**********************************************************************************************************************
    Name:  sortLastNameAscending()
    Description:  This function will sort the array of structs by last name into ascending order
    Incoming:  The array of structs containing all the data, and the counter for the number of qb's
    Outgoing:  None
    Return:  None
***********************************************************************************************************************/
void sortLastNameAscending(stats backs[], int num)
{
    // use selection sort to sort the data
    stats temp;
    int minIndex = 0;
    for(int i = 0; i < num - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < num; j++)
        {
           if(backs[j].lastName < backs[minIndex].lastName)
           {
                minIndex = j;
           }
        }
        temp = backs[i];
        backs[i] = backs[minIndex];
        backs[minIndex] = temp;
    }
}




/**********************************************************************************************************************
    Name:  sortRatingDescending()
    Description:  This function will sort the array of structs by rating in descending order
    Incoming:  The array of structs containing all the data, and the counter for the number of qb's
    Outgoing:  None
    Returning:  None
***********************************************************************************************************************/
void sortRatingDescending(stats backs[], int num)
{
    // use selection sort to sort the data
    stats temp;
    int minIndex = 0;
    for(int i = 0; i < num - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < num; j++)
        {
           if(backs[j].rating > backs[minIndex].rating)
           {
                minIndex = j;
           }
        }
        temp = backs[i];
        backs[i] = backs[minIndex];
        backs[minIndex] = temp;
    }
}




/**********************************************************************************************************************
    Name:  print()
    Description:  This function will print out an easy to read chart containing all the data from the text file
    Incoming:  The array of structs containing all the data, and the counter for the number of qb's
    Outgoing:  The chart of data to the screen
    Returning:  None
***********************************************************************************************************************/
void print(stats backs[], int num)
{
    cout << left << setw(20) << "Quarterback" << setw(7) << "Att." << setw(7) << "Comp." << setw(7) << "pct."           // print the header
         << setw(7) << "Yards" << setw(7) << "TD" << setw(7) <<  "Int." << setw(7) << "Rating" << endl
         << "-----------        -----  ------  ----   -----  --     ----   ------" << endl;


    for(int i = 0; i < num; i++)            // loop for each player
    {
        string fullName;
        double completion;
        double rating;

        fullName = backs[i].firstName + " " + backs[i].lastName;            // combine the names in order to use set width
        completion = completionPercentage(backs[i].completions, backs[i].attempts);         // call the fuction to calculate the completion Percentage
        backs[i].rating = qbRating(backs[i].completions, backs[i].passingYards,         // call the function to calculate the rating
                          backs[i].touchdowns, backs[i].attempts, backs[i].interceptions);

        cout << setw(20) << fullName << right <<setw(3) << backs[i].attempts << setw(8) << backs[i].completions << setw(7) << fixed
             << setprecision(1) << completion << scientific << setw(8) << setprecision(0) << backs[i].passingYards << setw(4)
             << backs[i].touchdowns << setw(8) << backs[i].interceptions << setw(9) << fixed << setprecision(2) << backs[i].rating
             << left << scientific << endl;         // print all of the data using the correct formatting
    }
}




/**********************************************************************************************************************
    Name:  qbRating()
    Description:  This function will use the given formula to calculate a rating for each player based on their given stats
    Incoming:  # of completions, # of passing yards, # of touchdowns, # of attempts, and # of interceptions for each player
    Outgoing:  None
    Returning:  return the calculated rating for the given player
***********************************************************************************************************************/
double qbRating(int completions, int passingYards, int touchdowns, int attempts, int interceptions)
{
    double rating;

    rating = ((4 * completions) + (1.2 * passingYards) + (8 * touchdowns)) / ((static_cast<double>(attempts)) + (6 * interceptions));   // cast so math
                                                                                                                                        // will be
                                                                                                                                        // correct

    if(attempts == 0)
    {
        return 0;
    }
    else
    {
        return rating;
    }
}




/**********************************************************************************************************************
    Name:  completionPercentage()
    Description:  This function will calculate the completion percentage for the given player based on the data
                        from the file
    Incoming:  # of completions, and # of attempts
    Outgoing:  None
    Returning:  The calculated completion percentage for the given player
***********************************************************************************************************************/
double completionPercentage(int completions, int attempts)
{
    double result = 0;

    result = completions / static_cast<double>(attempts);           // cast to double so math will be correct

    if(attempts == 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}




/**********************************************************************************************************************
    Name:  readFromFile()
    Description:  This function will read from the text file and save all the data into the array of structs
    Incoming:  The array of structs to be filled, and the counter for the number of qb's
    Outgoing:  None
    Returning:  None
***********************************************************************************************************************/
void readFromFile(stats backs[], int &num)
{
    num = 0;            // set the counter variable to 0
    ifstream in("football-in.txt");         // open the file
    in >> backs[num].firstName;         // prime the loop
    while(!in.eof())            // while not at the end
    {
        in >> backs[num].lastName;          // put the data in the correct location of the array of structs
        in >> backs[num].attempts;
        in >> backs[num].completions;
        in >> backs[num].passingYards;
        in >> backs[num].touchdowns;
        in >> backs[num].interceptions;
        num++;          // increment to go to the next player
        in >> backs[num].firstName;         // ask for this again because it is not in the loop the first time
    }
    in.close();         // close the file
}
