/**********************************************************************************************************************
    Name: Jamie Jones
    Course-Section: CS255
    Assignment: Assignment 9 (writer)
    Date due: 03-013-2022
    Description: This program will create a .dat file with a list of random 4 digit id's, random 3 word team names,
                    and three random bowling scores for 10,000 teams.
***********************************************************************************************************************/




#include <iostream>
#include <fstream>
#include <ctime>
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




int main()
{
    fstream out;
    BowlType bowler;

    srand(time(0));

    char part1[5][10] = {"Crazy", "Funny", "Rocking", "Silly", "Wacky"};
    char part2[5][10] = {"Blue", "Green", "Pink", "Red", "White"};
    char part3[5][10] = {"Eagles", "Hens", "Ostriches", "Penguins", "Seagulls"};

    out.open("Bowling.dat", ios::binary | ios::out);

    for(int i = 0; i < NUMBER_OF_BOWLERS; i++)
    {
        bowler.bowlID = 1000 + rand() % 9000;
        sprintf(bowler.teamName, "%s %s %s", part1[rand() % 5], part2[rand() % 5], part3[rand() % 5]);
        bowler.game1 = 100 + rand() % 151;
        bowler.game2 = 100 + rand() % 151;
        bowler.game3 = 100 + rand() % 151;
        out.write(reinterpret_cast<char*> (&bowler), sizeof(bowler));
    }

    cout << "Bowler data was created successfully using Bowling.dat" << endl;

    out.close();

    return 0;
}
