#include <conio.h>
#include <fstream>
#include <iostream>

using namespace std;

int* readFromFile()
{
	int *result = new int[101];
	ifstream inf("ololo.txt");
	int input = 0;
	int i = 0, j = 0;
	while (!inf.eof())
	{
		inf >> input;
		if (input != ' ')
		{
			result[i] = input;
			cout << input;
			++j;
		}
		++i;
	}
	result[101] = j;
	return result;
}

void writeToFile(int *data, int length)
{
	ofstream of("ololo.txt");
	int *buffer = new int[length + 1];
	int j = length - 1;
	for (int i = 0; i < length; ++i)
	{
		//of << data[i] << ' ';
		buffer[j] = data[i];
		j--;
	}
	for (int i = 0; i < length; ++i)
	{
		of << buffer[i] << ' ';
	}
	//вылетаю за границы вроде, не успел исправить
}

int main()
{
	int *data = readFromFile();
	writeToFile(data, data[101]);
	delete[] data;
	system("PAUSE");
	return 0;
}
