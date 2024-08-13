// Victor Costa Nova 
#include <iostream>
#include <clocale>
#include "DLinkedList.h"

using namespace std;
void Print(const LinkedList* list)
{
	Node* aux = list->head;
	for (int i = 0; i < list->count; i++)
	{
		cout << "[" << aux->id << "]" << " " << aux->name << "\n";
		aux = aux->next;
	}
	cout << "\n";
}
void PrintReverse(const LinkedList* list)
{

	Node* aux = list->tail;
	for (int i = 0; i < list->count; i++)
	{
		cout << "[" << aux->id << "]" << " " << aux->name << "\n";
		aux = aux->previous;
	}
	cout << "\n";
}
void PrintDoubleListInfo(LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}
int main()
{
	setlocale(LC_ALL, "pt_BR");
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List) ***\n";
	LinkedList* list = Create();
	PrintDoubleListInfo(list);
	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");
	PrintDoubleListInfo(list);
	Clear(list);
	PrintDoubleListInfo(list);
	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);
	Node* temp = RemoveNode(list, 44);
	cout << "N� removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	delete temp;
	temp = nullptr;
	PrintDoubleListInfo(list);
	temp = RemoveHead(list);
	cout << "N� removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	delete temp;
	temp = nullptr;
	PrintDoubleListInfo(list);
	temp = RemoveTail(list);
	cout << "N� removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	delete temp;
	temp = nullptr;
	PrintDoubleListInfo(list);
	Destroy(list);
	cout << "Fim.\n";
}
