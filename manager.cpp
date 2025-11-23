#include "manager.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Manager::Manager()
{
	//comeca com o vetor vazio
	tasks = {};

	prox = 1;
}

void Manager::addTask(const std::string& nome, const std::string& descricao)
{
	//Inicializa a nova tarefa -> por padrao comeca Pendente
	Task t(prox, nome ,descricao, false);

	//Coloca ela no vetor do gerenciamento
	tasks.push_back(t);

	//aumenta o contador para a proxima tarefa a ser adicionada
	prox++;

}

bool Manager::removeTask(int identificacao)
{
	//por causa do index tem q ta negativo ou inverter a ordem da conta++
	int conta = -1;

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
			if (!t.getStatus())
				t.taskCompleted();
			else
				std::cout << "\nTarefa ja estava concluida\n";

			//retorna true se conseguiu marcar a tarefa como completa
			return true;
		}
	}

	//retorna false se nao achar a tarefa
	return false;
}

void Manager::listTasks(int vol) const
{
	//caso trivial
	if (tasks.empty())
	{
		std::cout << "\n Nenhuma tarefa! \n";
		return; 
	} 

	std::string atual;

	
	std::cout << "\n== TAREFAS ==\n\n";

	for (const Task& t : tasks)
	{
		if (t.getStatus())
			atual = "Finalizada";
		else
			atual = "Pendente";

		if(vol == 2 && t.getStatus())
			std::cout << "ID: " << t.getId() << " || Nome: " << t.getName() << " || Status: " << atual << "\n";
		else if (vol == 3 && !t.getStatus())
			std::cout << "ID: " << t.getId() << " || Nome: " << t.getName() << " || Status: " << atual << "\n";
		else if(vol == 1)
			std::cout << "ID: " << t.getId() << " || Nome: " << t.getName() << " || Status: " << atual << "\n";
	}

	std::cout << "" << std::endl;

}


//Salva as tarefas em arquivo .txt dado pelo caminho
void Manager::salvarTarefas(const std::string& cam)
{

	//Cria/sobrescrever o arquivo
	std::ofstream arq(cam);

	if (!arq)
		std::cout << "Erro ao abrir o arquivo em salvarTarefas" << std::endl;
	else
	{
		//Fiz separando por ; para facilitar a identificacao dos dados
		for (const Task& t : tasks)
			arq << t.getId() << ";" << t.getName() << ";" << t.getDesc() << ";" << t.getStatus() << "\n";
	}

	arq.close();
	std::cout << "Tarefas salvas!" << std::endl;


}

//Carrega dados de um .txt por meio de seu caminho; assim, coloca as tarefas dadas no gerenciador de tarefas
void Manager::carregarTarefas(const std::string& cam)
{
	//ler arquivo
	std::ifstream arq(cam);

	int iden;
	std::string n,d;
	bool stat;


	if (!arq)
		std::cout << "Erro ao abrir o arquivo em carregarDados" << std::endl;
	else
	{

		std::string linha;

		while (std::getline(arq, linha))
		{
			std::stringstream ss(linha);
			std::string parte;


			// le int ate o primeiro ';' -> id
			std::getline(ss, parte, ';');
			iden = std::stoi(parte);

			// le string ate o proximo ';' -> nome
			std::getline(ss, n, ';');

			// -> descricao
			std::getline(ss, d, ';');

			// le double ate o fim da linha
			std::getline(ss, parte, ';');
			stat = std::stoi(parte);


			//Inicializa a tarefa
			Task t1(iden, n,d, stat);

			//Coloca no gerenciador de tarefas
			tasks.push_back(t1);
		}
	}

	arq.close();
	std::cout << "Dados carregados!" << std::endl;

}
