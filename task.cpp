#include "task.hpp"

Task::Task(int identificacao, const std::string& nome, const std::string& descricao)
{
	
	id = identificacao;

	name = nome;

	desc = descricao;

	//por padrao nao vai estar completo
	status = false;

}

int Task::getId() const
{
	return id;
}

std::string Task::getDesc() const
{
	return desc;
}

std::string Task::getName() const
{
	return desc;
}

bool Task::getStatus() const
{
	return status;
}

void Task::taskCompleted()
{
	status = true;
}
