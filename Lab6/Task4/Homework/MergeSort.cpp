#include "MergeSort.hpp"
#include "List.hpp"

List* merge(List *list, bool sortBy)
{
	List *res = createList();

	List *left = firstHalf(list);
	List *right = secondHalf(list);

	char name[20];
	char phone[20];

	while (left != nullptr)
	{
		if (sortBy == 0) // name
		{
			Contact *contact = priotityNameContact(head(left), head(right));
			Node *node = createNode(*contact);
			add(res, node);

			if (!strcmp(contact->name, headContact(left)->phone))
			{
				extractHead(left);
			}
			else
			{
				extractHead(right);
			}
		}
		else // phone
		{
			Contact *contact = priotityPhoneContact(head(left), head(right));
			Node *node = createNode(*contact);
			add(res, node);
			
			if (!strcmp(contact->name, headContact(left)->name))
			{
				extractHead(left);
			}
			else
			{
				extractHead(right);
			}
		}
	}

	if (getLength(right) != 0)
	{
		Contact *contact = headContact(right);
		Node *node = createNode(*contact);
		add(res, node);
	}

	delete[] name;
	delete[] phone;
	deleteList(left);
	deleteList(right);

	return res;
}

void mergeSort(List *list, bool sortBy)
{
	int length = getLength(list);

		mergeSort(firstHalf(list), sortBy);
		mergeSort(secondHalf(list), sortBy);

	list = merge(list, sortBy);
}
