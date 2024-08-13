// Exercício 11- Victor Costa Nova 

#include <iostream>

float MulViaAdd(int n1, float n2)
{
    float soma;
    soma = n2;
    for (int i = 1; i < n1; i++)
    {
        soma = n2 + soma;
    }
    return soma;

}




int main()
{
    int number1;
    float number2;
    std::cout << "Digite qualquer numero: ";
    std::cin >> number2;
    std::cout << "Digite um numero inteiro: ";
    std::cin >> number1;
    std::cout << " A multiplicacao pela soma sera :" << MulViaAdd(number1, number2);
    system("pause>0");

}


