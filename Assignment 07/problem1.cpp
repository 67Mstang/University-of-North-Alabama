#include <iostream>
#include <string>
using namespace std;



bool isVowel(char ch);
int countVowels(string str, int n);





int main()
{
	string myString = "";

	cout << "Please enter a string and I will count the number of vowels." << endl;
	getline(cin, myString);

	cout << endl << "There are: " << countVowels(myString, myString.length())
	     << " vowel(s) in the string that you entered." << endl;

	return 0;
}



bool isVowel(char ch)
{
    ch = toupper(ch);

    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}



int countVowels(string str, int n)
{
	if (n == 1)
		return isVowel(str[n-1]);

	return countVowels(str, n-1) + isVowel(str[n-1]);
}
