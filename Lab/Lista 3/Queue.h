#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <ctime>


const int QUEUE_CAPACITY = 1000;




struct StaticQueue
{
	int front;
	int rear;
	int count;

	char values[QUEUE_CAPACITY];
	time_t values1[QUEUE_CAPACITY];                        //Permitindo a struct aceitar valores com a variavel time_t
	int values2[QUEUE_CAPACITY];                           //Permitindo a struct aceitar valores com a variavel int
	
};

StaticQueue Create();

bool Enqueue(StaticQueue& queue, char elem);

bool Enqueue1(StaticQueue& queue, int elem);             //Função Enqueue para valores int

bool Enqueue2(StaticQueue& queue, time_t elem);          //Função Enqueue para a data e hora com a variavel time_t


char Dequeue(StaticQueue& queue);

int Dequeue1(StaticQueue& queue);                    // Função Dequeue para valores int

time_t Dequeue2(StaticQueue& queue);                 // Função Dequeue para a data e hora com a variavel time_t


char Front(const StaticQueue& queue);

int Front1(const StaticQueue& queue);

time_t Front2(const StaticQueue& queue);                 //Função Front para devolver data e hora com a variavel time_t

int Size(const StaticQueue& queue);


int Count(const StaticQueue& queue);


bool IsEmpty(const StaticQueue& queue);


bool Clear(StaticQueue& queue);

#endif 
