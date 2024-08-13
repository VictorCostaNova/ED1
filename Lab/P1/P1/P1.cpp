
// Refer�ncia para montar a Dequeue: https://www.educative.io/edpresso/how-to-implement-a-queue-using-stacks-in-cpp 

#include "QueueStack.h"
#include <iostream>
#include <windows.h>


using namespace std;



int main()
{
	setlocale(LC_ALL, "pt_BR");
    StaticQueue queuestack = Create();
    cout << "------------------------------------------------------------------------";
    cout << "\nAdicione um n�mero a Queue: ";
    int ent;
    cin >> ent;
    Enqueue(queuestack, ent);
    cout << "\nCapacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";

    cout << "\nAdicione outro n�mero a Queue: ";
    cin >> ent;
    Enqueue(queuestack, ent);
    cout << "\nCapacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";

    cout << "\nAdicione outro n�mero a Queue: ";
    cin >> ent;
    Enqueue(queuestack, ent);
    cout << "\nCapacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";

    cout << "\nAdicione outro n�mero a Queue: ";
    cin >> ent;
    Enqueue(queuestack, ent);
    cout << "\nCapacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";
    Sleep(2000);

    cout << "------------------------------------------------------------------------";
    cout << "\nDequeue: \n";
    Dequeue(queuestack);
    Sleep(5000);
    cout << "Capacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";

    Sleep(2000);
    cout << "\nDequeue: \n";
    Dequeue(queuestack);
    Sleep(5000);
    cout << "Capacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";

    Sleep(2000);
    cout << "------------------------------------------------------------------------";
    cout << "\nLimpar a Queue: \n";
    Clear(queuestack);
    Sleep(5000);
    cout << "Capacidade da Queue: [" << Count(queuestack) << "/" << Size(queuestack) << "]\n";
    cout << "Front Queue:" << Front(queuestack) << "\n";

    system("pause>0");
    
}
