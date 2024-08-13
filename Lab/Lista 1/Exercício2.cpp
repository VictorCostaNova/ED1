// Exercício 2- Victor Costa Nova 
#include <iostream>

int main()
{
	float distance;
	std::cout << "Digite a distância percorrida (em Km): ";
	std::cin >> distance;
	float time;
	std::cout << "Digite o tempo que levou (em horas): ";
	std::cin >> time;
	float medspeed = distance/time;
	std::cout << "Sua velocidade média foi de: " << medspeed << "km/h. \n";
	if (medspeed > 90)
	{
		printf("Você ultrapassou o limite de velocidade de 90 km/h.");
	}
	

	system("pause>0");
}