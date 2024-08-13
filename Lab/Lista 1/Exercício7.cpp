// Exercício 7- Victor Costa Nova 
#include <iostream>


int main()
{
    int maior;
    int menor;
    int numbers[10];
    std::cout << "Digite 10 números: \n";
    for (int j = 0; j < 10; ++j)
    {
        std::cin >> numbers[j];
    }
    
    maior = numbers[0];
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] > maior)
        {
            maior = numbers[i];
        }
    }
    menor = numbers[0];
    for (int x = 0; x < 10; x++)
    {
        if (numbers[x] < menor)
        {
            menor = numbers[x];
        }
    }
    std::cout << "O maior número é: " << maior << "\n";
    std::cout << "O menor número é: " << menor << "\n";

    system("pause>0");
}


void abc()
{

    int menor1;
    int numbers[3];
    std::cout << "Digite 3 números: \n";
    for (int j = 0; j < 3; ++j)
    {
        std::cin >> numbers[j];
    }

    menor1 = numbers[0];
    for (int x = 0; x < 3; x++)
    {
        if (numbers[x] < menor1)
        {
            menor1 = numbers[x];
        }
    }

    int menor2;
    int numbers2[3];
    std::cout << "Digite 3 números: \n";
    for (int j = 0; j < 3; ++j)
    {
        std::cin >> numbers2[j];
    }

    menor2 = numbers2[0];
    for (int x = 0; x < 3; x++)
    {
        if (numbers2[x] < menor2)
        {
            menor2 = numbers2[x];
        }
    }

    if (menor1 < menor2)
    {
        std::cout << "O menor número entre os dois parâmetro  é: " << menor1 << "\n";
    }
    else if (menor1 > menor2)
    {
        std::cout << "O menor número entre os dois parâmetro é: " << menor2 << "\n";
    }
    else
    {
        std::cout << "O menor número está nos dois parâmetros e é: " << menor1 << "\n";
    }

    system("pause>0");
}