#include "manager.hpp"
#include <iostream>

int main()
{

	Manager man;

	int opcao, volta;

	std::string s1, s2;

	//Nome do arquivo que contem os dados
	std::string backupManager = "tarefas.txt";

	int numAux;

	man.carregarTarefas(backupManager);

	do
	{
		std::cout << "\n\n== Gerenciador de Tarefas == \n\n";

		std::cout << "1. Adicionar tarefa\n";
		std::cout << "2. Listar tarefas\n";
		std::cout << "3. Concluir tarefa\n";
		std::cout << "4. Remover tarefa\n";
		std::cout << "5. Salvar e sair" << std::endl;

		std::cout << "Escolha: ";
		std::cin >> opcao;

		switch (opcao)
		{
		case 1:

			std::cout << "Nome da tarefa: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, s1);

			std::cout << "Descricao da tarefa: ";
			std::getline(std::cin, s2);

			man.addTask(s1,s2);

			break;

		case 2:

			
			do
			{
				std::cout << "\n\n== Gerenciador de Tarefas == \n";
				std::cout << "== Lista das Tarefas == \n\n";

				std::cout << "1. Listar todas as tarefas\n";
				std::cout << "2. Listar tarefas finalizadas\n";
				std::cout << "3. Listar tarefas pendentes\n";
				std::cout << "4. Voltar" << std::endl;

				std::cout << "Escolha: ";
				std::cin >> volta;

				if (volta == 1 || volta == 2 || volta == 3)
					man.listTasks(volta);
				else if(volta != 4)
					std::cout << "\nOpcao invalida\n";

			}while(volta != 4);

			break;

		case 3:

			std::cout << "Identificacao da tarefa a ser concluida: ";
			std::cin >> numAux;

			if (man.markComplete(numAux))
				std::cout << "\nTarefa Concluida com Sucesso\n";
			else
				std::cout << "\nTarefa nao encontrada\n";

			break;

		case 4:

			std::cout << "Identificacao da tarefa a ser removida: ";
			std::cin >> numAux;

			if (man.removeTask(numAux))
				std::cout << "\nTarefa Removida com Sucesso\n";
			else
				std::cout << "\nTarefa nao encontrada\n";

			break;

		case 5:
			//Salvar e sair
			man.salvarTarefas(backupManager);

			break;

		default:
			//Colocou um numero invalido
			std::cout << "\nOpcao invalida\n";
		}

	} while (opcao != 5);

	return 0;
}