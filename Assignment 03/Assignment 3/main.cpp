/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 3
    Date due: 01-24-2022
    Description: This program will create a class to store board games with members for name, minimum # of players,
                    maximum # of players, minimum age, and price.  Then use member functions to set and get each of
                    the members.  It will also include a member function for print that will print all of the data
                    for a given game.
***********************************************************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

class Game
{
    private:
        string description;
        int minPlayers, maxPlayers, minAge;
        double price;
    public:
        void setDescription(string);
        void setMinPlayers(int);
        void setMaxPlayers(int);
        void setMinAge(int);
        void setPrice(double);
        string getDescription() const;
        int getMinPlayers() const;
        int getMaxPlayers() const;
        int getMinAge() const;
        double getPrice() const;
        void print() const;
};

int main()
{
    Game board1, board2, board3;

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














