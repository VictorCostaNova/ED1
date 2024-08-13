// Exercício 10 - Victor Costa Nova 
#include <iostream>

int main()
{
    int numbers[6];
    std::cout << "Digite 6 números: \n";
    for (int j = 0; j < 6; ++j)
    {
        std::cin >> numbers[j];
    }
    int change = 0;
    for (int j = 0; j < 6; j++)
        for(int i=0; i<6; i++)
            if (numbers[j] < numbers[i])
            {
                change = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = change;
            }
    std::cout << "Números em ordem crescente:";
    for (int j = 0; j < 6; j++)
        std::cout << numbers[j] << "-";

    system("pause>0");
}
