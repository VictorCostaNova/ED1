#include "QueueStack.h"


StaticQueue Create()
{
	
	StaticQueue queue = { 0, { 0 } };
	return queue;
	
}


bool Enqueue(StaticQueue& stackqueue, int elem)
{
	if (stackqueue.count == STATIC_QUEUE_CAPACITY)
	{
		return false;
	}

	stackqueue.values[stackqueue.count] = elem;
	++stackqueue.count;

	return true;
}


int Dequeue(StaticQueue& stackqueue)
{
	if (IsEmpty(stackqueue))
	{
		return '\0';
	}
	int t = Top(stackqueue);
	Pop(stackqueue);

	if (IsEmpty(stackqueue))
		return t;
	int rec = Dequeue(stackqueue);
	Enqueue(stackqueue, t);
	return rec;


}

int Pop(StaticQueue& stackqueue)
{
	if (IsEmpty(stackqueue))
	{
		return '\0';
	}

	int temp = stackqueue.values[stackqueue.count - 1];
	stackqueue.values[stackqueue.count - 1] = '\0';
	--stackqueue.count;

	return temp;
}

int Top(const StaticQueue& stackqueue)
{
	if (IsEmpty(stackqueue))
	{
		return '\0';
	}

	return stackqueue.values[stackqueue.count - 1];
}


int Front(const StaticQueue& stackqueue)
{
	if (IsEmpty(stackqueue))
	{
		return '\0';
	}

	return stackqueue.values[0];
	
}


int Size(const StaticQueue& stackqueue)
{
	return sizeof(stackqueue.values) / sizeof(stackqueue.values[0]);
}


int Count(const StaticQueue& stackqueue)
{
	return stackqueue.count;
}


bool IsEmpty(const StaticQueue& stackqueue)
{
	return stackqueue.count == 0;
}


bool Clear(StaticQueue& stackqueue)
{
	while (!IsEmpty(stackqueue))
	{
		Dequeue(stackqueue);
	}

	return IsEmpty(stackqueue);
}