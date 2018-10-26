#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
//   В некоторых языках 
//   программирования однострочные комментарии задаются не 
//   //, как в С++, а символом ";" 
//   (комментарий начинается с ; и заканчивается концом строки). 
//   Задача - вывести на консоль все комментарии такого вида 
//   из входного файла (вместе с символом ";"). До комментария в строке 
//   может быть значимый 
//   текст, его выводить не надо. Пустые строки выводить не надо.

int main()
{
	ifstream file("ololo.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found!" << endl;
		return 1;
	}

	vector<string> data;

	while (!file.eof()) {
		string buffer;
		file >> buffer;
		data.push_back(buffer);
	}

	file.close();

	for (string const &line : data)
	{
		int length = line.length();
		int i = 0;
		while (line[i] != ';' && i < length - 1)
		{
			++i;
		}
		if (i < length - 1)
		{
			for (int j = i; i < length - 1; ++j)
			{
				cout << line[j];
			}
			cout << endl;
		}
	}

	return 0;
}