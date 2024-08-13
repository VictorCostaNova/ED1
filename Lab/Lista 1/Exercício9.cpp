// Exercício 9- Victor Costa Nova 
#include <iostream>



int main()
{
    int numbers[10];
    std::cout << "Digite 10 números: \n";
    for (int j = 0; j < 10; ++j)
    {
        std::cin >> numbers[j];
    }
    std::cout << "Ordem inversa dos números: ";
    for (int j = 9; j >= 0; --j)
    {
        std::cout << numbers[j] << "-";
    }

    system("pause>0");

    
}

