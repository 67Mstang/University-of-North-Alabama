/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 9 (reader)
    Date due: 03-13-2022
    Description: This program will read in from a .dat file and print out the bowler data.  It will also print
                    a heading after every 50 lines.
***********************************************************************************************************************/




#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;




const int NUMBER_OF_BOWLERS = 10000;




struct BowlType
{
    int bowlID;
    char teamName[30];
    int game1;
    int game2;
    int game3;
};




void printHeading();




int main()
{
    fstream in;
    BowlType bowler;

    int counter = 0;

    in.open("Bowling.dat", ios::binary | ios::in);

    printHeading();

    while(!in.eof())
    {

        in.read(reinterpret_cast<char*>(&bowler), sizeof(bowler));

        if(!in.eof())
        {
            if(counter == 50)
            {
                printHeading();
                counter = 0;
            }

            cout << left << setw(8) << bowler.bowlID << setw(30) << bowler.teamName <<
                setw(10) << bowler.game1 << setw(10) << bowler.game2 << setw(10) <<
                bowler.game3 << endl;
        }

        counter++;
    }

    in.close();

    return 0;
}




/**********************************************************************************************************************
    Name:  printHeading()
    Description:  This member function will print the heading for the bowling data.
    Incoming:  None.
    Outgoing:  Print the heading with the desired titles.
    Return:  None.
***********************************************************************************************************************/
void printHeading()
{
    cout << endl << endl << " ID:        Team Name:             Game 1:    Game 2:    Game 3:" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}
