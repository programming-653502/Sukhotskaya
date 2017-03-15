#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <limits>

using namespace std;

void input();
void output();
void norm();
void diff();
void integrate();
void value();
void info();

double arr[4];

int main()
{
	int choise;
	do
	{
		cout <<  "Choose the action:\n"
		<<  "1. Input polinomial.\n"
		<<  "2. Show polinomial.\n"
		<<  "3. Normalize polinomial.\n"
		<<  "4. Differentiate polinomial.\n"
		<<  "5. Integrate polinomial.\n"
		<<  "6. Calculate the value of a polynomial.\n"
		<<  "7. Get information about the program.\n"
		<<  "0. Exit.\n";
		cin >> choise;
		switch (choise)
		{
			case 1:
				input();
				break;
			case 2:
				output();
				break;
			case 3:
				norm();
				break;
			case 4:
				diff();
				break;
			case 5:
				integrate();
				break;
			case 6:
				value();
				break;
			case 7:
				info();
				break;
			case 0:
				return 0;
				break;
			default:
				break;
		}
	}
	while (choise != 0);
	getch();
	return 0;
}

void input()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter the " << i + 1 << " coefficient of a polynomial (before x^" << 3 - i << "):" << endl;
		cin >> arr[i];
	}
}

void output()
{
	if (arr[0] != 0)
	{
		cout << arr[0] << "x^3";
		for (int i = 1; i < 4; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << arr[i] << "x^" << 3 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << arr[i] << "x^" << 3 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] != 0)
	{
		cout << arr[1] << "x^2";
		for (int i = 2; i < 4; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << arr[i] << "x^" << 3 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << arr[i] << "x^" << 3 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] == 0)
	{
		if (arr[2] != 0)
		cout << arr[2] << "x" << arr[3] << endl;
		else cout << "Polynomial doesn't exist" << endl;
	}
}

void norm()
{
	if (arr[0] != 0)
	{
		cout << arr[0]/arr[0] << "x^3";
		for (int i = 1; i < 4; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << arr[i]/arr[0] << "x^" << 3 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << arr[i]/arr[0] << "x^" << 3 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] != 0)
	{
		cout << arr[1]/arr[1] << "x^2";
		for (int i = 2; i < 4; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << arr[i]/arr[1] << "x^" << 3 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << arr[i]/arr[1] << "x^" << 3 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] == 0)
	{
		if (arr[2] != 0)
		cout << arr[2]/arr[2] << "x" << arr[3]/arr[2] << endl;
		else cout << "Polynomial doesn't exist" << endl;
	}
}

void diff()
{
	if (arr[0] != 0)
	{
		cout << 3 * arr[0] << "x^2";
		for (int i = 1; i < 3; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << (3 - i) * arr[i] << "x^" << 2 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << (3 - i) * arr[i] << "x^" << 2 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] != 0)
	{
		cout << 2 * arr[1] << "x^1";
		for (int i = 2; i < 3; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << (3 - i) * arr[i] << "x^" << 2 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << (3 - i) * arr[i] << "x^" << 2 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] == 0)
	{
		if (arr[2] != 0)
		cout << arr[2] << endl;
		else cout << "Polynomial doesn't exist" << endl;
	}
}

void integrate()
{
	if (arr[0] != 0)
	{
		cout << arr[0]/4 << "x^4";
		for (int i = 1; i < 4; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << arr[i]/(4 - i) << "x^" << 4 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << arr[i]/(4 - i) << "x^" << 4 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] != 0)
	{
		cout << arr[1]/3 << "x^3";
		for (int i = 2; i < 4; i++)
		{
			if (arr[i] > 0)
			{
				cout << " + " << arr[i]/(4 - i) << "x^" << 4 - i;
			}
			else if (arr[i] < 0)
			{
				cout << " " << arr[i]/(4 - i) << "x^" << 4 - i;
			}
		}
		cout << endl;
	}
	else if (arr[0] == 0 && arr[1] == 0)
	{
		if (arr[2] != 0)
		cout << arr[2]/2 << " x^2" << arr[3] << "x^1" << endl;
		else cout << "Polynomial doesn't exist" << endl;
	}
}

void value()
{
		double x, val = 0;
		cout << "Enter the value of x: " << endl;
		cin >> x;
		for (int i = 0; i < 4; i++)
		{
			val += arr[i] * powl(x, (3 - i));
		}
		cout << val << endl;
}

void info()
{
	cout << "Polynomial of the third degree. Version 1.0." << endl;
	cout << "Created by Anastasiya Suknotskaya." << endl;
}
