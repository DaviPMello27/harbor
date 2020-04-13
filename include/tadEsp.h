#ifndef TADESP_H
#define TADESP_H

#include "structs.h"

void inicializaSlots(Slots &slots){
	for(int i = 0; i < 5; i++){
		slots.pilha[i].topo = NULL;
	}
}

bool insereContainer(Slots &slots){
	for(int numeroConteineres = 0; numeroConteineres < 6; numeroConteineres++){
		for(int slot = 0; slot < 5; slot++){
			if(retornaTamanho(slots.pilha[slot]) < numeroConteineres){
				push(slots.pilha[slot], {numeroConteineres});
				return true;
			}
		}
	}
	return false;
}

bool retiraConteiner(Slots &slots){
	for(int numeroConteineres = 1; numeroConteineres < 6; numeroConteineres++){
		for(int slot = 0; slot < 5; slot++){
			int tamanho = retornaTamanho(slots.pilha[slot]);
			if(0 < tamanho && tamanho < numeroConteineres){
				pop(slots.pilha[slot]);
				return true;
			}
		}
	}
	return false;
}

#endif