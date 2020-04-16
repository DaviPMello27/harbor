#ifndef TADESP_H
#define TADESP_H

#include "structs.h"

void inicializaSlots(Slots &slots){
	for(int i = 0; i < 500; i++){
		slots.pilha[i].topo = NULL;
	}
}

void inicializaEmpilhadeiras(Empilhadeira empilhadeiras[], Terminal terminal){
	for(int i = 0; i < terminal.quantidadeEmpilhadeiras; i++){
		empilhadeiras[i].tempoOcupada = 0;
		empilhadeiras[i].estado = Estado::DISPONIVEL;
	}
}

template <class type>
void inicializaCaminhoes(Fila<type> fila[], Terminal terminal){
	for(int i = 0; i < terminal.quantidadeFilas; i++){
		fila[i].primeiro = NULL;
	}
}

bool insereUmConteiner(Slots &slots, Empilhadeira &empilhadeira){
	for(int numeroConteineres = 0; numeroConteineres < 6; numeroConteineres++){
		for(int slot = 0; slot < 500; slot++){
			if(retornaTamanho(slots.pilha[slot]) < numeroConteineres){
				push(slots.pilha[slot], {numeroConteineres});
				empilhadeira.tempoOcupada = 1 + numeroConteineres;
				empilhadeira.estado = Estado::INSERINDO;
				//std::cout << "Inserindo no slot [" << slot << "] na altura " << numeroConteineres << ";\n";
				return true;
			}
		}
	}
	std::cerr << "Todos os slots estão ocupados.\n";
	return false;
}

bool removeUmConteiner(Slots &slots, int &conteineresArmazenados){
	for(int numeroConteineres = 1; numeroConteineres < 6; numeroConteineres++){
		for(int slot = 0; slot < 500; slot++){
			int tamanho = retornaTamanho(slots.pilha[slot]);
			if(0 < tamanho && tamanho < numeroConteineres){
				pop(slots.pilha[slot]);
				conteineresArmazenados--;
				return true;
			}
		}
	}
	return false;
}

void dTempoEmpilhadeiras(Empilhadeira empilhadeiras[], Fila<bool> caminhoes[], Terminal terminal){
	for(int i = 0; i < terminal.quantidadeEmpilhadeiras; i++){
		if(empilhadeiras[i].tempoOcupada){
			empilhadeiras[i].tempoOcupada--;
		}
		if(!empilhadeiras[i].tempoOcupada){
			if(empilhadeiras[i].estado == Estado::REMOVENDO){
				for(int fila = 0; fila < terminal.quantidadeFilas; fila++){
					if(retornaTamanho(caminhoes[fila])){
						if(!caminhoes[fila].primeiro->conteudo){
							dequeue(caminhoes[fila]);
							//std::cout << "Container Removido.\n";
						}
					}
				}
			} else if(empilhadeiras[i].estado == Estado::INSERINDO){
				//std::cout << "Container Inserido.\n";
			}
			empilhadeiras[i].estado = Estado::DISPONIVEL;
		}
	}
}

#endif