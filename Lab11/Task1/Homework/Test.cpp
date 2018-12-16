#include "Test.hpp"
#include "KMPalgorithm.hpp"
#include "ReadFile.hpp"
#include <iostream>
#include <vector>

using namespace std;

void errTemplateKMP(string &error, string text, string pattern, string func, int expected, int found)
{
	error += "\nText: " + text;
	error += "\nPattern: " + pattern;
	error += "\nExpeced answer: ";
	error += to_string(expected);
	error += "\nGot answer: ";
	error += to_string(found);
}

bool test(vector <string> &result)
{
	bool res = true;

	ifstream input("testinput.txt", ios::in);

	if (!input.is_open())
	{
		res = false;
		result.push_back("Cannot open testinput.txt file!");
		return res;
	}

	string testText1 = readFromFile(input);

	input.close();

	if (!testText1.compare("TEstIng the AlgoRiThm ! The KMP is being tested !!!!!"))
	{
		res = false;
		result.push_back("Error in readFromFile()! - Wrong string");
		return res;
	}

	string testText2 = "Hello , world!";
	string testText3 = "How are you?";

	// Testing text from file
	if (firstPatternMatchKMP(testText1, "KEK") != -1)
	{
		res = false;
		string error = string();
		errTemplateKMP(error, testText1, "KEK", "firstPatternMatchKMP()", -1, firstPatternMatchKMP(testText1, "KEK"));
		result.push_back(error);
	}
	if (firstPatternMatchKMP(testText1, "Al") != 12)
	{
		res = false;
		string error = string();
		errTemplateKMP(error, testText1, "Al", "firstPatternMatchKMP()", 12, firstPatternMatchKMP(testText1, "Al"));
		result.push_back(error);
	}
	// Testing "Hello , world!"
	if (firstPatternMatchKMP(testText2, "worlddd") != -1)
	{
		res = false;
		string error = string();
		errTemplateKMP(error, testText2, "worlddd", "firstPatternMatchKMP()", -1, firstPatternMatchKMP(testText2, "worlddd"));
		result.push_back(error);
	}
	if (firstPatternMatchKMP(testText2, "llo") != 2)
	{
		res = false;
		string error = string();
		errTemplateKMP(error, testText2, "llo", "firstPatternMatchKMP()", 2, firstPatternMatchKMP(testText2, "llo"));
		result.push_back(error);
	}
	// Testing "How are you?"
	if (firstPatternMatchKMP(testText3, "ADDo") != -1)
	{
		res = false;
		string error = string();
		errTemplateKMP(error, testText3, "ADDo", "firstPatternMatchKMP()", -1, firstPatternMatchKMP(testText3, "ADDo"));
		result.push_back(error);
	}
	if (firstPatternMatchKMP(testText3, "are") != 4)
	{
		res = false;
		string error = string();
		errTemplateKMP(error, testText3, "are", "firstPatternMatchKMP()", 4, firstPatternMatchKMP(testText3, "are"));
		result.push_back(error);
	}

	return res;
}