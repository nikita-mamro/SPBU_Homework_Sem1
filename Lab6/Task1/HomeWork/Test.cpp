#include "Test.hpp"

using namespace std;

bool success()
{
	cout << "Passed test!" << endl;
	return true;
}

bool failure(int wrongAnswer, int correctAnswer)
{
	printf("Counted answer: %d\nExpected answer: %d\nFailed test!", wrongAnswer, correctAnswer);
	return false;
}

bool test(const string & input, int correctAnswer)
{
	int result = proceedTask(input);
	return result == correctAnswer ? success() : failure(result, correctAnswer);
}

bool runTests()
{
	string test1 = "4 6 3 - * 8 6 - 2 / +";
	int answer1 = 13;
	string test2 = "9 6 - 1 2 + * ";
	int answer2 = 9;
	return test(test1, answer1) && test(test2, answer2);
}