#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

const int STATIC_STACK_CAPACITY = 100;

struct StaticStack
{
	int count;
	char values[STATIC_STACK_CAPACITY];

};

StaticStack Create();

bool Push(StaticStack& stack, char elem);


char Pop(StaticStack& stack);

bool IsEmpty(const StaticStack& stack);

int Size(const StaticStack& stack);

int Count(const StaticStack& stack);

#endif

