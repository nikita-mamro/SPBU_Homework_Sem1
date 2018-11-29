#include "AVL_Tree.hpp"

int main()
{
	Node *root = createNode();
	root = add(root, 5, "Five");
	root = add(root, 6, "Six");
	root = add(root, 7, "Seven");
	root = add(root, 9, "Nine");
	return EXIT_SUCCESS;
}