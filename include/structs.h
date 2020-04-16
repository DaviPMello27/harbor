#ifndef STRUCTS_H
#define STRUCTS_H

#include "fila.h"
#include "pilha.h"

struct Conteiner {
	int tempoInsercao;
};

struct Terminal{
	int conteineresPendentes;
	int conteineresArmazenados;
	int quantidadeEmpilhadeiras;
	int quantidadeFilas;
};

enum class Estado {
	DISPONIVEL,
	INSERINDO,
	REMOVENDO,
};

struct Empilhadeira {
	int tempoOcupada;
	Estado estado;
};

struct Slots {
	Pilha<Conteiner> pilha[500];
};

struct FilasCaminhoes {
	Fila<bool> fila;
};

#endif
