#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__


const int STATIC_QUEUE_CAPACITY = 10;

struct StaticQueue
{
	int count;
	int values[STATIC_QUEUE_CAPACITY]; 
};


StaticQueue Create();


bool Enqueue(StaticQueue& stackqueue, int elem);


int Dequeue(StaticQueue& stackqueue);

int Pop(StaticQueue& stackqueue);

int Top(const StaticQueue& stackqueue);

int Front(const StaticQueue& stackqueue);


int Size(const StaticQueue& stackqueue);


int Count(const StaticQueue& stackqueue);


bool IsEmpty(const StaticQueue& stackqueue);


bool Clear(StaticQueue& stackqueue);

#endif 
