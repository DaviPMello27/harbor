#define SETE_DIAS 10080
#define SEIS_HORAS 360

#include <iostream>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"

void insereContaineres(Slots &slots, Empilhadeira empilhadeiras[], int &conteineresPendentes, int &conteineresArmazenados){
	for(int i = 0; i < 30; i++){
		if(empilhadeiras[i].estado == Estado::DISPONIVEL && conteineresPendentes){
			if(insereUmConteiner(slots, empilhadeiras[i])){
				conteineresPendentes--;
				conteineresArmazenados++;
			}
		} else if(empilhadeiras[i].estado != Estado::DISPONIVEL){
			//std::cout << "Empilhadeira[" << i << "]: " << empilhadeiras[i].tempoOcupada << " min;\n";
		}
	}
}

void adicionaCaminhoes(Fila<bool> &fila){
	for(int i = 0; i < (rand() % 6) + 1; i++){
		queue(fila, true);
	}
}

int main(){
	srand(time(NULL));

	Slots slots;
	inicializaSlots(slots);

	Empilhadeira empilhadeiras[30];
	inicializaEmpilhadeiras(empilhadeiras);

	Fila<bool> caminhoes;
	inicializaFila(caminhoes);



	int conteineresPendentes = 0;
	int conteineresArmazenados = 0;
	for(int tempoAtual = 0; tempoAtual < SETE_DIAS; tempoAtual++){
		std::cout << "Tempo Atual: " << tempoAtual <<".\n";
		
		if(tempoAtual % SEIS_HORAS == 0){
			conteineresPendentes += 200;
		}
		adicionaCaminhoes(caminhoes);

		if(conteineresPendentes){
			insereContaineres(slots, empilhadeiras, conteineresPendentes, conteineresArmazenados);
		}
		if(retornaTamanho(caminhoes) > 0){
			for(int i = 0; i < 30; i++){
				if(conteineresArmazenados && empilhadeiras[i].estado == Estado::DISPONIVEL && retornaTamanho(caminhoes)){
					//std::cout << "Removendo conteiner;\n";
					removeUmConteiner(slots, conteineresArmazenados);
					dequeue(caminhoes);
					empilhadeiras[i].estado = Estado::REMOVENDO;
					empilhadeiras[i].tempoOcupada = 2;
				}
			}
		}

		dTempoEmpilhadeiras(empilhadeiras, caminhoes, slots, conteineresArmazenados);


		
		std::cout << "Existem " << retornaTamanho(caminhoes) << " caminhoes na fila.\n";
		std::cout << conteineresPendentes << "/" << conteineresArmazenados << "\n";
		std::cout << "-----\n";
	}
}