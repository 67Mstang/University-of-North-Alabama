#include <iostream>
using namespace std;


int sumDigits(int num);


int main()
{
	int num = 0;

	cout << "Please enter and integer: ";
	cin >> num;

	cout << endl << "The sum of the digits of " << num << " is: " << sumDigits(num) << endl;

	return 0;
}





int sumDigits(int num)
{
	if (num == 0)
	{
        return 0;
	}

	return (num % 10 + sumDigits(num / 10));
}
