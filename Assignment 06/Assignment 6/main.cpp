/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 3
    Date due: 01-31-2022
    Description: This program will build off of assignment 3 and add consturctors, and a destructor.  It will
                    also add several new functions and member functions and adjust main to use all of the functions.
***********************************************************************************************************************/
#include <iostream>
#include "Assignment6.h"
using namespace std;

const int MAX_GAMES = 50;
const double DISCOUNT = 0.90;

void readFromFile(Game[], int&);                        // read in the game information from the text file
void printAllGames(Game[], int&);                       // print a listing of all the games stored in the array

int main()
{
    int numGames = 0;
    Game board1, board2, board3, board10, board11;
    Game boards[MAX_GAMES];

    cout << "Print the original games from assignment3" << endl;
    cout << "**************************************************************" << endl;
    board1.setDescription("Monopoly");
    board1.setMinPlayers(2);
    board1.setMaxPlayers(8);
    board1.setMinAge(8);
    board1.setPrice(24.99);
    board1.print();

    board2.setDescription("Clue");
    board2.setMinPlayers(3);
    board2.setMaxPlayers(6);
    board2.setMinAge(8);
    board2.setPrice(12.99);
    board2.print();

    board3.setDescription("Scrabble");
    board3.setMinPlayers(2);
    board3.setMaxPlayers(4);
    board3.setMinAge(8);
    board3.setPrice(42.99);
    board3.print();

    cout << endl << endl << endl << endl;
    /*cout << "Print the Monopoly game before updating the price, then after" << endl;
    cout << "**************************************************************" << endl;
    board1.print();
    board1.updatePrice(DISCOUNT);
    board1.print();

    cout << endl << endl << endl << endl;
    cout << "Print all of the new games read in from the file" << endl;
    cout << "**************************************************************" << endl;
    readFromFile(boards, numGames);
    printAllGames(boards, numGames);

    cout << endl << endl << endl << endl;
    cout << "**************************************************************" << endl;*/

    cout << "While the boards are different: " << endl;
    if(board1 == board2)
    {
        cout << "They are the same!" << endl;
    }
    else
    {
        cout << "They are NOT the same!" << endl;
    }

    board2.setDescription("Monopoly");
    board2.setMinPlayers(2);
    board2.setMaxPlayers(8);
    board2.setMinAge(8);
    board2.setPrice(24.99);
    cout << endl;

    cout << "While the boards are the same: " << endl;
    if(board1 == board2)
    {
        cout << "They are the same!" << endl;
    }
    else
    {
        cout << "They are NOT the same!" << endl;
    }

    cout << endl << endl << endl;
    cout << "Adding board 1 and board 2" << endl << endl;

    board10 = board1 + board2;
    board10.print();

    cout << endl << endl << endl;
    cout << "Using the << operator instead of the print function: " << endl;

    cout << board3 << endl;

    cout << endl << endl << endl;

    cout << "Enter the following details about a board game: " << endl;
    cout << "(Be sure to enter the data exactly as shown!!)" << endl << endl;
    cout << "Name" << endl;
    cout << "Min_Players    Max_Players     Min_Age     Price   (Seperated by a space!!)" << endl << endl;
    cin >> board11;
    cout << endl << board11 << endl;

    return 0;
}
