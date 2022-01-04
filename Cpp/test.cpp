#include <iostream>
using namespace std;

int bin[] = {0, 0, 0, 0, 0};

int getNum()
{
	int num;

	cout << "Enter a number between 0 and 31: " << endl;

	cin >> num;

	if (num > 31)
	{

		cout << num << " is > than 31" << endl;

		getNum();
	}
	else if (num < 0)
	{

		cout << num << " is < than 0" << endl;

		getNum();
	}
	else
	{
		return num;
	}
}

int decToBin(int num)
{

	for (int i = 0; i < 6; i++)
	{

		if (num % 2 == 0)
		{

			bin[i] = 0;
		}
		else
		{

			bin[i] = 1;
		}

		num = num / 2;
	}

	return 0;
}

int main()
{
	int input = getNum();

	decToBin(input);

	cout << input << " in bin = ";

	for (int i = 0; i <= 5; i++)
	{
		cout << bin[5 - i];
	}

	int exit;

	while (exit != 1)
	{

		cout << endl
			 << "press 1 to exit" << endl;

		cin >> exit;
	}

	return 0;
}