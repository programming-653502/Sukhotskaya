#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 81
#define FIRST_NUMBER "987654321987654321"
#define SECOND_NUMBER "123456789123456789"

using namespace std;

typedef struct item
{
	int digit;
	struct item *next;
	struct item *prev;
} Item;

typedef struct mnumber
{
	Item *head;
	Item *tail;
	int n;
} MNumber;

MNumber CreateMNumber(char *initStr);
void AddDigit(MNumber *number, int digit);
void PrintMNumber(MNumber number);
MNumber LongSumLong(MNumber n1, MNumber n2);
MNumber LongSubLong(MNumber n1, MNumber n2);

int main()
{
	char FirstNumber[MAX_LENGTH];
	char SecondNumber[MAX_LENGTH];
	MNumber a = CreateMNumber(FIRST_NUMBER);
	MNumber b = CreateMNumber(SECOND_NUMBER);
	cout << FIRST_NUMBER << "\n" << SECOND_NUMBER << "\n";
	cout << "The sum is: ";
	LongSumLong(a, b);
	cout << endl;
	cout << "The subtraction is: ";
	LongSubLong(a, b);
	cout << endl;
	getch();
	return 0;
}

MNumber CreateMNumber(char initStr[])
{
	MNumber number = {NULL, NULL, 0};
	int n;

	for(n = strlen(initStr) - 1; n >= 0; n--)
	{
		AddDigit(&number, initStr[n] - '0');
	}
	return number;
}

void AddDigit(MNumber *number, int digit)
{
	Item *p = (Item *)malloc(sizeof(Item));
	p->digit = digit;
	p->next = p->prev = NULL;
	if (number->head == NULL)
		number->head = number->tail = p;
	else
	{
		number->tail->next = p;
		p->prev = number->tail;
		number->tail = p;
	}

	number->n++;
}

MNumber LongSumLong(MNumber n1, MNumber n2)
{
	MNumber sum = CreateMNumber("");
	Item *p1 = n1.head, *p2 = n2.head;
	int digit, pos = 0, s1, s2;

	while (p1 || p2)
	{
		if (p1)
		{
			s1 = p1->digit; p1 = p1->next;
		}
		else s1 = 0;
		if (p2)
		{
			s2 = p2->digit; p2 = p2->next;
		}
		else s2 = 0;
		digit = (s1 + s2 + pos) % 10;
		pos = (s1 + s2 + pos) / 10;
		AddDigit(&sum, digit);
	}
	if (pos)
	{
		AddDigit(&sum, pos);
	}
	PrintMNumber(sum);
}

MNumber LongSubLong(MNumber n1, MNumber n2)
{
	MNumber dif = CreateMNumber("");
	Item *p1 = n1.head, *p2 = n2.head;
	int digit, pos = 0, s1, s2;

	while (p1 || p2)
	{
		if (p1)
		{
			s1 = p1->digit; p1 = p1->next;
		}
		else s1 = 0;
		if (p2)
		{
			s2 = p2->digit; p2 = p2->next;
		}
		else s2 = 0;

		if (s1 >= s2)
		{
			if ((s1 - s2 + pos) >= 0)
			{
				digit = s1 - s2 + pos;
				pos = 0;
			}

			else
			{
				digit = (s1 + 10) - s2 + pos;
				pos = -1;
			}
		}

		else
		{
			digit = (s1 + 10) - s2 + pos;
			pos = -1;
		}

		AddDigit(&dif, digit);
	}
	if (pos)
	{
		AddDigit(&dif, pos);
	}
	PrintMNumber(dif);
}

void PrintMNumber(MNumber number)
{
	Item *p = number.tail;
	while(p)
	{
		printf ("%d", p->digit);
		p = p->prev;
	}
}
