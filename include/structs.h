#ifndef STRUCTS_H
#define STRUCTS_H

#include "fila.h"
#include "pilha.h"

struct Conteiner {
	int tempoInsercao;
};

struct Empilhadeira {
	int tempoOcupada;
};

struct Slots { //bool pra gente fazer if(nav->conteudo){}
	Pilha<Conteiner> pilha[50];
};

template <int n>
struct FilasCaminhoes {
	Fila<bool> filaCaminhoes[n];
};

#endif
