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

	Manager();

	void addTask(const std::string& nome, const std::string& descricao);

	bool removeTask(int identificacao);

	bool markComplete(int identificacao);

	void listTasks() const;

};