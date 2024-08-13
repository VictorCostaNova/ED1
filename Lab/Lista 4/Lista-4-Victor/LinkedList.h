// Victor Costa Nova 

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__


struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();

void Destroy(LinkedList* list);

Node* Insert(LinkedList* list, int elem);

Node* Append(LinkedList* list, int elem);

Node* RemoveHead(LinkedList* list);

Node* RemoveTail(LinkedList* list);

Node* RemoveNode(LinkedList* list, int value);

Node* GetHead(LinkedList* list);

Node* GetTail(LinkedList* list);

Node* GetNode(LinkedList* list, int value);

int Count(LinkedList* list);

bool IsEmpty(LinkedList* list);

bool Clear(LinkedList* list);

#endif 
