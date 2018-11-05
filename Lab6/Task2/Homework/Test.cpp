#include "Test.hpp"

bool test()
{
	string testStrings[10];
	
	testStrings[0] = "asdfghjkl";
	testStrings[1] = "(((()))";
	testStrings[2] = "ttt(dwdw)aa(())cxs([])";
	testStrings[3] = "{[}]";
	testStrings[4] = "([{}])";
	testStrings[5] = "aaaa(aaaa[aaaa{aaaa]aaa}aaa)";
	testStrings[6] = "(((())))[[[[{{{{}}}}]]]]";
	testStrings[7] = "test[";
	testStrings[8] = "qwerty(qwerty[qwerty{qwerty}qwerty]qwerty)qq";
	testStrings[9] = "qwerty]";

	for (int i = 0; i < 10; ++i)
	{
		bool res = checkString(testStrings[i]);

		if (true == res && i % 2 == 1 || false == res && i % 2 == 0)
		{
			return false;
		}
	}

	return true;
}