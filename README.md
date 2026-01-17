# 🗂️ Sistema de Gerenciamento de Tarefas

Projeto que implementa um gerenciador de tarefas via terminal, permitindo criar, listar, concluir, remover e salvar tarefas em arquivo de texto para persistência de dados.

## 📌 Funcionalidades

+ Adicionar novas tarefas (nome e descrição)

+ Listar tarefas:

  1) Todas

  2) Apenas finalizadas

  3) Apenas pendentes

+ Marcar tarefas como concluídas

+ Remover tarefas pelo ID

+ Salvar tarefas automaticamente em arquivo .txt

+ Carregar tarefas salvas ao iniciar o programa

## 🧠 Estrutura do Projeto

O projeto é dividido em três componentes principais:

1. 🔹 Task: Responsável por representar uma tarefa individual.

      -> Atributos principais / Verificação:

          id – Identificação única          getId()

          name – Nome da tarefa             getName()

          desc – Descrição                  getDesc()

          status – Pendente ou Finalizada   getStatus()


2. 🔹 Manager: Responsável por gerenciar todas as tarefas. Os dados são armazenados em um vetor de tarefas e mantidos no arquivo tarefas.txt.

      -> Responsabilidades:

          Adicionar tarefas

          Remover tarefas

          Marcar tarefas como concluídas

          Listar tarefas com filtros

          Salvar e carregar tarefas de arquivo



3. 🔹 Main: Interface de interação com o usuário via terminal. O programa apresenta um menu interativo com as opções disponíveis e executa as ações com base na escolha do usuário. Ao iniciar o programa, o arquivo é lido automaticamente, restaurando as tarefas salvas.

      -> Persistência de Dados: as tarefas são salvas no arquivo tarefas.txt no seguinte formato:

          id;nome;descricao;status

      Sendo 0 para Pendente e 1 para Finalizada, exemplo:

        1;Estudar C++;Revisar classes e objetos;0
        2;Trabalho de Algoritmos;Finalizar implementação;1

## ▶️ Como Compilar e Executar

Requisitos:

1) Compilador C++ compatível com C++11 ou superior

2) Terminal (Windows, Linux ou macOS)

### Compilação (exemplo com g++)

  + g++ main.cpp manager.cpp task.cpp -o gerenciador    
  + ./gerenciador

## 🚀 Possíveis Melhorias Futuras

Ⅰ. Interface gráfica (GUI)

ⅠⅠ. Prioridade das tarefas
