#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "help.h"

struct SOURCE
{
	string instName;
	string language;
	string topic;
	string date;
	vector <string> articles;
	vector <string> comments;
	bool isChanged;

	SOURCE(string name)
	{
		instName = name;
		isChanged = false;
	}
	void setLangThemeDate(string language, string topic, string date)
	{
		this->language = language;
		this->topic = topic;
		this->date = date;
	}
};

struct LINKS
{
	string linkName;
	vector<string> linkFiles;

	LINKS(string name, string file)
	{
		linkName = name;
		linkFiles.push_back(file);
	}
};

void loadDatabase(vector<SOURCE>& fileNames,
	vector<LINKS>& languages,
	vector<LINKS>& topics)
{
	ifstream database("code'n'comm/source_base.txt");
	if (database.is_open())
	{
		while (!database.eof())
		{
			string tempFileName;
			database >> tempFileName;
			fileNames.push_back(SOURCE(tempFileName));

			string commentFileName = string("code'n'comm/" +
				tempFileName.substr(0, tempFileName.find_last_of('.')) + "_comm.txt");
			ifstream commentFile(commentFileName.c_str(), ios::app);

			if (commentFile.peek() == ifstream::traits_type::eof())
			{
				commentFile.close();
				ofstream addCommentFile(commentFileName.c_str());
				std::cout << "File: " << tempFileName << endl;

				string buffer;
				std::cout << "Enter language: ";
				std::getline(cin, buffer);
				addCommentFile << "language: " << buffer << endl;
				buffer.clear();

				std::cout << "Enter topic: ";
				std::getline(cin, buffer);
				addCommentFile << "topic: " << buffer << endl;
				buffer.clear();

				std::cout << "Enter date: ";
				std::getline(cin, buffer);
				addCommentFile << "date: " << buffer << endl;
				buffer.clear();

				addCommentFile << "articles:\ncomments: \n\n";
				addCommentFile.close();

				commentFile.open(commentFileName.c_str(), ios::app);
			}

			string buffer;
			std::getline(commentFile, buffer);
			string language = buffer.substr(6, buffer.size() - 1);
			if (!languages.size())
				languages.push_back(LINKS(language, tempFileName));
			else
			{
				for (unsigned i = 0; i < languages.size(); ++i)
				{
					if (!languages[i].linkName.compare(language))
					{
						languages[i].linkFiles.push_back(tempFileName);
						break;
					}
					else if (i == languages.size() - 1)
					{
						languages.push_back(LINKS(language, tempFileName));
						break;
					}
				}
			}
			buffer.clear();

			std::getline(commentFile, buffer);
			string topic = buffer.substr(7, buffer.size() - 1);
			if (!topics.size())
				topics.push_back(LINKS(topic, tempFileName));
			else
			{
				for (unsigned i = 0; i < topics.size(); ++i)
				{
					if (!(topics[i].linkName.compare(topic)))
					{
						topics[i].linkFiles.push_back(tempFileName);
						break;
					}
					else if (i == topics.size() - 1)
					{
						topics.push_back(LINKS(topic, tempFileName));
						break;
					}
				}
			}

			buffer.clear();
			std::getline(commentFile, buffer);
			string date = buffer.substr(6, buffer.size() - 1);
			buffer.clear();

			fileNames[fileNames.size() - 1].setLangThemeDate(language, topic, date);

			std::getline(commentFile, buffer);
			buffer.clear();

			std::getline(commentFile, buffer);
			if (buffer[0] == '-')
			{
				do
				{
					buffer.erase(buffer.begin());
					if (!buffer.empty())
						fileNames[fileNames.size() - 1].articles.push_back(buffer);
					buffer.clear();
					getline(commentFile, buffer);
				} while (buffer[0] != 'c');
			}

			buffer.clear();
			while (commentFile.peek() != ifstream::traits_type::eof())
			{
				getline(commentFile, buffer);
				fileNames[fileNames.size() - 1].comments.push_back(buffer);
				buffer.clear();
			}

			commentFile.close();
		}

		database.close();
	}

	else
		cout << "Database isn't opened" << endl;
}

bool commentMenu(SOURCE & filename)
{
	std::cout << "Comment editing menu: " << endl;
	std::cout << "1) Add comment" << endl;
	std::cout << "2) Edit comment" << endl;
	std::cout << "3) Delete comment" << endl;
	std::cout << "4) Back to menu " << endl;
	int choice = correctInput("Your choice: ", 1, 4);
	switch (choice)
	{
	case 1:
	{
		std::cout << "Enter your comment: " << endl;
		string newComment;
		std::getline(cin, newComment);
		filename.comments.push_back(newComment);
		filename.isChanged = true;
	}
	break;
	case 2:
	{
		int commentIndex = correctInput("Comment ¹ ", 1, filename.comments.size()) - 1;
		string newComment;
		std::getline(cin, newComment);
		filename.comments[commentIndex].clear();
		filename.comments[commentIndex] = newComment;
		filename.isChanged = true;
	}
	break;
	case 3:
	{
		int commentIndex = correctInput("Comment ¹ ", 1, filename.comments.size()) - 1;
		filename.comments.erase(filename.comments.begin() + commentIndex);
		filename.isChanged = true;
	}
	break;
	case 4:
		return true;
		break;
	}
	return false;
}

void openFile(SOURCE& fileName)
{
	string choosenFileName = "code'n'comm/" + fileName.instName;
	ifstream choosenFile(choosenFileName.c_str());
	bool isReturn = false;
	if (choosenFile.is_open())
	{
		while (!isReturn)
		{
			std::cout << string(70, '¹') << "\n\n";
			showFile(choosenFile);
			std::cout << string(70, '¹') << "\n";
			std::cout << "Language: " << fileName.language << endl;
			std::cout << "Topic: " << fileName.topic << endl;
			std::cout << "Date: " << fileName.date << endl << endl;

			if (fileName.articles.size())
			{
				std::cout << "Articles: " << endl;
				showVecStr(fileName.articles);
				std::cout << endl;
			}
			else
				std::cout << "No related articles" << endl << endl;

			if (fileName.comments.size())
			{
				std::cout << "Comments: " << endl;
				showVecStr(fileName.comments);
				std::cout << endl;
			}
			else
				std::cout << "No related comments" << endl << endl;

			isReturn = commentMenu(fileName);
			choosenFile.close();
			choosenFile.open(choosenFileName.c_str());
		}
		choosenFile.close();
		std::cout << string(70, '¹') << "\n\n";
	}
	else
		std::cout << "Error" << endl;
}

void openFile(vector<SOURCE>& fileNames, string fileName)
{
	int index = 0;
	while (fileNames[index].instName.compare(fileName)) { index++; };
	openFile(fileNames[index]);
}

void loadArticles(vector<string>& articleNames)
{
	ifstream artbase("articles/article_base.txt");
	if (artbase.is_open())
	{
		while (!artbase.eof())
		{
			string buffer;
			std::getline(artbase, buffer);
			articleNames.push_back(buffer.substr(0, buffer.size() - 4));
		}
		artbase.close();
	}
	else
		std::cout << "Article base not found" << endl;
}

void showLinks(vector<LINKS>& vec_link)
{
	for (unsigned i = 0; i < vec_link.size(); ++i)
	{
		std::cout << vec_link[i].linkName << endl;
		for (unsigned j = 0; j < vec_link[i].linkFiles.size(); ++j)
			cout << "\t" << vec_link[i].linkFiles[j] << endl;
		std::cout << endl;
	}
}

void chooseArticle(vector<string>& articleNames)
{
	showVecStr(articleNames);
	std::cout << "¹" << articleNames.size() + 1 << ": Return" << endl;
	unsigned choice = correctInput("Article ¹ ", 1, articleNames.size() + 1) - 1;
	if (choice != articleNames.size())
	{
		string fas = "articles/" + articleNames[choice] + ".txt";
		ifstream artStream(fas.c_str());
		if (artStream.is_open())
		{
			showFile(artStream);
			artStream.close();
		}
		else
			std::cout << "Article is not found" << endl;
	}
}

int chooseInLink(vector<LINKS>& link_vec, string linkName)
{
	std::cout << linkName << endl;
	for (unsigned i = 0; i < link_vec.size(); ++i)
		std::cout << i + 1 << " - " << link_vec[i].linkName << endl;

	return correctInput("Your choice: ", 1, link_vec.size()) - 1;
}

void saveBase(vector<SOURCE>& fileNames)
{
	for (unsigned i = 0; i < fileNames.size(); ++i)
	{
		if (fileNames[i].isChanged)
		{
			string commentFileName = string("code'n'comm/" +
				fileNames[i].instName.substr(0, fileNames[i].instName.find_last_of('.'))
				+ "_comm.txt");
			ofstream changedFile(commentFileName.c_str(), ios::trunc);
			if (changedFile.is_open())
			{
				changedFile << "language: " << fileNames[i].language << endl;
				changedFile << "topic: " << fileNames[i].topic << endl;
				changedFile << "date: " << fileNames[i].date << endl;
				changedFile << "articles: " << endl;
				for (unsigned j = 0; j < fileNames[i].articles.size(); ++j)
					changedFile << "-" << fileNames[i].articles[j] << endl;
				changedFile << "comments: " << endl;
				for (unsigned j = 0; j < fileNames[i].comments.size(); ++j)
					changedFile << fileNames[i].comments[j] << endl;

				changedFile.close();
			}
			else
				std::cout << "Error" << endl;
		}
	}
}