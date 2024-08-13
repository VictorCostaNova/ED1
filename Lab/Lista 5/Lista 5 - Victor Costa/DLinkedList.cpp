// Victor Costa Nova 
#include "DLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

LinkedList* Create()
{

	LinkedList* list = new LinkedList;

	list->count = 0;

	list->head = nullptr;

	list->tail = nullptr;

	return list;
}


void Destroy(LinkedList* list)
{

	Clear(list);


	delete list;
	list = nullptr;
}

Node* Insert(LinkedList* list, int elem, string name)
{

	Node* node = new Node;


	node->id = elem;
	node->name = name;

	node->next = list->head;
	node->previous = list->tail;

	if (list->count == 0)
	{
		list->tail = node;
		list->head = node;
		++list->count;
		return node;
	}
	else
	{
		list->head->previous = node;
		list->head = node;
		++list->count;
		return node;
	}

}

Node* Append(LinkedList* list, int elem, string name)
{

	Node* node = new Node;


	node->id = elem;
	node->name = name;

	node->next = list->head;
	node->previous = list->tail;

	if (list->count == 0)
	{

		list->head = node;
		list->tail = node;
	}

	else
	{

		list->tail->next = node;
		list->tail = node;
	}


	++list->count;

	return node;
}

Node* RemoveHead(LinkedList* list)
{

	Node* toRemove = list->head;

	if (list->head == list->tail)
	{

		list->head = list->tail = nullptr;
	}
	else
	{

		list->head = list->head->next;
	}

	--list->count;
	return toRemove;
}

Node* RemoveTail(LinkedList* list)
{
	Node* toRemove = list->tail;

	if (list->head == list->tail)
	{
		RemoveHead(list);
	}
	else
	{
		list->tail = list->tail->previous;
	}

	--list->count;
	return toRemove;
}

Node* RemoveNode(LinkedList* list, int value)
{

	Node* toRemove = list->head;
	for (int i = 0; i < list->count; i++)
	{
		while (toRemove->id != value)
		{
			toRemove = toRemove->next;
		}
		if (toRemove == nullptr)
		{
			return toRemove;
		}
		else if (toRemove == list->head)
		{
			RemoveHead(list);
		}
		else if (toRemove == list->tail)
		{
			RemoveTail(list);
		}
		else
		{
			toRemove->previous->next = toRemove->next;
			toRemove->next->previous = toRemove->previous;

			--list->count;


			return toRemove;
		}
	}
}

Node* GetHead(LinkedList* list)
{

	return list->head;

}

Node* GetTail(LinkedList* list)
{
	return list->tail;
}

Node* GetNode(LinkedList* list, int value)
{

	Node* node = list->head;


	for (int i = 0; i < list->count; i++)
	{

		if (node->id == value)
		{

			return node;

		}
		node = node->next;

	}
	cout << "Erro";
	return node;
}

int Count(LinkedList* list)
{
	return list->count;
}

bool IsEmpty(LinkedList* list)
{

	return (list->head == nullptr && list->tail == nullptr);
}

bool Clear(LinkedList* list)
{
	Node* node = list->head;

	while (node != list->tail)
	{
		RemoveHead(list);
		node = node->next;
	}
	RemoveHead(list);
	return IsEmpty(list);
}
