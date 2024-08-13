#include <iostream>
#include "StaticStack.h"

using namespace std;

int main()
{
	StaticStack stack = Create();
	cout << "Pilha vazia? " << IsEmpty(stack) << '\n';
	cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";

	Push(stack, 'a');
	cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";

	Push(stack, 'b');
	cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";

	Push(stack, 'c');
	cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";

	char temp = Pop(stack);
	cout << "Elemento removido da pilha: " << temp << '\n';
	cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";

	cout << "Capacidade da pilha: " << Size(stack) << '\n';
	cout << "Quantidade de elementos empilhados: " << Count(stack) << '\n';

	bool cleared = Clear(stack);
	cout << "Limpou a pilha? " << cleared << '\n';
	temp = Top(stack);
	if (temp == '\0')
	{
		cout << "Pilha vazia!\n";
	}

	cout << "Capacidade da pilha: " << Size(stack) << '\n';
	cout << "Quantidade de elementos empilhados: " << Count(stack) << '\n';
	cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";

	for (int i = 0; i < STATIC_STACK_CAPACITY + 3; ++i)
	{
		if (Push(stack, 65 + i))
		{
			cout << "Topo da pilha: " << Top(stack) << " (" << Count(stack) << "/" << Size(stack) << ")\n";
		}
		else
		{
			cout << "ERRO: Pilha cheia!\n";
		}
	}
}

