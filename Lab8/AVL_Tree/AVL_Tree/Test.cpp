#include "Test.hpp"
#include "AVL_Tree.hpp"

using namespace std;

void fillTree(Node *&root)
{
	root = add(root, 10, "Ten");
	root = add(root, 9, "Nine");
	root = add(root, 8, "Eight");
	root = add(root, 7, "Seven");
	root = add(root, 6, "Six");
	root = add(root, 5, "Five");
	root = add(root, 4, "Four");
	root = add(root, 3, "Three");
	root = add(root, 2, "Second");
	root = add(root, 1, "One");
	root = add(root, 0, "Zero");
}

bool testStructure(Node *root)
{
	if (getKey(root) == 7)
	{
		Node *left = getLeft(root);
		Node *right = getRight(root);

		if (getKey(left) == 3 && getKey(right) == 9)
		{
			if (getKey(getLeft(right)) == 8 && getKey(getRight(right)) == 10)
			{
				right = getRight(left);
				left = getLeft(left);

				if (getKey(left) == 1 && getKey(right) == 5)
				{
					if (getKey(getLeft(left)) == 0 && getKey(getRight(left)) == 2)
					{
						if (getKey(getLeft(right)) == 4 && getKey(getRight(right)) == 6)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool test(vector<string>& result)
{
	bool res = true;
	Node *testRoot = createNode();
	fillTree(testRoot);

	if (!testStructure(testRoot))
	{
		result.push_back("Error in add()!");
		res = false;
	}

	testRoot = remove(testRoot, -666);

	if (!testStructure(testRoot))
	{
		result.push_back("Error in remove()! Test: removing key that doesn't exist.");
		res = false;
	}

	if (!exists(testRoot, 5))
	{
		result.push_back("Error in exists()! Test: looking for key that exists.");
		res = false;
	}

	if (exists(testRoot, -666))
	{
		result.push_back("Error in exists()! Test: looking for key that doesn't exist.");
		res = false;
	}

	testRoot = add(testRoot, 10, "TEN");

	if (getValue(getRight(getRight(testRoot))) != "TEN")
	{
		result.push_back("Error in add()! Test: changing value of node which exists.");
		res = false;
	}

	return res;
}