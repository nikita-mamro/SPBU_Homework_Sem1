#include "Menu.hpp"
#include "AVL_Tree.hpp"
#include <iostream>

int main()
{
	Node *root = createNode();
	root = add(root, 5, "Five");
	root = add(root, 4, "Four");
	root = add(root, 3, "Three");
	return EXIT_SUCCESS;
}