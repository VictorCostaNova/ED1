

#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

DinamicStack* Create()
{

	DinamicStack* stack = new DinamicStack;

	stack->count = 0;

	stack->head = nullptr;

	stack->tail = nullptr;

	return stack;
}


void Destroy(DinamicStack* stack)
{

	Clear(stack);
	delete stack;
	stack = nullptr;
}

Node* Push(DinamicStack* stack, string car)
{

	Node* node = new Node;

	node->data = car;
	node->number = 0;

	node->next = stack->head;
	node->previous = stack->tail;

	if (stack->count == 0)
	{
		stack->tail = node;
		stack->head = node;
		++stack->count;
		return node;
	}
	else
	{
		stack->head->previous = node;
		stack->head = node;
		++stack->count;
		return node;
	}

}

Node* Push1(DinamicStack* stack, float number)
{

	Node* node = new Node;

	node->number = number;

	node->next = stack->head;
	node->previous = stack->tail;

	if (stack->count == 0)
	{
		stack->tail = node;
		stack->head = node;
		++stack->count;
		return node;
	}
	else
	{
		stack->head->previous = node;
		stack->head = node;
		++stack->count;
		return node;
	}

}


Node* Pop(DinamicStack* stack)
{

	Node* toRemove = stack->head;

	if (stack->head == stack->tail)
	{

		stack->head = stack->tail = nullptr;
	}
	else
	{

		stack->head = stack->head->next;
	}

	--stack->count;
	return toRemove;
}

float Top(DinamicStack* stack)
{
	return stack->head->number;
}

int Count(DinamicStack* stack)
{
	return stack->count;
}

bool IsEmpty(DinamicStack* stack)
{

	return (stack->head == nullptr && stack->tail == nullptr);
}

bool Clear(DinamicStack* stack)
{
	Node* node = stack->head;

	while (node != stack->tail)
	{
		Pop(stack);
		node = node->next;
	}
	Pop(stack);
	return IsEmpty(stack);
}


int Operators(string ch)
{
	if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
		return 1;
	return -1;
}


float Operations(float a, float b, string op)
{
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
		return a / b;
}
