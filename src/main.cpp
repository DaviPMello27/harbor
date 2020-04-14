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
	Empilhadeira empilhadeiras[30];
	inicializaEmpilhadeiras(empilhadeiras);

	for(int tempoAtual = 0; tempoAtual < 10080; tempoAtual++){
		if(tempoAtual % SEIS_HORAS == 0){
			for(int i = 0; i < 20; i++){ //20 Containers
				insereContainer(slots, empilhadeiras);
			}
		}
		//insereContainer(slots, empilhadeiras);
		dTempoEmpilhadeiras(empilhadeiras);
		std::cout << "Tempo Atual: " << tempoAtual <<".\n";
		for(int i = 0; i < 5; i++){ //Imprime apenas os 5 primeiros slots
			std::cout << "[" << i << "]: " << retornaTamanho(slots.pilha[i]) << "\n";
		}
		std::cout << "-----\n";
		
	}
}