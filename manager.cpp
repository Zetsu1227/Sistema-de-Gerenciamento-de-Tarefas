#include "manager.hpp"
#include <iostream>


Manager::Manager()
{

	//comeca com o vetor vazio
	tasks = {};

	prox = 1;
}

void Manager::addTask(const std::string& nome, const std::string& descricao)
{
	//Inicializa a nova tarefa
	Task t(prox, nome ,descricao);

	//Coloca ela no vetor do gerenciamento
	tasks.push_back(t);

	//aumenta o contador para a proxima tarefa a ser adicionada
	prox++;

}

bool Manager::removeTask(int identificacao)
{
	int conta = 0;

	for (const Task& t : tasks)	//const& para nao copiar toda a estrutura e nao modifica-la
	{
		conta++;
		if (t.getId() == identificacao)
		{
			tasks.erase(tasks.begin() + conta);
			
			//retorna true se conseguiu remover a tarefa selecionada
			return true;
		}
	}

	//retorna false se não conseguiu remover a tarefa selecionada
	return false;
}

bool Manager::markComplete(int identificacao)
{

	for (Task& t : tasks)	//& para nao copiar toda a estrutura
	{
		if (t.getId() == identificacao)
		{
			t.taskCompleted();

			//retorna true se conseguiu marcar a tarefa como completa
			return true;
		}
	}

	//retorna false se nao achar a tarefa
	return false;
}

void Manager::listTasks() const
{
	//caso trivial
	if (tasks.empty())
	{
		std::cout << "\n Nenhuma tarefa! \n";
		return; 
	} 

	std::string atual;


	for (const Task& t : tasks)
	{
		if (t.getStatus())
			atual = "Finalizada";
		else
			atual = "Pendente";


		std::cout << "ID: " << t.getId() << " || Nome: " << t.getName() << " || Status: " << atual << "\n";
	}

	std::cout << "" << std::endl;

}
