#include "KMPalgorithm.hpp"

int *prefixFunction(const string & str)
{
	int *res = new int[str.size()]{ 0 };

	for (unsigned int i = 1, k = 0; i < str.size(); ++i)
	{
		while (k > 0 && str[k] != str[i])
		{
			k = res[k - 1];
		}
		if (str[k] == str[i])
		{
			++k;
		}
		res[i] = k;
	}

	return res;
}

int firstPatternMatchKMP(const string & text, const string & pattern)
{
	if (pattern.empty())
	{
		return 0;
	}

	int *prefixFunc = prefixFunction(pattern);

	for (unsigned int i = 0, k = 0; i < text.size(); ++i)
	{
		while (k && pattern[k] != text[i])
		{
			k = prefixFunc[k - 1];
		}
		if (pattern[k] == text[i])
		{
			++k;
		}
		if (k == pattern.size())
		{
			delete[] prefixFunc;
			return i - k + 1;
		}
	}

	delete[] prefixFunc;

	return -1;
}