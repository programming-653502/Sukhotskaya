#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	char* buff = new char[256];
	char** LongestString = new char*[256];
	for(int i = 0; i < 256; i++)
		LongestString[i] = new char[100];
	char** LongestWord = new char*[50];
	for(int i = 0; i < 50; i++)
		LongestWord[i] = new char[30];
	char* MbLongestWord = new char[30];
	int StringLength = 0;
	int WordLength = 0;
	int numOfLW = 0;
	int numOfLS = 0;
	int numOfSentenses = 0;
	int NumOfWords = 0;
	int NumOfStrings = 0;
	cout << "Enter your text (press Enter twice to finish input): " << endl;
	gets(buff);

	while (strlen(buff) > 0)
	{
		for (int i = 0; i < strlen(buff); i++)
		{
			if (isspace(buff[i]) && !(isspace(buff[i+1])))
			{
				++NumOfWords;
			}

			if (buff[i] == '.' || buff[i] == '!' || buff[i] == '?' || buff[i] == '?!' || buff[i] == '...')
			{
				numOfSentenses++;
			}
		}
		if(strlen(buff) > StringLength)
		{
			numOfLS = 0;
			StringLength = strlen(buff);
			strcpy(LongestString[numOfLS], buff);
			numOfLS++;
		}

		else if(strlen(buff) == StringLength)
		{
			strcpy(LongestString[numOfLS], buff);
			numOfLS++;
		}

		for (int i = 0; i < 256 && buff[i]!='\0';)
		{
			int numletter = 0;
			while (isalpha(buff[i]))
			{
				MbLongestWord[numletter] = buff[i];
				numletter++;
				i++;
			}
			if(numletter > WordLength)
			{
				numOfLW = 0;
				WordLength = numletter;
				strcpy(LongestWord[numOfLW], MbLongestWord);
				numOfLW++;
			}
			else if(numletter == WordLength)
			{
				strcpy(LongestWord[numOfLW], MbLongestWord);
				numOfLW++;
			}

			while(!isalpha(buff[i]) && buff[i] != '\0')
			{
				i++;
			}
		}
		NumOfStrings++;
		gets(buff);
	}

	cout << "Number of words: " << NumOfWords + NumOfStrings << endl;
	cout << "Number of sentenses: " << numOfSentenses << endl;
	cout << "The longest word: ";
	for (int i = 0; i < numOfLW; i++)
	{
		cout << LongestWord[i] << endl;
	}

	cout << "The longest string: " ;
	for (int i = 0; i < numOfLS; i++)
	{
		cout << LongestString[i] << endl;
	}

	for(int i = 0; i < 256; i++)
	{
		delete [] LongestString[i];
	}

	for(int i = 0; i < 50; i++)
	{
		delete [] LongestWord[i];
	}

	delete [] buff;

	getch();
	return 0;
}
