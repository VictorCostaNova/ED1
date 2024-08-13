// CI�NCIA DA COMPUTA��O (2021)
// ESTRUTURA DE DADOS I
// PROF. ANDR� KISHIMOTO
// Lista de Exerc�cios 2 (Pilha) - Exemplos de poss�veis solu��es.

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
	� ou n�o � um pal�ndromo. Seu programa deve usar uma pilha para auxiliar
	na verifica��o do pal�ndromo.
	Por exemplo, "Mussum" e "A sacada da casa" s�o pal�ndromos, mas "Bolton"
	e "Hello World" n�o s�o. Considere a string vazia("") como pal�ndromo.
*/
void Ex1()
{
	cout << "*** Ex1: Pal�ndromo ***\n";

	string str;
	cout << "Digite uma mensagem: ";
	getline(cin, str);

	string strTemp = StringWithoutChar(str, ' ');
	cout << '\"' << str << "\" " << (IsPalindrome_CompareAll(strTemp) ? "�" : "N�O �") << " pal�ndromo.\n";
}

void Ex1_Test()
{
	cout << "*** (TESTE) Ex1: Pal�ndromo ***\n";

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
		cout << '\"' << str << "\" " << (IsPalindrome_CompareHalf(strTemp) ? "�" : "N�O �") << " pal�ndromo.\n";
	}	
}


/*
	2. Altere o programa anterior para verificar se uma data informada pelo
	usu�rio usando o formato DD/MM/YYYY � uma data pal�ndroma.
	Por exemplo, 12/02/2021 foi uma data pal�ndroma, mas 02/02/2021 n�o.
*/
void Ex2()
{
	cout << "*** Ex2: Pal�ndromo (datas) ***\n";

	string str;
	cout << "Digite uma data no formato DD/MM/YYYY: ";
	getline(cin, str);

	string strTemp = StringWithoutChar(str, '/');
	cout << '\"' << str << "\" " << (IsPalindrome_CompareHalf(strTemp) ? "�" : "N�O �") << " pal�ndromo.\n";
}

void Ex2_Test()
{
	cout << "*** (TESTE) Ex2: Pal�ndromo (datas) ***\n";

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
		cout << '\"' << str << "\" " << (IsPalindrome_CompareAll(strTemp) ? "�" : "N�O �") << " pal�ndromo.\n";
	}
}


/*
	3. Escreva um programa que usa pilha para verificar e informar se uma express�o
	(string) possui a correspond�ncia e ordem correta dos s�mbolos (), [], {} e <>.
	A express�o deve ser informada pelo usu�rio.

	Por exemplo, os s�mbolos na string "{([{<>}])}" est�o corretos, enquanto que na
	string "{([{<}>])}" o primeiro } e o > est�o na ordem errada.

	Alguns exemplos que o programa deve informar OK:
	"(Hello([{W}o]r))ld!"
	"<html>"
	"(a && b) || (c && d)"

	E alguns exemplos que o programa deve informar erro de correspond�ncia:
	"[x + y)"
	"<body"
	"(([]))}"
*/
void Ex3()
{
	cout << "*** Ex3: Correspond�ncia e ordem de s�mbolos ***\n";

	string str;
	cout << "Digite uma mensagem: ";
	getline(cin, str);

	cout << "Checagem de s�mbolos: " << (CheckSymbols(str) ? "SEM" : "COM") << " erros --- " << str << '\n';
}

void Ex3_Test()
{
	cout << "*** (TESTE) Ex3: Correspond�ncia e ordem de s�mbolos ***\n";

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
		cout << "Checagem de s�mbolos: " << (CheckSymbols(str) ? "SEM" : "COM") << " erros --- " << str << '\n';
	}
}


int main()
{
	setlocale(LC_ALL, "pt_BR");

	cout << "ESTRUTURA DE DADOS I - Lista de Exerc�cios 2 - Prof. Andr� Kishimoto\n";

	int option = 0;
	do
	{
		cout << "\n*** OP��ES:\n"
			<< "[0] Sair\n"
			<< "[1] Pal�ndromo\n"
			<< "[2] Pal�ndromo (datas)\n"
			<< "[3] Correspond�ncia e ordem de s�mbolos\n"
			<< "[4] (TESTE) Pal�ndromo\n"
			<< "[5] (TESTE) Pal�ndromo (datas)\n"
			<< "[6] (TESTE) Correspond�ncia e ordem de s�mbolos\n"
			<< "Escolha uma op��o: ";
		cin >> option;

		// Usamos o cin.ignore() para corrigir um bug quando usamos getline() ap�s cin, pois o '\n' do cin
		// (enter pressionado pelo usu�rio) � repassado para o getline(), sendo que getline() � encerrada
		// quando encontra uma quebra de linha ('\n').
		// cin.ignore(), sem par�metros, ignora o �ltimo caractere do cin (no caso, o '\n').
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
					cout << "*** Op��o inv�lida!\n";
				break;
		}
	} while (option != 0);
}

string StringWithoutChar(const string& str, char toRemove)
{
	// Retorna uma c�pia da string passada no primeiro par�metro, mas sem
	// conter o caractere indicado no segundo par�metro.
	string temp = str;
	temp.erase(remove(temp.begin(), temp.end(), toRemove), temp.end());
	return temp;
}

bool IsPalindrome_CompareAll(const string& str)
{
	Stack::StaticStack stack = Stack::Create();

	// Empilha cada caractere da string, convertendo para mai�sculo (toupper(char)) antes de empilhar.
	for (const char& c : str)
	{
		Stack::Push(stack, toupper(c));
	}

	// Verifica se a string � um pal�ndromo.
	// Nessa vers�o, comparamos todos os caracteres que comp�em a string.
	// H� uma parada antecipada do loop se j� detectamos que a string n�o � um pal�ndromo.
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

	// Opera��o de shift right: deslocamento de bit para a direita.
	// Aqui, deslocamos um bit para a direita. Isso significa que estamos dividindo o int size por 2^1.
	int half = size >> 1;

	// Exemplo da opera��o de shift right:
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


	// Empilha apenas metade da string, convertendo para mai�sculo (toupper(char)) antes de empilhar.
	// Podemos fazer isso porque temos um espelhamento da palavra / frase que � em um pal�ndromo.
	for (int i = 0; i < half; ++i)
	{
		Stack::Push(stack, toupper(str[i]));
	}

	// Verifica se a string � um pal�ndromo.
	// Nessa vers�o, comparamos se a segunda metade da string � igual � primeira metade invertida.
	// H� uma parada antecipada do loop se j� detectamos que a string n�o � um pal�ndromo.
	bool isPalindrome = true;

	// Calcula o �ndice correto do in�cio da segunda metade da string.
	// Exemplos:
	// - "ana" � �mpar e s� empilhamos o primeiro 'a'. O 'n' est� bem no meio da string, servindo
	// como "espelho" para a segunda metade invertida. Portanto, pulamos esse caractere.
	// Logo, half = 3/2 = 1 e current = 2.
	// No loop a seguir, comparamos se str[2] == str[0] (segundo 'a' == primeiro 'a'), pois empilhamos
	// o primeiro 'a' e agora o estamos desempilhando.
	//
	// - "anna" � par e empilhamos o primeiro 'a' e o primeiro 'n'. J� que a quantidade de caracteres
	// � par, n�o temos um "caractere espelho" e, portanto, half = 4/2 = 2 e current = 2.
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
		// S� estamos preocupados com esses quatro s�mbolos: ( { [ <
		// Ao empilhar os s�mbolos, sabemos quem foi o �ltimo s�mbolo do tipo "abre"
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
			// Encontramos um s�mbolo do tipo "fecha". Se o �ltimo s�mbolo do tipo "abre"
			// que apareceu na string e que foi empilhado n�o for o seu par, ent�o a string
			// j� possui um erro e paramos a execu��o da fun��o, retornando false.
			if ((c == ')' && Stack::Top(stack) != '(')
				|| (c == '}' && Stack::Top(stack) != '{')
				|| (c == ']' && Stack::Top(stack) != '[')
				|| (c == '>' && Stack::Top(stack) != '<'))
			{
				return false;
			}

			// Encontramos um s�mbolo do tipo "fecha" E o �ltimo s�mbolo do tipo "abre" que
			// apareceu na string e que foi empilhado � o seu par. OK, par encontrado,
			// desempilhamos o s�mbolo "abre" pois ele j� foi verificado.
			if ((c == ')' && Stack::Top(stack) == '(')
				|| (c == '}' && Stack::Top(stack) == '{')
				|| (c == ']' && Stack::Top(stack) == '[')
				|| (c == '>' && Stack::Top(stack) == '<'))
			{
				Stack::Pop(stack);
			}
		}
	}

	// Se ainda existe algum s�mbolo empilhado e j� percorremos toda a string, significa que
	// faltou algum s�mbolo do tipo "fecha".
	return Stack::IsEmpty(stack);
}
