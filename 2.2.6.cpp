#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

long double factorial (int n);
double iteration (double x, int n);
double recursion (double x, int n);

int main()
{
	double x, value0, value1 = 0, value2 = 0, e;
	begin:
	int n = 0;
	cout << "Enter the value of x:" << endl;
	cin >> x;
	cout << "Enter the value of epsilone:" << endl;
	cin >> e;
	value0 = sin(x);
	for (int i = 1; i < 50; i++)
	{
		value1 = iteration(x, i);
		value2 = recursion(x, i);
		if (fabs(value2 - value0) < fabs(e))
		{
			n = i;
			break;
		}
	}
	if (fabs(value1) > 1 + e || fabs(value2) > 1 + e)
	{
		cout << "The value of factorial is too large to keep in memory. Try again." << endl;
		goto begin;
	}
	else
	{
		cout << "sin(x) = " << value0 << "\n" << "value in a row by recursion = " << value2 << endl;
		cout << "value in a row by iteration = " << value1 << endl;
		if (fabs(value2 - value0) < fabs(value1 - value0))
		{
			cout << "Iteration is more accure for this input." << endl;
		}
		else if (fabs(value2 - value0) > fabs(value1 - value0))
		{
			cout << "Recursion is more accure for this input." << endl;
		}
		else
		{
			cout << "Methods are equel for this input." << endl;
		}
		cout << "The accuracy is reached when n = " << n << endl;
	}
	getch();
	return 0;
}

double iteration (double x, int n)
{
	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += powl((-1), i - 1) * powl(x, 2 * i - 1) / factorial(2 * i - 1);
	}
	return result;
}

double recursion (double x, int n)
{
	if (n != 0)
		{
			double result = powl((-1), n - 1) * powl(x, 2 * n - 1) / factorial(2 * n - 1);
			return result + recursion(x, n - 1);
		}
	else return 0;
}

long double factorial(int n)
{
	long double result = 1;
	for (int i = 2; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
