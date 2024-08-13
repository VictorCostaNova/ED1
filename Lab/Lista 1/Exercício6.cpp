// Exercício 6- Victor Costa Nova 
#include <iostream>




int main()
{
    int number, fat;
    int fatorial = 1;
    std::cout << "Digite um número:";
    std::cin >> number;
    for (fat = 1; fat <= number; ++fat)
    {
        fatorial = fatorial * fat;
    }
    std::cout << "O fatorial deste número é: " << fatorial;

    system("pause>0");
}
