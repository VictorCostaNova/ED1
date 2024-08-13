// CIÊNCIA DA COMPUTAÇÃO (2021)
// ESTRUTURA DE DADOS I
// PROF. ANDRÉ KISHIMOTO
// Lista de Exercícios 2 (Pilha) - Exemplos de possíveis soluções.

#include <iostream>
#include <string>
#include "StaticStack.h"

using namespace std;
using namespace MyDataStructures;

string StringWithoutChar(const string& str, char value);
bool IsPalindrome_CompareAll(const string& str);
bool IsPalindrome_CompareHalf(const string& str);
bool CheckSymbols(const string& str);

/*
	1. Escreva um programa que leia uma string e indique se o texto informado
	é ou não é um palíndromo. Seu programa deve usar uma pilha para auxiliar
	na verificação do palíndromo.
	Por exemplo, "Mussum" e "A sacada da casa" são palíndromos, mas "Bolton"
	e "Hello World" não são. Considere a string vazia("") como palíndromo.
*/
void Ex1()
{
	cout << "*** Ex1: Palíndromo ***\n";

	string str;
	cout << "Digite uma mensagem: ";
	getline(cin, str);

	string strTemp = StringWithoutChar(str, ' ');
	cout << '\"' << str << "\" " << (IsPalindrome_CompareAll(strTemp) ? "É" : "NÃO É") << " palíndromo.\n";
}

void Ex1_Test()
{
	cout << "*** (TESTE) Ex1: Palíndromo ***\n";

	string testData[] =
	{
		"Mussum",
		"A sacada da casa",
		"Bolton",
		"Hello World"
	};

	string strTemp;
	for (const string& str : testData)
	{
		strTemp = StringWithoutChar(str, ' ');
		cout << '\"' << str << "\" " << (IsPalindrome_CompareHalf(strTemp) ? "É" : "NÃO É") << " palíndromo.\n";
	}	
}


/*
	2. Altere o programa anterior para verificar se uma data informada pelo
	usuário usando o formato DD/MM/YYYY é uma data palíndroma.
	Por exemplo, 12/02/2021 foi uma data palíndroma, mas 02/02/2021 não.
*/
void Ex2()
{
	cout << "*** Ex2: Palíndromo (datas) ***\n";

	string str;
	cout << "Digite uma data no formato DD/MM/YYYY: ";
	getline(cin, str);

	string strTemp = StringWithoutChar(str, '/');
	cout << '\"' << str << "\" " << (IsPalindrome_CompareHalf(strTemp) ? "É" : "NÃO É") << " palíndromo.\n";
}

void Ex2_Test()
{
	cout << "*** (TESTE) Ex2: Palíndromo (datas) ***\n";

	string testData[] =
	{
		"12/02/2021",
		"02/02/2021",
		"02/02/2020",
		"02/02/2021",
	};

	string strTemp;
	for (const string& str : testData)
	{
		strTemp = StringWithoutChar(str, '/');
		cout << '\"' << str << "\" " << (IsPalindrome_CompareAll(strTemp) ? "É" : "NÃO É") << " palíndromo.\n";
	}
}


/*
	3. Escreva um programa que usa pilha para verificar e informar se uma expressão
	(string) possui a correspondência e ordem correta dos símbolos (), [], {} e <>.
	A expressão deve ser informada pelo usuário.

	Por exemplo, os símbolos na string "{([{<>}])}" estão corretos, enquanto que na
	string "{([{<}>])}" o primeiro } e o > estão na ordem errada.

	Alguns exemplos que o programa deve informar OK:
	"(Hello([{W}o]r))ld!"
	"<html>"
	"(a && b) || (c && d)"

	E alguns exemplos que o programa deve informar erro de correspondência:
	"[x + y)"
	"<body"
	"(([]))}"
*/
void Ex3()
{
	cout << "*** Ex3: Correspondência e ordem de símbolos ***\n";

	string str;
	cout << "Digite uma mensagem: ";
	getline(cin, str);

	cout << "Checagem de símbolos: " << (CheckSymbols(str) ? "SEM" : "COM") << " erros --- " << str << '\n';
}

void Ex3_Test()
{
	cout << "*** (TESTE) Ex3: Correspondência e ordem de símbolos ***\n";

	string testData[] =
	{
		"{([{<>}])}",
		"{([{<}>])}",
		"(Hello([{W}o]r))ld!",
		"<html>",
		"(a && b) || (c && d)",
		"[x + y)",
		"<body",
		"(([]))}",
	};

	for (const string& str : testData)
	{
		cout << "Checagem de símbolos: " << (CheckSymbols(str) ? "SEM" : "COM") << " erros --- " << str << '\n';
	}
}


int main()
{
	setlocale(LC_ALL, "pt_BR");

	cout << "ESTRUTURA DE DADOS I - Lista de Exercícios 2 - Prof. André Kishimoto\n";

	int option = 0;
	do
	{
		cout << "\n*** OPÇÕES:\n"
			<< "[0] Sair\n"
			<< "[1] Palíndromo\n"
			<< "[2] Palíndromo (datas)\n"
			<< "[3] Correspondência e ordem de símbolos\n"
			<< "[4] (TESTE) Palíndromo\n"
			<< "[5] (TESTE) Palíndromo (datas)\n"
			<< "[6] (TESTE) Correspondência e ordem de símbolos\n"
			<< "Escolha uma opção: ";
		cin >> option;

		// Usamos o cin.ignore() para corrigir um bug quando usamos getline() após cin, pois o '\n' do cin
		// (enter pressionado pelo usuário) é repassado para o getline(), sendo que getline() é encerrada
		// quando encontra uma quebra de linha ('\n').
		// cin.ignore(), sem parâmetros, ignora o último caractere do cin (no caso, o '\n').
		cin.ignore();

		switch (option)
		{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex1_Test(); break;
			case 5: Ex2_Test(); break;
			case 6: Ex3_Test(); break;

			default:
				if (option != 0)
					cout << "*** Opção inválida!\n";
				break;
		}
	} while (option != 0);
}

string StringWithoutChar(const string& str, char toRemove)
{
	// Retorna uma cópia da string passada no primeiro parâmetro, mas sem
	// conter o caractere indicado no segundo parâmetro.
	string temp = str;
	temp.erase(remove(temp.begin(), temp.end(), toRemove), temp.end());
	return temp;
}

bool IsPalindrome_CompareAll(const string& str)
{
	Stack::StaticStack stack = Stack::Create();

	// Empilha cada caractere da string, convertendo para maiúsculo (toupper(char)) antes de empilhar.
	for (const char& c : str)
	{
		Stack::Push(stack, toupper(c));
	}

	// Verifica se a string é um palíndromo.
	// Nessa versão, comparamos todos os caracteres que compõem a string.
	// Há uma parada antecipada do loop se já detectamos que a string não é um palíndromo.
	bool isPalindrome = true;
	int current = 0;
	while (!Stack::IsEmpty(stack))
	{
		if (toupper(str[current]) != Stack::Pop(stack))
		{
			isPalindrome = false;
			break;
		}

		++current;
	}

	return isPalindrome;
}

bool IsPalindrome_CompareHalf(const string& str)
{
	Stack::StaticStack stack = Stack::Create();

	int size = str.length();

	// Operação de shift right: deslocamento de bit para a direita.
	// Aqui, deslocamos um bit para a direita. Isso significa que estamos dividindo o int size por 2^1.
	int half = size >> 1;

	// Exemplo da operação de shift right:
	// 1010 (bin) == 10 (dec), porque: 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 = 8 + 0 + 2 + 0 = 10.
	// 
	// 10 >> 1 (dec) == 10 / 2 == 1010 >> 1 => 0101
	// 0101 (bin) == 5 (dec), porque: 0 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0 = 0 + 4 + 0 + 1 = 5.
	//
	// 5 >> 1 (dec) == 5 / 2 == 0101 >> 1 => 0010
	// 0010 (bin) == 2 (dec), porque: 0 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 = 0 + 0 + 2 + 0 = 2.
	//
	// 2 >> 1 (dec) == 2 / 2 == 0010 >> 1 => 0001
	// 0001 (bin) == 1 (dec), porque: 0 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0 = 0 + 0 + 0 + 1 = 1.
	//
	// 1 >> 1 (dec) == 1 / 2 == 0001 >> 1 => 0000
	// 0000 (bin) == 0 (dec), porque: 0 * 2^3 + 0 * 2^2 + 0 * 2^1 + 0 * 2^0 = 0 + 0 + 0 + 0 = 0.


	// Empilha apenas metade da string, convertendo para maiúsculo (toupper(char)) antes de empilhar.
	// Podemos fazer isso porque temos um espelhamento da palavra / frase que é em um palíndromo.
	for (int i = 0; i < half; ++i)
	{
		Stack::Push(stack, toupper(str[i]));
	}

	// Verifica se a string é um palíndromo.
	// Nessa versão, comparamos se a segunda metade da string é igual à primeira metade invertida.
	// Há uma parada antecipada do loop se já detectamos que a string não é um palíndromo.
	bool isPalindrome = true;

	// Calcula o índice correto do início da segunda metade da string.
	// Exemplos:
	// - "ana" é ímpar e só empilhamos o primeiro 'a'. O 'n' está bem no meio da string, servindo
	// como "espelho" para a segunda metade invertida. Portanto, pulamos esse caractere.
	// Logo, half = 3/2 = 1 e current = 2.
	// No loop a seguir, comparamos se str[2] == str[0] (segundo 'a' == primeiro 'a'), pois empilhamos
	// o primeiro 'a' e agora o estamos desempilhando.
	//
	// - "anna" é par e empilhamos o primeiro 'a' e o primeiro 'n'. Já que a quantidade de caracteres
	// é par, não temos um "caractere espelho" e, portanto, half = 4/2 = 2 e current = 2.
	// No loop a seguir, comparamos se str[2] == str[1] (segundo 'n' == primeiro 'n') e depois comparamos
	// se str[3] == str[0] (segundo 'a' == primeiro 'a').
	int current = (size % 2 == 0 ? half : half + 1);

	while (!Stack::IsEmpty(stack))
	{
		if (toupper(str[current]) != Stack::Pop(stack))
		{
			isPalindrome = false;
			break;
		}

		++current;
	}

	return isPalindrome;
}

bool CheckSymbols(const string& str)
{
	Stack::StaticStack stack = Stack::Create();

	for (const char& c : str)
	{
		// Só estamos preocupados com esses quatro símbolos: ( { [ <
		// Ao empilhar os símbolos, sabemos quem foi o último símbolo do tipo "abre"
		// a aparecer na string.
		if (c == '('
			|| c == '{'
			|| c == '['
			|| c == '<')
		{
			Stack::Push(stack, c);
		}
		else
		{
			// Encontramos um símbolo do tipo "fecha". Se o último símbolo do tipo "abre"
			// que apareceu na string e que foi empilhado não for o seu par, então a string
			// já possui um erro e paramos a execução da função, retornando false.
			if ((c == ')' && Stack::Top(stack) != '(')
				|| (c == '}' && Stack::Top(stack) != '{')
				|| (c == ']' && Stack::Top(stack) != '[')
				|| (c == '>' && Stack::Top(stack) != '<'))
			{
				return false;
			}

			// Encontramos um símbolo do tipo "fecha" E o último símbolo do tipo "abre" que
			// apareceu na string e que foi empilhado é o seu par. OK, par encontrado,
			// desempilhamos o símbolo "abre" pois ele já foi verificado.
			if ((c == ')' && Stack::Top(stack) == '(')
				|| (c == '}' && Stack::Top(stack) == '{')
				|| (c == ']' && Stack::Top(stack) == '[')
				|| (c == '>' && Stack::Top(stack) == '<'))
			{
				Stack::Pop(stack);
			}
		}
	}

	// Se ainda existe algum símbolo empilhado e já percorremos toda a string, significa que
	// faltou algum símbolo do tipo "fecha".
	return Stack::IsEmpty(stack);
}
