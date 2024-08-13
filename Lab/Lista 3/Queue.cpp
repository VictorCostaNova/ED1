#include "Queue.h"
#include <iostream>
#include <ctime>

StaticQueue Create()
{
	StaticQueue queue =
	{
		0, 
		0, 
		0, 
		{ 0 } 
	};

	return queue;
}
bool Enqueue(StaticQueue& queue, char elem)
{
	if (queue.count == Size(queue))
	{
		return false;
	}
	queue.values[queue.rear] = elem;
	queue.rear = (queue.rear + 1) % Size(queue); 
	++queue.count;
	return true;
}

bool Enqueue1(StaticQueue& queue, int elem)
{
	if (queue.count == Size(queue))
	{
		return false;
	}
	queue.values2[queue.rear] = elem;
	queue.rear = (queue.rear + 1) % Size(queue);
	++queue.count;
	return true;
}
bool Enqueue2(StaticQueue& queue, time_t elem)
{
	if (queue.count == Size(queue))
	{
		return false;
	}
	queue.values1[queue.rear] = elem;
	queue.rear = (queue.rear + 1) % Size(queue);
	++queue.count;
	return true;
}


char Dequeue(StaticQueue& queue)
{
	if (IsEmpty(queue))
	{
		return '\0';
	}

	char value = queue.values[queue.front];
	queue.values[queue.front] = '\0';
	queue.front = (queue.front + 1) % Size(queue); 
	--queue.count;
	return value;
}

int Dequeue1(StaticQueue& queue)
{
	if (IsEmpty(queue))
	{
		return '\0';
	}

	int value = queue.values2[queue.front];
	queue.values2[queue.front] = '\0';
	queue.front = (queue.front + 1) % Size(queue);
	--queue.count;
	return value;
}
time_t Dequeue2(StaticQueue& queue)                              
{
	if (IsEmpty(queue))
	{
		return '\0';
	}

	time_t value = queue.values1[queue.front];
	queue.values[queue.front] = '\0';
	queue.front = (queue.front + 1) % Size(queue);
	--queue.count;
	return value;
}

char Front(const StaticQueue& queue)
{
	return IsEmpty(queue) ? '\0' : queue.values[queue.front];
}

int Front1(const StaticQueue& queue)
{
	return IsEmpty(queue) ? '\0' : queue.values2[queue.front];
}

time_t Front2(const StaticQueue& queue)
{
	return IsEmpty(queue) ? '\0' : queue.values1[queue.front];
}

int Size(const StaticQueue& queue)
{
	return sizeof(queue.values) / sizeof(queue.values[0]); 
}

int Count(const StaticQueue& queue)
{
	return queue.count;
}

bool IsEmpty(const StaticQueue& queue)
{
	return queue.count == 0;
}

bool Clear(StaticQueue& queue)
{
	while (!IsEmpty(queue))
	{
		Dequeue(queue);
	}
	return IsEmpty(queue);
}