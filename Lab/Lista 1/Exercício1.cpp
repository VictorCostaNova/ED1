

#include <iostream>
void troca(int* x, int* y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
int main(void)
{
    int valora;
    std::cout << "Digite o volar de a: ";
    std::cin >> valora;
    int valorb;
    std::cout << "Digite o volar de b: ";
    std::cin >> valorb;
    printf("Valores: a= %d e b= %d\n", valora, valorb);
    troca(&valora, &valorb);
    printf("Valores trocados: a= %d e b= %d", valora, valorb);
    system("pause>0");
    return 0;

    

}