#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Assignment6.h"
using namespace std;

istream &operator >> (istream &stream, Game &object)
{
    string tempName = "NULL";
    int tempMin = 0;
    int tempMax = 0;
    int tempAge = 0;
    double tempPrice = 0.0;

    stream >> ws;
    getline(stream, tempName);
    object.setDescription(tempName);

    stream >> tempMin;
    stream >> tempMax;
    stream >> tempAge;
    stream >> tempPrice;

    object.setMinPlayers(tempMin);
    object.setMaxPlayers(tempMax);
    object.setMinAge(tempAge);
    object.setPrice(tempPrice);

    return stream;
}

ostream &operator << (ostream &stream, const Game &object)
{
    stream << fixed << setprecision(2)
           << setw(25) << left << "Name: " << object.getDescription() << endl
           << setw(25) << "Minimum # of Players: " << object.getMinPlayers() << endl
           << setw(25) << "Maximum # of Players: " << object.getMaxPlayers() << endl
           << setw(25) << "Minimum Age: " << object.getMinAge() << endl
           << setw(25) << "Price: " << object.getPrice() << endl << endl;

    return stream;
}

Game Game::operator + (const Game &right)
{
    Game temp;

    temp.description = (description + " - " + right.description);
    temp.minPlayers = (minPlayers + right.minPlayers) / 2;
    temp.maxPlayers = (maxPlayers + right.maxPlayers) / 2;
    temp.minAge = (minAge + right.minAge) / 2;
    temp.price = (price + right.price) / 2;

    return temp;
}

bool Game::operator == (const Game &right)
{
    bool status = false;

    if(description == right.description)
    {
        status = true;
    }

    return status;
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
    cout << " ";
    //cout << "BoardGame is destroyed" << endl;
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
