// Exercício 3- Victor Costa Nova 
#include <iostream>
 



int main()
{
	char letter;
	std::cout << "Digite uma letra: ";
	std::cin >> letter;

	if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
	{
		printf("Essa letra é uma vogal");
	}
	else
	{
		printf("Essa letra é uma consoante");
	}
	system("pause>0");
}
