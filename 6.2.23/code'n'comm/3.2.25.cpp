#include <iostream>
#include <conio.h>

using namespace std;

void CreateArray(int ***arr, int n);
void OutputArray(int ***arr, int n);

int main()
{
	int n;
	cout << "Enter the size of cube (n): " << endl;
	cin >> n;
	int ***arr = new int**[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int*[n];

		for(int j = 0; j < n; j++)
		{
			arr[i][j] = new int[n];
		}
	}
	CreateArray(arr, n);
	OutputArray(arr, n);
	for (int i = 0; i < n; i++)
	{
			for (int j = 0; j < n; j++)
		{
					delete [] arr[i][j];
			}
			delete [] arr[i];
	}
		delete [] arr;
	getch();
	return 0;
}

void CreateArray(int ***arr, int n)
{
	int i = 0, j = 0, k = 0, counter = 0, cube = 0;

	while (cube < (n * n))
		{
			if (j == n)
				{
					j = 0;
				}
			if (counter == n)
				{
					i = 0;
					counter = 0;
					k++;
					j = k;
				}
			arr[i][j][k] = 1;
			i++;
			j++;
			counter++;
			cube++;
		}
}

void OutputArray(int ***arr, int n)
 {
		 for (int i = 0; i < n; i++)
			{
				cout << "Layer " << i + 1 << ":";
				for (int j = 0; j < n; j++)
				{
					cout <<  endl;
					for (int k = 0; k < n; k++)
					cout << arr[i][j][k];
				}
				cout << endl << endl;
			}
 }
