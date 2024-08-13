// Exercício 15- Victor Costa Nova 
#include <iostream>

bool AreCirclesColliding(int xp1, int yp1, int r1, int xp2, int yp2, int r2)
{
	int somaraio = r1 + r2;
	int variA = xp1 - xp2;
	int variB = yp1 - yp2;
	float distance = sqrt(variA * variA + variB * variB);
	if (somaraio >= distance)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	int xp1;
	int yp1;
	int r1;
	std::cout << "Digite o x de p1: ";
	std::cin >> xp1;
	std::cout << "Digite o y de p1: ";
	std::cin >> yp1;
	std::cout << "Digite o raio r1: ";
	std::cin >> r1;
	int xp2;
	int yp2;
	int r2;
	std::cout << "Digite o x de p2: ";
	std::cin >> xp2;
	std::cout << "Digite o y de p2: ";
	std::cin >> yp2;
	std::cout << "Digite o raio r2: ";
	std::cin >> r2;
	bool sobrep = AreCirclesColliding(xp1, yp1, r1, xp2, yp2, r2);
	if (sobrep)
	{
		std::cout << "Os círculos estão sobrepostos.";
	}
	else
	{
		std::cout << "Os círculos não estão sobrepostos.";
	}
	system("pause>0");
}


