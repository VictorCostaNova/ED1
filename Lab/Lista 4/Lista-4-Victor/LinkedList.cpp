// Victor Costa Nova 

//
#include "LinkedList.h"
#include <iostream>

LinkedList* Create()/// FUNCIONANDO
{
	//cria / aloca mem�ria para uma nova lista
	LinkedList* list = new LinkedList;

	// tamanho da lista come�a com zero
	list->count = 0;

	// head come�a com valor nulo
	list->head = nullptr;

	//tail come�a com valor nulo
	list->tail = nullptr;

	// retorna a nova lista
	return list;
}


void Destroy(LinkedList* list)
{
	//TO DO: esvazia a lista (Clear())
	Clear(list);

	// libera mem�ria alocada para a lista
	delete list;
	list = nullptr;
}

Node* Insert(LinkedList* list, int elem) ///FUNCIONANDO
{
	//cria / aloca novo n� node
	Node* node =  new Node;
		
	//node-> data = data
	node->data = elem; 

	//node � o primeiro n� da lista, ent�o node next aponta para head (1)
	node->next = list->head;
		
	//se lista estiver vazia
	if (list->head == nullptr && list->tail == nullptr)
	{
		//tail aponta para node
		list->tail = node;
	}
	//head aponta para node
	list->head = node;

	//aumenta o tamanho da lista
	++list->count;

	return node;

	//*(1) �aponta para� significa �recebe� ou, nesse caso, node next = head
}

Node* Append(LinkedList* list, int elem) // FUNCIONANDO
{
	//cria / aloca novo n� node
	Node* node = new Node;   
		
	//node-> data = data
	node-> data = elem; 
		
	//node � o �ltimo n� da lista, ent�o node->next � nulo(temp->next = nullptr)
	node->next = nullptr;
		
	//se lista estiver vazia
	if (list->head == nullptr && list->tail == nullptr)
	{
		//head e tail apontam para node
		list->head = node;
		list->tail = node;
	}
	//sen�o
	else
	{
		//tail.next aponta para node
		list->tail->next = node;
		//tail aponta para node
		list->tail = node;
	}
			
	//aumenta o tamanho da lista
	++list->count;

	return node;
}

Node* RemoveHead(LinkedList* list)/// FUNCIONANDO
{
	//cria n� toRemove que aponta para head
	Node* toRemove = list->head;

	// se existe s� um n� na lista(head � igual � tail)
	if (list->head == list->tail)
	{
		//n�o h� mais n�s na lista(head e tail viram nulo)
		list->head = list->tail = nullptr;
	}
	else // sen�o
	{
		//head agora aponta para o segundo n� (head->next)
		list->head = list->head->next;
	}
	// diminui tamanho da lista
	--list->count;

	// retorna toRemove
	return toRemove;
}

Node* RemoveTail(LinkedList* list)////    FUNCIONANDO
{
	//--se existe s� um n� na lista
	if (list->head == list->tail)
	{
		//remove e retorna n� usando RemoveHead()
		RemoveHead(list);
	}
	//percorre a lista at� chegar em tail(1)
	//(1)cria n� toRemove que come�a em head
	Node* toRemove = list->head;
	//cria n� previous que come�a como nulo
	Node* previous = new Node;
	previous = nullptr;

	//enquanto toRemove n�o chegou em tail
	while (toRemove->next != nullptr)
	{
		//previous aponta para toRemove
		previous = toRemove;

		//toRemove aponta para o pr�ximo n� da lista(toRemove->next)
		toRemove = toRemove->next;
	} 
	
	//previous->next aponta para nulo
	previous->next = nullptr;


	//tail aponta para pen�ltimo n� (previous)
	list->tail = previous;


	//diminui tamanho da lista
	--list->count;
		
	//retorna toRemove
	return toRemove;
}

Node* RemoveNode(LinkedList* list, int value) ///     FUNCIONANDO 
{
	// cria n� toRemove que come�a em head
	Node* toRemove = list->head;
	//cria n� previous que come�a como nulo
	Node* previous = nullptr;
	//enquanto toRemove n�o for nulo e valor de toRemove n�o � value
	while (toRemove != nullptr && toRemove->data != value)
	{
		//previous aponta para toRemove
		previous = toRemove;
		//toRemove aponta para o pr�ximo n� da lista(toRemove->next)
		toRemove = toRemove->next;
	}
			
	//se toRemove for nulo, retorna nulo
	if (toRemove == nullptr)
	{
		return toRemove;
	}
			
	//se toRemove for head, remove e retorna n� usando RemoveHead()
	else if (toRemove == list->head)
	{
		RemoveHead(list);
	}
	//se toRemove for tail, remove e retorna n� usando RemoveTail()
	else if (toRemove == list->tail)
	{
		RemoveTail(list);
	}
	//sen�o
	else
	{
	//previous->next aponta para toRemove->next
		previous->next = toRemove->next;

	//diminui tamanho da lista
	--list->count;

	//retorna toRemove
	return toRemove;
	}

}

Node* GetHead(LinkedList* list)//FUNCIONANDO
{
	//retorna n� head
	return list->head;

}

Node* GetTail(LinkedList* list)//FUNCIONANDO
{
	//retorna n� tail
	return list->tail;
}

Node* GetNode(LinkedList* list, int value)//FUNCIONANDO
{
	//cria n� node que aponta para head
	Node* node = list->head;
	
	//enquanto n�o chegou ao fim da lista(node n�o � nulo)
	while (node != nullptr)
	{
		//se node tem valor value
		if (node->data == value)         
		{
			//retorna node
			return node;

		}
		//node aponta para node next
		node = node->next;

	}
	//retorna nulo, j� que n� com valor value n�o foi encontrado
	std::cout << "Erro";
	return node;
}

int Count(LinkedList* list)//FUNCIONANDO
{
	// retorna tamanho da lista
	return list->count;

}

bool IsEmpty(LinkedList* list)//FUNCIONANDO
{
	//vazio quando head � igual � nulo e tail � igual � nulo(ou quando tamanho da lista � zero)
	return (list->head == nullptr && list->tail == nullptr);
}

bool Clear(LinkedList* list)//FUNCIONANDO
{
	//cria n� node que come�a em head
	Node* node = list->head;
		
	//enquanto node n�o for nulo
	while (node != nullptr)
	{
		RemoveHead(list);
		node = node->next;
	}
	return IsEmpty(list);
}
