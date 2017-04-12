#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

int count = 0;

int main()
{
	std::fstream file("C:\\Users\\Анастасия\\Desktop\\code.txt", std::ios::in);

	if (file.fail())
	{
		std::cout << "File does not exist!";
	}
	else
	{
		file.seekg(0, std::ios::end);
		int length = file.tellg();
		file.seekg(0, std::ios::beg);

		char* buffer = new char[length];
		file.read(buffer, length);/*length - размер файла + 2 невидимых
для нас символа окончания каждой строки (\ и n)*/

		for (int i = 1; i <= length; i++)
		{
			if (buffer[i - 1] == '/' && buffer[i] == '/')
			{
				while (buffer[i] != '\n')
				{
					count++;
					i++;
				}
				count += 1;
			}/*так как в условии не сказано конкретно, считать ли символы,
обозначающие начало либо завершение комментария, частью самого комментария,
я позволила себе предположить, что эти символы стоит включить в него*/
			else if (buffer[i - 1] == '/' && buffer[i] == '*')
			{
				while (!(buffer[i - 1] == '*' && buffer[i] == '/'))
				{
					if (buffer[i] == '\n')
					{
						count += 2;
					}
					else
					{
						count++;
					}
					i++;
				}
				count += 2;
			}
		}
		std::cout << "Commented code percentage: " << (double)count/(double)length * 100;
		delete[] buffer;
	}

	file.close();
	getch();
	return 0;
}

