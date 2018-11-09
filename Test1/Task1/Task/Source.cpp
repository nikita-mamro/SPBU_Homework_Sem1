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
	string testStr1 = "� ��� � ����� �����";
	string testStr2 = "� � ��� � ���� � ������ �����";
	string testStr3 = "������";
	string testStr4 = "� ��� � ����� �����";

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
		cout << "����� ��������!" << endl;
	}
	else
	{
		cout << "�����  �� ��������!" << endl;
	}

	string str;

	cout << "������� ������ :" << endl << endl;
	getline(cin, str);
	
	if (isPalindrome(str))
	{
		cout << "������ --- ���������!" << endl;
	}
	else
	{
		cout << "������ --- �� ���������!" << endl;
	}

	return 0;
}