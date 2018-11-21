#include "MergeSort.hpp"
#include "List.hpp"

void merge(List *list, bool sortBy)
{
	List *res = createList();

	List *left = firstHalf(list);
	List *right = secondHalf(list);

	while (head(left) != nullptr && head(right) != nullptr)
	{
		if (sortBy == 0) // name
		{
			Contact *contact = priotityNameContact(head(left), head(right));
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
		else // phone
		{
			Contact *contact = priotityPhoneContact(head(left), head(right));
			Node *node = createNode(*contact);
			add(res, node);
			
			if (!strcmp(contact->phone, headContact(left)->phone))
			{
				extractHead(left);
			}
			else
			{
				extractHead(right);
			}
		}
	}

	if (head(left) != nullptr)
	{
		appendList(res, left);
	}
	if (head(right) != nullptr)
	{
		appendList(res, right);
	}

	while (head(list) != nullptr)
	{
		extractHead(list);
	}

	appendList(list, res);
}

void mergeSort(List *list, bool sortBy)
{
	if (getLength(list) == 1)
	{
		return;
	}

	List *left = firstHalf(list);
	List *right = secondHalf(list);

	mergeSort(left, sortBy);
	mergeSort(right, sortBy);

	merge(list, sortBy);

	deleteList(left);
	deleteList(right);
}
