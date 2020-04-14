#ifndef TADESP_H
#define TADESP_H

#include "structs.h"

void inicializaSlots(Slots &slots){
	for(int i = 0; i < 50; i++){
		slots.pilha[i].topo = NULL;
	}
}

void inicializaEmpilhadeiras(Empilhadeira empilhadeiras[30]){
	for(int i = 0; i < 30; i++){
		empilhadeiras[i].tempoOcupada = 0;
	}
}

bool insereContainer(Slots &slots,  Empilhadeira empilhadeiras[30]){
	for(int empilhadieraAtual = 0; empilhadieraAtual < 30; empilhadieraAtual++){
		if(empilhadeiras[empilhadieraAtual].tempoOcupada <= 0){
			for(int numeroConteineres = 0; numeroConteineres < 6; numeroConteineres++){
				for(int slot = 0; slot < 50; slot++){
					if(retornaTamanho(slots.pilha[slot]) < numeroConteineres){
						push(slots.pilha[slot], {numeroConteineres});
						empilhadeiras[empilhadieraAtual].tempoOcupada = 1 + numeroConteineres;
						std::cout << "Inserido container no slot [" << slot << "] na altura [" << numeroConteineres << "] pela empilhadeira [" << empilhadieraAtual << "].\n";
						return true;
					}
				}
			}
			std::cerr << "Todos os slots estão ocupados.\n";
			return false;
		}
	}
	std::cerr << "Todas as Empilhadeiras estão ocupadas.\n";
	return false;
}

void dTempoEmpilhadeiras(Empilhadeira empilhadeiras[30]){
	for(int i = 0; i < 30; i++){
		if(empilhadeiras[i].tempoOcupada){
			empilhadeiras[i].tempoOcupada--;
		}
	}
}
/*
bool insereContainer(Slots &slots){
	for(int numeroConteineres = 0; numeroConteineres < 6; numeroConteineres++){
		for(int slot = 0; slot < 500; slot++){
			if(retornaTamanho(slots.pilha[slot]) < numeroConteineres){
				push(slots.pilha[slot], {numeroConteineres});
				return true;
			}
		}
	}
	return false;
}
*/
bool retiraConteiner(Slots &slots){
	for(int numeroConteineres = 1; numeroConteineres < 6; numeroConteineres++){
		for(int slot = 0; slot < 500; slot++){
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