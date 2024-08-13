// Exercício 13- Victor Costa Nova 

#include <iostream>

int Max(int n[3], int n2[3])
{
    int maior1;
    maior1 = n[0];
    for (int x = 0; x < 3; x++)
    {
        if (n[x] > maior1)
        {
            maior1 = n[x];
        }
    }
    int maior2;
    maior2 = n2[0];
    for (int x = 0; x < 3; x++)
    {
        if (n2[x] > maior2)
        {
            maior2 = n2[x];
        }
    }

    if (maior1 > maior2)
    {
        return maior1;
    }
    else if (maior1 < maior2)
    {
        return maior2;
    }
    else if (maior1 = maior2)
    {
        return maior1;
    }
}

int main()
{
   
    int numbers[3];
    std::cout << "Digite 3 números: \n";
    for (int j = 0; j < 3; ++j)
    {
        std::cin >> numbers[j];
    }
    int numbers2[3];
    std::cout << "Digite 3 números: \n";
    for (int j = 0; j < 3; ++j)
    {
        std::cin >> numbers2[j];
    }
    std::cout << "O maior número entre os dois parâmetros é: " << Max(numbers, numbers2);
    system("pause>0");
}
