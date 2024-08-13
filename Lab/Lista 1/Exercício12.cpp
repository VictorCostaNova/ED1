// Exercício 12- Victor Costa Nova 

#include <iostream>

int Min(int n[3], int n2[3])
{
    int menor1;
    menor1 = n[0];
    for (int x = 0; x < 3; x++)
    {
        if (n[x] < menor1)
        {
            menor1 = n[x];
        }
    }
    int menor2;
    menor2 = n2[0];
    for (int x = 0; x < 3; x++)
    {
        if (n2[x] < menor2)
        {
            menor2 = n2[x];
        }
    }

    if (menor1 < menor2)
    {
        return menor1;
    }
    else if (menor1 > menor2)
    {
        return menor2;
    }
    else if (menor1=menor2)
    {
        return menor1;
    }
}

int main()
{
    int menor1;
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
    std::cout << "O menor número entre os dois parâmetros é: " << Min(numbers, numbers2);
    system("pause>0");
}


