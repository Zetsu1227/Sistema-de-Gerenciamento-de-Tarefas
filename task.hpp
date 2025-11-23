#pragma once
#include <string>


class Task
{

private:

	//identificação da tarefa
	int id;

	//nome da tarefa
	std::string name;

	//descrição da tarefa
	std::string desc;

	//status atual. false->em andamento  e  true->finalizada
	bool status;


public:

	//Construtor da classe Task
	Task(int identificacao, const std::string& nome, const std::string& descricao, bool stat);

	//retorna a identificacao da tarefa
	int getId() const;

	//retorna o nome da tarefa
	std::string getName() const;
	
	//retorna a descricao da tarefa
	std::string getDesc() const;

	//retorna o status atual da tarefa
	bool getStatus() const;

	//Completa a task
	void taskCompleted();



};
