#ifndef STRUCTS_H
#define STRUCTS_H

#include "fila.h"
#include "pilha.h"

struct Conteiner {
	int tempoInsercao;
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
