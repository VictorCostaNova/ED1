

// Refer�ncia: https://www.tutorialspoint.com/evaluate-reverse-polish-notation-in-cplusplus-program

#include<iostream>
#include"Stack.h"
#include <string>
#include <sstream>


void RPN(string postfix)
{
    DinamicStack* stack1 = Create();
    DinamicStack* stack2 = Create();
    istringstream iss(postfix);
    string str;
    while (iss >> str)
    {
        try
        {
            float value = stof(str);
            Push1(stack1, value);
        }
        catch (invalid_argument e)
        {
            Push(stack1, str);
        }
    }

    Node* aux = stack1->head;
    for (int i = 0; i < stack1->count; i++)
    {
        if (Operators(aux->data) != -1)
        {
            Push(stack2, aux->data);
            aux = aux->next;
        }
        else 
        {
            Push1(stack2, aux->number);
            aux = aux->next;
        }
    }
    
    Node* aux2 = stack2->head;
    float a, b;
    int erros = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < stack1->count; i++)
    {
        if (aux2->number == 0)
        {
            count1 = count1 + 1;
            a = Top(stack2);
            if (Top(stack2) == 0)
            {
                erros = erros + 1;
                i = stack1->count;

            }
            Pop(stack2);
            if (Top(stack2) == 0)
            {
                erros = erros + 1;
                i = stack1->count;
                
            }
            else
            {
                b = Top(stack2);
                Pop(stack2);
                if (Top(stack2) == 0)
                {
                    Pop(stack2);
                }
                Push1(stack2, Operations(a, b, aux2->data));
                aux2 = aux2->next;

            }
            
        }
        else 
        {
            aux2 = aux2->next;
            count2 = count2 + 1;
        }
    }
    
    int dif = count2 - count1;
    if (count1 == count2)
    {
        cout << "\nErro na express�o.\n";
    }

    else if (dif == 2 || dif > 2)
    {
        cout << "\nErro na express�o.\n";
    }
    else if (count1 == 0 && count2 == 1)
    {
        cout << "\nErro na express�o.\n";
    }
    else
    {
        if (erros == 0)
        {
            cout << "\nO Resultado �: " << Top(stack2)<<"\n";
        }
        else
        {
            cout << "\nErro na express�o.\n";
        }
    }
    
  
}
 


int main()
{
    setlocale(LC_ALL, "pt_BR");
    string expresion;
    cout << "\nDigite uma nota��o p�s fixada: ";
    getline(cin, expresion);
   
    while (expresion != "0")
    {
        RPN(expresion);
        cout << "\nDigite outra nota��o p�s fixada: ";
        getline(cin, expresion);       
    }
    cout << "Fim";
    
}