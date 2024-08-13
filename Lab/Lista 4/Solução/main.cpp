// main.cpp
#include <iostream>
#include <clocale>
#include "LinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
    for (Node* node = list->GetHead(); node != nullptr; node = node->GetNext())
    {
        std::cout << node->GetData() << ' ';
    }
    std::cout << '\n';
}

void PrintListInfo(const LinkedList* list)
{
    if (list->IsEmpty())
    {
        cout << "Lista vazia!\n";
    }
    else
    {
        cout << "Lista: ";
        Print(list);
    }
}

int main()
{
    setlocale(LC_ALL, "pt_BR");
    cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";

    LinkedList* list = new LinkedList();
    PrintListInfo(list);

    list->Insert(1);
    list->Insert(2);
    list->Insert(3);
    list->Append(4);
    list->Append(5);
    list->Append(6);
    PrintListInfo(list);

    list->Clear();
    PrintListInfo(list);

    list->Insert(77);
    list->Append(88);
    list->Insert(99);
    list->Append(3);
    list->Insert(2);
    list->Append(1);
    list->Insert(0);
    PrintListInfo(list);

    Node* temp = list->RemoveNode(3);
    cout << "Nó removido: " << temp->GetData()<< '\n';
    delete temp;
    PrintListInfo(list);

    temp = list->RemoveHead();
    cout << "Nó removido: " << temp->GetData() << '\n';
    delete temp;
    PrintListInfo(list);

    temp = list->RemoveTail();
    cout << "Nó removido: " << temp->GetData() << '\n';
    delete temp;
    PrintListInfo(list);

    delete list;

    cout << "Fim.\n";
}
