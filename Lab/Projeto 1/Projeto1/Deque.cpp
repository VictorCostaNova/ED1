// Projeto 1
// Victor Costa Nova 

#include "Deque.h"

StaticDeque Create()
{
	StaticDeque deque = { 0, { 0 } };
	return deque;
}

bool InsertFront(StaticDeque& deque, int elem)
{
	if (deque.count == STATIC_DEQUE_CAPACITY)
	{
		return false;
	}

	deque.values[deque.count] = elem;
	++deque.count;

	return true;

}

bool InsertBack(StaticDeque& deque, int elem)
{


	if (deque.count == STATIC_DEQUE_CAPACITY)
	{
		return false;
	}
	int aux;
	int i = 0;
	StaticDeque dequeaux = Create();
	InsertFront(dequeaux, elem);
	while (i != deque.count)
	{
		aux = Back(deque);
		InsertFront(dequeaux, aux);
		RemoveBack(deque);
	}
	while (i != dequeaux.count)
	{
		aux = Back(dequeaux);
		InsertFront(deque, aux);
		RemoveBack(dequeaux);
	}
	return true;

}

int RemoveFront(StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}

	int temp = deque.values[deque.count - 1];
	deque.values[deque.count - 1] = '\0';
	--deque.count;

	return temp;
}

int RemoveBack(StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}
	int last = Front(deque);
	RemoveFront(deque);

	if (IsEmpty(deque))
		return last;
	int rec = RemoveBack(deque);
	InsertFront(deque, last);
	return rec;
}

int Front(const StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}

	return deque.values[deque.count - 1];

}

int Back(const StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}

	return deque.values[0];
}

int Size(const StaticDeque& deque)
{
	return sizeof(deque.values) / sizeof(deque.values[0]);
}


int Count(const StaticDeque& deque)
{
	return deque.count;
}


bool IsEmpty(const StaticDeque& deque)
{
	return deque.count == 0;
}


bool Clear(StaticDeque& deque)
{
	while (!IsEmpty(deque))
	{
		RemoveFront(deque);
	}

	return IsEmpty(deque);
}
