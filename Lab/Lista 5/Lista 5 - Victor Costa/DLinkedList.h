// Victor Costa Nova 


#ifndef __DLINKED_LIST_H__
#define __DLINKED_LIST_H__
#include <string>
using namespace std;

struct Node
{
	string name;
	int id;
	Node* next;
	Node* previous;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();

void Destroy(LinkedList* list);

Node* Insert(LinkedList* list, int elem, string name);

Node* Append(LinkedList* list, int elem, string name);

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

