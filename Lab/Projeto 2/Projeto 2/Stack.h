

#ifndef __Dinamic_Stack_H__
#define __Dinamic_Stack_H__
#include <string>
using namespace std;


struct Node
{
	string data;
	float number;
	Node* next;
	Node* previous;
};

struct DinamicStack
{
	int count;
	Node* head;
	Node* tail;
};

DinamicStack* Create();

void Destroy(DinamicStack* stack);

Node* Push(DinamicStack* stack, string car);

Node* Push1(DinamicStack* stack, float number);

Node* Pop(DinamicStack* stack);

float Top(DinamicStack* stack);

int Count(DinamicStack* stack);

bool IsEmpty(DinamicStack* stack);

bool Clear(DinamicStack* stack);

int Operators(string ch);


float Operations(float a, float b, string op);



#endif 
