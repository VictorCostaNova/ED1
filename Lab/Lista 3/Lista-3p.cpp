#include <iostream>
#include <string>
#include "Queue.h"
#include <ctime>


//Victor Costa Nova 


using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");
	StaticQueue MarcaA = Create();
	StaticQueue TempoA = Create();											// Criando filas para cada valor da Marca A			
	StaticQueue EstanteA = Create();
	StaticQueue PrateleiraA = Create();
	StaticQueue GavetaA = Create();

	StaticQueue MarcaB = Create();
	StaticQueue TempoB = Create();
	StaticQueue EstanteB = Create();										// Criando filas para cada valor da Marca B
	StaticQueue PrateleiraB = Create();
	StaticQueue GavetaB = Create();

	StaticQueue MarcaAB = Create();
	StaticQueue TempoAB = Create();											// Criando filas para cada valor da Marca A e Marca B
	StaticQueue EstanteAB = Create();
	StaticQueue PrateleiraAB = Create();
	StaticQueue GavetaAB = Create();


	char option;
	cout << "\nMENU\n"
		<< "[0] Sair\n"
		<< "[1] Cadastrar no estoque\n"									// Menu Com 3 op��es
		<< "[2] Retirar do estoque\n"
		<< "Escolha uma op��o: ";
	cin >> option;

	while (option != '0')
	{
		if (option == '1')																	                           //Inicio Op��o 1- Cadastro
		{
			char type;
			cout << "\nDigite qual marca ser� cadastrada (A ou B): ";
			cin >> type;
				

			while (type != 'A' && type != 'a' && type != 'B' && type != 'b')
			{
				cout << "Digite a marca da �gua corretamente (A ou B): ";
				cin >> type;
			}
			
			time_t data = time(nullptr);
			

		
			


			int est;
			cout << "Digite qual estante o recipiente ser� armazenado ([1][2][3][4][5]): ";
			cin >> est;
			while (est <1 || est> 5)
			{
				cout << "Digite uma das estantes acima : ";
				cin >> est;
			}


			int prat;
			cout << "Digite o n�mero da prateleira onde o recipiente ser� armazenado (1 a 10): ";
			cin >> prat;
			while (prat <1 || prat> 10)
			{
				cout << "Digite uma das prateleiras acima : ";
				cin >> prat;
			}

			int gav;
			cout << "Digite o n�mero da gaveta onde o recipiente ser� armazenado (1 a 4): ";
			cin >> gav;
			while (gav < 1 || gav> 4)
			{
				cout << "Digite uma das gavetas acima : ";
				cin >> gav;
			}

			if (type == 'A' || type == 'a')
			{
				Enqueue(MarcaA, type);
				Enqueue2(TempoA, data);
				Enqueue1(EstanteA, est);
				Enqueue1(PrateleiraA, prat);                                                                                 //Salvando as entradas nas filas A e AB
				Enqueue1(GavetaA, gav);

				Enqueue(MarcaAB, type);
				Enqueue2(TempoAB, data);
				Enqueue1(EstanteAB, est);
				Enqueue1(PrateleiraAB, prat);
				Enqueue1(GavetaAB, gav);

				


			}
			else if (type == 'B' || type == 'b')
			{
				Enqueue(MarcaB, type);
				Enqueue2(TempoB, data);
				Enqueue1(EstanteB, est);
				Enqueue1(PrateleiraB, prat);
				Enqueue1(GavetaB, gav);                                                                           //Salvando as entradas nas filas B e AB

				Enqueue(MarcaAB, type);
				Enqueue2(TempoAB, data);
				Enqueue1(EstanteAB, est);
				Enqueue1(PrateleiraAB, prat);
				Enqueue1(GavetaAB, gav);

			}
			cout << "\nEscolha uma op��o do menu: ";                                
			cin >> option;                                                                                      //Fim Op��o 1- Cadastro

		}
		else if (option == '2')																					//Inicio Op��o 2- Remo��o
		{
			char escolha;
			cout << "\nOP��ES:\n"
				<< "[0] Remover Marca A\n"
				<< "[1] Remover Marca B\n"																		//Mini menu com as escolhas de remo��o
				<< "[2] Tanto Faz\n"
				<< "[3] Voltar para o menu\n"
				<< "Escolha uma op��o: ";
			cin >> escolha;
			while (escolha != '3')
			{
				if (escolha == '0')																				//Remo��o Marca A - Remover primeiros elementos das filas A
				{
					if (Front(MarcaA) == false)
					{
						cout << "N�o h� estoque da �gua A.\n";
						escolha = '3';
					}
					else if (Front(MarcaAB) == 'A' || Front(MarcaAB) == 'a')
					{
						cout << "\nMarca removida:" << Front(MarcaA) << "\n";                                           //Se os primeiros elementos das filas AB forem da marca A,
						Dequeue(MarcaA);
									                                                                                            							
						time_t t = Front2(TempoA);                                                                                           
						tm timeInfo;
						localtime_s(&timeInfo, &t);
						cout << "Hor�rio cadastrado: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << " "
							<< " " << timeInfo.tm_hour << ":" << timeInfo.tm_min << "\n";

						Dequeue2(TempoA);                                                                                            //ser�o removidos os primeiros elementos das filas AB tamb�m.
						
						cout << "Estante armazenada:" << Front1(EstanteA) << "\n";
						Dequeue1(EstanteA);
						cout << "Prateleira armazenada:" << Front1(PrateleiraA) << "\n";
						Dequeue1(PrateleiraA);
						cout << "Gaveta armazenada:" << Front1(GavetaA) << "\n";
						Dequeue1(GavetaA);

						Dequeue(MarcaAB);
						Dequeue2(TempoAB);
						Dequeue1(EstanteAB);
						Dequeue1(PrateleiraAB);
						Dequeue1(GavetaAB);

						escolha = '3';
					}
					else
					{
						cout << "\nMarca removida:" << Front(MarcaA) << "\n";
						Dequeue(MarcaA);
						
						time_t t = Front2(TempoA);
						tm timeInfo;
						localtime_s(&timeInfo, &t);
						cout << "Hor�rio cadastrado: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << " "
							<< " " << timeInfo.tm_hour << ":" << timeInfo.tm_min << "\n";
						Dequeue2(TempoA);
						
						cout << "Estante armazenada:" << Front1(EstanteA) << "\n";
						Dequeue1(EstanteA);
						cout << "Prateleira armazenada:" << Front1(PrateleiraA) << "\n";
						Dequeue1(PrateleiraA);
						cout << "Gaveta armazenada:" << Front1(GavetaA) << "\n";
						Dequeue1(GavetaA);

						escolha = '3';

					}

				}
				else if (escolha == '1')                                                                                    //Remo��o Marca B - Remover primeiros elementos das filas B
				{
					if (Front(MarcaB) == false)
					{
						cout << "N�o h� estoque da �gua B.\n";
						escolha = '3';
					}
					else if (Front(MarcaAB) == 'B' || Front(MarcaAB) == 'b')
					{
							cout << "\nMarca removida:" << Front(MarcaB) << "\n";
							Dequeue(MarcaB);
							time_t t = Front2(TempoB);
							tm timeInfo;
							localtime_s(&timeInfo, &t);
							cout << "Hor�rio cadastrado: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << " "
								<< " " << timeInfo.tm_hour << ":" << timeInfo.tm_min << "\n";
							                                                                                                               //Se os primeiros elementos das filas AB forem da marca B,
							Dequeue2(TempoB);                                                                                              //ser�o removidos os primeiros elementos das filas AB tamb�m.
							cout << "Estante armazenada:" << Front1(EstanteB) << "\n";
							Dequeue1(EstanteB);
							cout << "Prateleira armazenada:" << Front1(PrateleiraB) << "\n";
							Dequeue1(PrateleiraB);
							cout << "Gaveta armazenada:" << Front1(GavetaB) << "\n";
							Dequeue1(GavetaB);

							Dequeue(MarcaAB);
							Dequeue2(TempoAB);
							Dequeue1(EstanteAB);
							Dequeue1(PrateleiraAB);
							Dequeue1(GavetaAB);

							escolha = '3';
					}
					else
					{
						cout << "\nMarca removida:" << Front(MarcaB) << "\n";
						Dequeue(MarcaB);

						time_t t = Front2(TempoB);
						tm timeInfo;
						localtime_s(&timeInfo, &t);
						cout << "Hor�rio cadastrado: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << " "
							<< " " << timeInfo.tm_hour << ":" << timeInfo.tm_min << "\n";

						Dequeue2(TempoB);
						cout << "Estante armazenada:" << Front1(EstanteB) << "\n";
						Dequeue1(EstanteB);
						cout << "Prateleira armazenada:" << Front1(PrateleiraB) << "\n";
						Dequeue1(PrateleiraB);
						cout << "Gaveta armazenada:" << Front1(GavetaB) << "\n";
						Dequeue1(GavetaB);
						escolha = '3';
						
					}
				}
				else if (escolha == '2')                                                                                        //Remo��o Marcas A ou B - Remover primeiros elementos das filas AB
				{
					if (Front(MarcaA) == false && Front(MarcaB) == false)
					{
						cout << "N�o h� estoque de nenhuma marca.\n";
						escolha = '3';
					}
					else if (Front(MarcaAB) == 'A' || Front(MarcaAB) == 'a')
					{
						cout << "\nMarca removida:" << Front(MarcaAB) << "\n";
						Dequeue(MarcaAB);

						time_t t = Front2(TempoAB);
						tm timeInfo;
						localtime_s(&timeInfo, &t);
						cout << "Hor�rio cadastrado: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << " "
							<< " " << timeInfo.tm_hour << ":" << timeInfo.tm_min << "\n";
						                                                                                                              //Se os primeiros elementos das filas AB forem da marca A,                                                                                                         
						Dequeue2(TempoAB);                                                                                           //ser�o removidos os primeiros elementos das filas A tamb�m.
						cout << "Estante armazenada:" << Front1(EstanteAB) << "\n";
						Dequeue1(EstanteAB);
						cout << "Prateleira armazenada:" << Front1(PrateleiraAB) << "\n";
						Dequeue1(PrateleiraAB);
						cout << "Gaveta armazenada:" << Front1(GavetaAB) << "\n";
						Dequeue1(GavetaAB);

						Dequeue(MarcaA);
						Dequeue2(TempoA);
						Dequeue1(EstanteA);
						Dequeue1(PrateleiraA);
						Dequeue1(GavetaA);

						escolha = '3';
					}
					else if (Front(MarcaAB) == 'B' || Front(MarcaAB) == 'b')
					{
						cout << "\nMarca removida:" << Front(MarcaAB) << "\n";
						Dequeue(MarcaAB);
						time_t t = Front2(TempoAB);
						tm timeInfo;
						localtime_s(&timeInfo, &t);
						cout << "Hor�rio cadastrado: " << timeInfo.tm_mday << '/' << (timeInfo.tm_mon + 1) << "/" << (timeInfo.tm_year + 1900) << " "
							<< " " << timeInfo.tm_hour << ":" << timeInfo.tm_min << "\n";
						                                                                                                             //Se os primeiros elementos das filas AB forem da marca B
						Dequeue2(TempoAB);                                                                                           //ser�o removidos os primeiros elementos das filas B tamb�m
						cout << "Estante armazenada:" << Front1(EstanteAB) << "\n";
						Dequeue1(EstanteAB);
						cout << "Prateleira armazenada:" << Front1(PrateleiraAB) << "\n";
						Dequeue1(PrateleiraAB);
						cout << "Gaveta armazenada:" << Front1(GavetaAB) << "\n";
						Dequeue1(GavetaAB);

						Dequeue(MarcaB);
						Dequeue2(TempoB);
						Dequeue1(EstanteB);
						Dequeue1(PrateleiraB);
						Dequeue1(GavetaB);

						escolha = '3';
					}

				}
				else
				{
					cout << "\nEscolha uma das op��es acima: ";
					cin >> escolha;                                                                                      //Fim Op��o 2- Remo��o
				}
			}
			cout << "\nEscolha uma op��o do menu: ";
			cin >> option;
		}
		else
		{
		cout << "Escolha uma op��o v�lida do menu: ";
		cin >> option;
		}

	}
	system("pause>0");                                                                                         //Sa�da do Menu
}





	


	





