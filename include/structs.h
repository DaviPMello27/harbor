#ifndef STRUCTS_H
#define STRUCTS_H

#include "fila.h"
#include "pilha.h"

struct Conteiner {
	int tempoInsercao;				//Tempo para inserção do conteiner, baseado em sua altura.
};

struct Slots {
	Pilha<Conteiner> pilha[500];	 //Capacidade máxima de 500 slots de containeres.
};

struct Terminal {					//Variáveis de escopo para todo o terminal.
	int conteineresPendentes;		//Quantidade de conteiners a serem empilhados.
	int conteineresArmazenados;		//Quantidade total de conteiners armazenados.
	int quantidadeEmpilhadeiras;	//Quantidade de empilhadeiras fornecidas para a simulação.
	int quantidadeFilas;			//Quantidade de filas fornecidas para a simulação.
	int modoOperacao;				//Modo de simulação escolhido pelo usuário.
};

enum class Estado {					//Lista de estados para as empilhadeiras.
	DISPONIVEL,
	INSERINDO,
	REMOVENDO,
};

struct Empilhadeira {
	int tempoOcupada;				//Tempo até concluir a atividade sendo executada.
	Estado estado;					//Atividade sendo executada.
};

#endif
