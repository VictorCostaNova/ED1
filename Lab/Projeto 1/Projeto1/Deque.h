// Projeto 1
// Victor Costa Nova 

#ifndef __STATIC_DEQUE_H__
#define __STATIC_DEQUE_H__


const int STATIC_DEQUE_CAPACITY = 8;

struct StaticDeque
{
	int count;
	int values[STATIC_DEQUE_CAPACITY];
};




StaticDeque Create();

bool InsertFront(StaticDeque& deque, int elem);
bool InsertBack(StaticDeque& deque, int elem);


int RemoveFront(StaticDeque& deque);
int RemoveBack(StaticDeque& deque);


int Front(const StaticDeque& deque);
int Back(const StaticDeque& deque);


int Size(const StaticDeque& deque);


int Count(const StaticDeque& deque);


bool IsEmpty(const StaticDeque& deque);


bool Clear(StaticDeque& deque);

#endif 
