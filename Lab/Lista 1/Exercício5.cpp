// Exercício 5- Victor Costa Nova 


int main()
{
	printf("A equação da reta é: 3x + y = 8 \n");
	int varix;
	std::cout << "Digite o valor de x: ";
	std::cin >> varix;
	int variy;
	std::cout << "Digite o valor de y: ";
	std::cin >> variy;
	if (3 * varix + variy == 8)
	{
		printf("O ponto (%d,%d) pertence a reta", varix, variy);
	}
	else
	{
		printf("O ponto (%d,%d) não pertence a reta", varix, variy);
	}
  
	system("pause>0");
	return 0;

}
