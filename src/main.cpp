#define SETE_DIAS 10080
#define SEIS_HORAS 6 * 60

#include <iostream>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"


int main(){
	Slots slots;
	inicializaSlots(slots);

	for(int tempoAtual = 0; tempoAtual < 10080; tempoAtual++){
		if(tempoAtual % SEIS_HORAS == 0){
			for(int i = 0; i < 2; i++){
				if(!insereContainer(slots)){
					std::cout << "Capacidade do terminal esgotada!";
					return -1;
				}
			}
			for(int i = 0; i < 5; i++){
				std::cout << "[" << i << "]: " << retornaTamanho(slots.pilha[i]) << "\n";
			}
			std::cout << "-----\n";
		}
	}
}