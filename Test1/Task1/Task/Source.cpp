#include <iostream>
#include <string>
#include <cstring>
#include <locale.h>

using namespace std;

string deleteSpaces(string input)
{
	string res = "";
	int length = input.length();
	
	for (int i = 0; i < length; ++i)
	{
		if (input[i] != ' ')
		{
			res += input[i];
		}
	}

	return res;
}

bool isPalindrome(string input)
{
	string str = deleteSpaces(input);
	int length = str.length();

	for (int i = 0; i < length / 2; ++i)
	{
		if (str[i] != str[length - i - 1])
		{
			return false;
		}
	}

	return true;
}

bool test()
{
	string testStr1 = "я иду с мечем судия";
	string testStr2 = "и к вам и трем с смерти мавки";
	string testStr3 = "привет";
	string testStr4 = "Я иду с мечем судия";

	if (!isPalindrome(testStr1) || !isPalindrome(testStr2) || isPalindrome(testStr3) || isPalindrome(testStr4))
	{
		return false;
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (test())
	{
		cout << "Тесты пройдены!" << endl;
	}
	else
	{
		cout << "Тесты  не пройдены!" << endl;
	}

	string str;

	cout << "Введите строку :" << endl << endl;
	getline(cin, str);
	
	if (isPalindrome(str))
	{
		cout << "Строка --- палиндром!" << endl;
	}
	else
	{
		cout << "Строка --- НЕ палиндром!" << endl;
	}

	return 0;
}