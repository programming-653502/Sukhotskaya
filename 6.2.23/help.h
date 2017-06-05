#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void showFile(ifstream& fileStream)
{
	while (!fileStream.eof())
	{
		string buffer;
		getline(fileStream, buffer);
		cout << buffer << endl;
	}
}

void showArticle(string& article)
{
	string name = "articles/" + article + ".txt";
	ifstream artStream(name.c_str());
	if (artStream.is_open())
	{
		while (!artStream.eof())
		{
			string buffer;
			getline(artStream, buffer);
			cout << buffer << endl;
		}
		artStream.close();
	}
}

void showVecStr(vector<string>& vec_str)
{
	for (unsigned i = 0; i < vec_str.size(); ++i)
	{
		cout << "¹" << i + 1 << ": " << vec_str[i] << endl;
	}
}

bool is_number(string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int correctInput(string message, int minValue, int maxValue)
{
	string result;
	int res;
	bool isSuccess = false;
	do
	{
		try
		{
			cout << message;
			getline(cin, result);
			if (is_number(result))
			{
				res = atoi(result.c_str());
				if (res < minValue || res > maxValue)
					throw 99;
				else isSuccess = true;
			}
			else throw 99;
		}
		catch (...)
		{
			cout << "Incorrect input. Try again" << endl;
		}
	} while (!isSuccess);
	return res;
}
