/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 3
    Date due: 01-31-2022
    Description: This program will build off of assignment 3 and add consturctors, and a destructor.  It will
                    also add several new functions and member functions and adjust main to use all of the functions.
***********************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int MAX_GAMES = 50;
const double DISCOUNT = 0.90;

class Game
{
    private:
        string description;
        int minPlayers, maxPlayers, minAge;
        double price;
    public:
        void setDescription(string);                    // populate the name of the game
        void setMinPlayers(int);                        // populate the minimum # of players
        void setMaxPlayers(int);                        // populate the maximum # of players
        void setMinAge(int);                            // populate the minimum age of players
        void setPrice(double);                          // populate the price of the game
        string getDescription() const;                  // retrieve the name of the game
        int getMinPlayers() const;                      // retrieve the minimum # of players
        int getMaxPlayers() const;                      // retrieve the maximum # of players
        int getMinAge() const;                          // retrieve the minimum age of players
        double getPrice() const;                        // retrieve the price of the game
        void print() const;                             // print out each member of the object
        Game();                                         // constructor
        Game(string, int, int, int, double);            // destructor
        void initialize();                              // populate each member of the object with specified values
        ~Game();                                        // destructor
        void updatePrice(double);                       // update the price of the object to reflect a specified discount
        void setGame(string, int, int, int, double);    // populate every member of an object at the same time with specified values
};

void readFromFile(Game[], int&);                        // read in the game information from the text file
void printAllGames(Game[], int&);                       // print a listing of all the games stored in the array

int main()
{
    int numGames = 0;
    Game board1, board2, board3;
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
    cout << "Print the Monopoly game before updating the price, then after" << endl;
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
    cout << "**************************************************************" << endl;

    return 0;
}

/**********************************************************************************************************************
    Name:  printAllGames()
    Description:  This function will print all of the game objects and members stored in the boards[] array
    Incoming:  The array of objects(game boards), and the counter for number of games read from the file
    Outgoing:  Call the .print() member function to print each of the entries in the array
    Return:  None
***********************************************************************************************************************/
void printAllGames(Game board[], int &num)
{
    for(int i = 0; i < num; i++)
    {
        board[i].print();
    }
}

void Game::setGame(string name, int min, int max, int age, double cost)
{
    description = name;
    minPlayers = min;
    maxPlayers = max;
    minAge = age;
    price = cost;
}

/**********************************************************************************************************************
    Name:  readFromFile()
    Description:  This function will read from a file and populate the array of Game objects
    Incoming:  The array of objects(game boards), and the counter for number of games read from the file
    Outgoing:  Sending the newly read in information to the object specified in each array position
    Return:  None
***********************************************************************************************************************/
void readFromFile(Game board[], int &num)
{
    string name = "null";
    int minimum = 0;
    int maximum = 0;
    int age = 0;
    double cost = 0;
    num = 0;
    ifstream in;
    in.open("boardgames.txt");

    getline(in, name);
    while(!in.eof())
    {
        in >> minimum >> maximum >> age >> cost;
        board[num].setGame(name, minimum, maximum, age, cost);
        num++;
        in.ignore();
        getline(in, name);
    }

    in.close();
}

void Game::updatePrice(double discountRate)
{
    price *= discountRate;
}


Game::~Game()
{
    cout << "BoardGame is destroyed" << endl;
}

void Game::initialize()
{
    description = "TBA";
    minPlayers = 0;
    maxPlayers = 0;
    minAge = 0;
    price = 0;
}

Game::Game(string inDescription, int inMinPlayers, int inMaxPlayers, int inMinAge, double inPrice)
{
    description = inDescription;
    minPlayers = inMinPlayers;
    maxPlayers = inMaxPlayers;
    minAge = inMinAge;
    price = inPrice;
}

Game::Game()
{
    description = "TBA";
    minPlayers = 0;
    maxPlayers = 0;
    minAge = 0;
    price = 0;
}

void Game::setDescription(string name)
{
    description = name;
}

void Game::setMinPlayers(int numPlayers)
{
    minPlayers = numPlayers;
}

void Game::setMaxPlayers(int numPlayers)
{
    maxPlayers = numPlayers;
}

void Game::setMinAge(int age)
{
    minAge = age;
}

void Game::setPrice(double cost)
{
    price = cost;
}

string Game::getDescription() const
{
    return description;
}

int Game::getMinPlayers() const
{
    return minPlayers;
}

int Game::getMaxPlayers() const
{
    return maxPlayers;
}

int Game::getMinAge() const
{
    return minAge;
}

double Game::getPrice() const
{
    return price;
}

void Game::print() const
{
    cout << fixed << setprecision(2);
    cout << setw(25) << left << "Name: " << getDescription() << endl;
    cout << setw(25) << "Minimum # of Players: " << getMinPlayers() << endl;
    cout << setw(25) << "Maximum # of Players: " << getMaxPlayers() << endl;
    cout << setw(25) << "Minimum Age: " << getMinAge() << endl;
    cout << setw(25) << "Price: " << getPrice() << endl << endl;
}
