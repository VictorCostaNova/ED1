#include <iostream>
#include <string>
#include "Stack.h"


//Victor Costa Nova Alexandre
//Tia:32052960

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");
	printf("Exercício 1: \n");
	string str;
	cout << "\nDigite uma palavra ou uma frase somente com letras minúsculas ou maiúsculas e sem ascentos: ";
	getline(cin, str);
	cout << "String digitada: " << str << "\n";

	str.erase(remove(str.begin(), str.end(), '!'), str.end());
	str.erase(remove(str.begin(), str.end(), ','), str.end());
	str.erase(remove(str.begin(), str.end(), '.'), str.end());
	str.erase(remove(str.begin(), str.end(), '?'), str.end());
	str.erase(remove(str.begin(), str.end(), ' '), str.end());


	StaticStack stack1 = Create();
	for (int lett = 0; lett < str.size(); lett++)
		Push(stack1, (char)str[lett]);

	StaticStack stack2 = Create();
	for (int let = 0; let < str.size(); let++)
		Push(stack2, (char)stack1.values[stack1.count - 1 - let]);

	int pali = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (stack1.values[i] == stack2.values[i])
			pali++;
	}
	if (pali == stack1.count)
		cout << "A string digitada é um palíndromo.\n";
	else
		cout << "A string digitada não é um palíndromo.\n";

	printf("\nExercício 2: \n");
	string data;
	cout << "Digite uma data com o formato DD/MM/YYYY : ";
	getline(cin, data);
	cout << "Data digitada: " << data << "\n";


	data.erase(remove(data.begin(), data.end(), '/'), data.end());


	StaticStack stack3 = Create();
	for (int lett = 0; lett < data.size(); lett++)
		Push(stack3, (char)data[lett]);

	StaticStack stack4 = Create();
	for (int let = 0; let < data.size(); let++)
		Push(stack4, (char)stack3.values[stack3.count - 1 - let]);

	int datapali = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (stack3.values[i] == stack4.values[i])
			datapali++;
	}
	if (datapali == stack3.count)
		cout << "A data digitada é  palíndroma.\n";
	else
		cout << "A data digitada não é palíndroma.\n";

	printf("\nExercício 3: \n");

	char symb[8] = { '{', '}', '[', ']',  '(', ')', '<', '>' };
	char open[4] = { '{' , '[' , '(' , '<' };
	char close[4] = { '}' , ']' , ')' , '>' };
	


	string expsymbols;
	cout << "Digite uma expressão com símbolos: ";
	getline(cin, expsymbols);
	expsymbols.erase(remove(expsymbols.begin(), expsymbols.end(), ' '), expsymbols.end());

	StaticStack stacksymbols = Create();
	for (int i = 0; i < expsymbols.size(); i++)
		for (int j = 0; j < 8; j++)
			if (expsymbols[i] == symb[j])
				Push(stacksymbols, (char)expsymbols[i]);

	StaticStack stackopen = Create();//Seleciona os simbolos abertos
	for (int i=0; i< Count(stacksymbols);i++)
		for (int j = 0; j < 4; j++)
		if (stacksymbols.values[i] == open[j])
			Push(stackopen, stacksymbols.values[i]);

	StaticStack stackclose = Create();//Seleciona os simbolos fechados
	for (int i = 0; i < Count(stacksymbols);i++)
		for (int j = 0; j < 4; j++)
			if (stacksymbols.values[i] == close[j])
				Push(stackclose, close[j]);

	StaticStack stackclose1 = Create();// Valor do stackclose inverso Ex: stackclose= ))}} - stackclose1=}}))
	for (int i = 0; i < Count(stackclose); i++)
		Push(stackclose1, (char)stackclose.values[stackclose.count - 1 - i]);


	char change1 = '}';
	char change2 = '{';
	char change3 = ']';
	char change4 = '[';
	char change5 = ')';
	char change6 = '(';
	char change7 = '>';
	char change8 = '<';
	
		
	StaticStack stackopen1 = Create();// Transforma os símbolos fechados em abertos
	for (int i = 0; i < Count(stackclose1);)
	{
		if (stackclose1.values[i] == change1)
		{
			Push(stackopen1, change2);
			i++;
		}
		else if (stackclose1.values[i] == change3)
		{
			Push(stackopen1, change4);
			i++;
		}
		else if (stackclose1.values[i] == change5)
		{
			Push(stackopen1, change6);
			i++;
		}

		else if (stackclose1.values[i] == change7)
		{
			Push(stackopen1, change8);
			i++;
		}
	}


	int falso= 0;
	for (int i = 0; i < Count(stackopen1); i++)
	{
		if (stackopen1.values[i] != stackopen.values[i])
			falso = 1;
		else
			falso = 0;

	}

	if (falso==0)
		cout << "Os símbolos estão na ordem correta. \n";
	else
		cout << "Os símbolos não estão na ordem correta.\n";

	system("pause>0");
}