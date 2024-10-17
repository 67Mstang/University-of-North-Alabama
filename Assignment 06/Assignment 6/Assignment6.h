#include <iostream>
using namespace std;

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

        Game operator + (const Game &);
        bool operator == (const Game &);
        friend ostream &operator << (ostream &, const Game &);
        friend istream &operator >> (istream &, Game &);
};
