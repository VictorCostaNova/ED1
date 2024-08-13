// Exercício 14- Victor Costa Nova 
#include <iostream>
#include <string>

int VowelsCount(char s[10])
{
	int count;
	int countA = 0;
	int countE = 0;
	int countI = 0;
	int countO = 0;
	int countU = 0;
	for (int i = 0; i < 10; i++)
	{
		if (s[i] == 'a' || s[i] == 'A')
		{
			countA = countA + 1;
		}
		else if (s[i] == 'e' || s[i] == 'E')
		{
			countE = countE + 1;
		}
		else if (s[i] == 'i' || s[i] == 'I')
		{
			countI = countI + 1;
		}
		else if (s[i] == 'o' || s[i] == 'O')
		{
			countO = countO + 1;
		}
		else if (s[i] == 'u' || s[i] == 'U')
		{
			countU = countU + 1;
		}
	}
	count = countA + countE + countI + countO + countU;
	return count;
}

int main()
{
	char string[10];
	std::cout << "Digite uma string com 10 caracteres: ";
	std::cin >> string;
	std::cout << "O total de vogais nessa string é: " << VowelsCount(string);

	system("pause>0");

}