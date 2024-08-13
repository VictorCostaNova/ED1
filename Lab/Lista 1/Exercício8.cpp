// Exercício 8- Victor Costa Nova 

 
    int main()
    {
       
        int valora = 1;
        int valorb = 1;
        int contagem = 3;
        int nextnumber;
        int term;
        std::cout << "Digite um termo para a a Sequência de Fibonacci: ";
        std::cin >> term;
        std::cout << " A Sequência de Fibonacci até o "<< term <<"º termo é: " << valora << "-" << valorb << "-";
        nextnumber = valora + valorb;
        while (contagem <= term)
        {
            std::cout << nextnumber << "-";
            valora = valorb;
            valorb = nextnumber;
            nextnumber = valora + valorb;
            contagem = contagem + 1;
        }
        system("pause>0");
    }
    

