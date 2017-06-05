#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "database.h"

void changeMenu(vector<SOURCE>& fileNames, vector<string>& articleNames, vector<LINKS>& languages, vector<LINKS>& topics)
{
	std::cout << "1) Show source code in some programming language" << endl;
	std::cout << "2) Show source code of some topic" << endl;
	std::cout << "3) Show all existing sources" << endl;
	std::cout << "4) Back to Main Menu" << endl;
	int choice = correctInput("Your choice: ", 1, 4);
	switch (choice)
	{
	case 1:
	{
		int index1 = chooseInLink(languages, "Choose programming language: ");
		showVecStr(languages[index1].linkFiles);
		int index2 = correctInput("Your choice: ", 1, languages[index1].linkFiles.size()) - 1;
		openFile(fileNames, languages[index1].linkFiles[index2]);
	}
	break;
	case 2:
	{
		int index1 = chooseInLink(topics, "Choose topic: ");
		showVecStr(topics[index1].linkFiles);
		int index2 = correctInput("Your choice: ", 1, topics[index1].linkFiles.size()) - 1;
		openFile(fileNames, topics[index1].linkFiles[index2]);
	}
	break;
	case 3:
	{
		cout << "Choose programms' code file: " << endl;
		for (unsigned i = 0; i < fileNames.size(); ++i)
			cout << i + 1 << " - " << fileNames[i].instName << endl;
		int index = correctInput("Your choice: ", 1, fileNames.size());
		openFile(fileNames[index]);
	}
	break;
	case 4:
		break;
	}
}

void showMenu(vector<SOURCE>& fileNames, vector<string>& articleNames, vector<LINKS>& languages, vector<LINKS>& topics)
{
	bool isExit = false;
	do
	{
		cout << "          Main Menu         " << endl;
		cout << "1) Choose programms' code file" << endl;
		cout << "2) Choose article" << endl;
		cout << "3) Exit" << endl;
		int choice = correctInput("Your choice: ", 1, 3);
		switch (choice)
		{
		case 1:
			changeMenu(fileNames, articleNames, languages, topics);
			break;
		case 2:
			chooseArticle(articleNames);
			break;
		case 3:
			isExit = true;
			break;
		}
	} while (!isExit);
}


int main()
{
	vector<SOURCE> fileNames;
	vector<string> articleNames;
	vector<LINKS> languages, topics;

	loadDatabase(fileNames, languages, topics);
	loadArticles(articleNames);

	showMenu(fileNames, articleNames, languages, topics);
	saveBase(fileNames);
	return 0;
}