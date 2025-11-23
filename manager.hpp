#pragma once
#include "task.hpp"
#include <vector>

class Manager
{

private:

	//vetor que contem todas as tasks
	std::vector<Task> tasks;

	//proxima task a ser manuseada(?)
	int prox;


public:

	//Construtor -> inicializa a classe
	Manager();

	//adiciona a task
	void addTask(const std::string& nome, const std::string& descricao);

	//remove a task, se remover corretamente ->true, senao -> false
	bool removeTask(int identificacao);

	//marca como completa a task, se marcar corretamente ->true, senao -> false
	bool markComplete(int identificacao);

	//Lista as tasks de acordo com qual criterio selecionado
	void listTasks(int vol) const;

	//salva as tarefas em .txt
	void salvarTarefas(const std::string& cam);

	//carrega as tarefas de um .txt
	void carregarTarefas(const std::string& cam);

};