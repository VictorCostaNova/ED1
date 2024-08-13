// Projeto 1
// Victor Costa Nova 


#include "Deque.h"
#include <iostream>
#include <windows.h>

using namespace std;



int main()
{
    setlocale(LC_ALL, "pt_BR");
    StaticDeque deque = Create();
    cout << "------------------------------------------------------------------------";
    cout << "\nAdicione um n�mero ao in�cio da Deque: ";
    int ent;
    cin >> ent;
    InsertFront(deque, ent);
    cout << "\nCapacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    cout << "\nAdicione outro n�mero ao in�cio da Deque: ";
    cin >> ent;
    InsertFront(deque, ent);
    cout << "\nCapacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    cout << "\nAdicione outro n�mero ao in�cio da Deque: ";
    cin >> ent;
    InsertFront(deque, ent);
    cout << "\nCapacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    cout << "\nAgora adicione um n�mero ao fim da Deque: ";     
    cin >> ent;
    InsertBack(deque, ent);
    cout << "\nCapacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    cout << "\nAdicione outro n�mero ao fim da Deque: ";      
    cin >> ent;
    InsertBack(deque, ent);
    cout << "\nCapacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";
    Sleep(2000);

    cout << "\nAdicione outro n�mero ao fim da Deque: ";
    cin >> ent;
    InsertBack(deque, ent);
    cout << "\nCapacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";
    Sleep(2000);



    cout << "------------------------------------------------------------------------";
    cout << "\nRemovendo Front da Deque: \n";
    RemoveFront(deque);
    Sleep(5000);
    cout << "Capacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    Sleep(2000);
    cout << "\nRemovendo Front da Deque: \n";
    RemoveFront(deque);
    Sleep(5000);
    cout << "Capacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    Sleep(2000);
    cout << "\nRemovendo Back da Deque: \n";
    RemoveBack(deque);
    Sleep(5000);
    cout << "Capacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    Sleep(2000);
    cout << "\nRemovendo Back da Deque: \n";
    RemoveBack(deque);
    Sleep(5000);
    cout << "Capacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    Sleep(2000);
    cout << "------------------------------------------------------------------------";
    cout << "\nLimpando a Deque: \n";
    Clear(deque);
    Sleep(3000);
    cout << "Capacidade da Deque: [" << Count(deque) << "/" << Size(deque) << "]\n";
    cout << "Front Deque:" << Front(deque) << "\n";
    cout << "Back Deque:" << Back(deque) << "\n";

    cout << "\nFim.";

    system("pause>0");
}

