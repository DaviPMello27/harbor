#define SETE_DIAS 10080
#define SEIS_HORAS 360
#define QTD_EMPILHADEIRAS 2
#define QTD_FILAS_CAMINHOES 1

#include <iostream>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"
#include "harbor.h"


int main(){
	srand(time(NULL));

	Slots slots;
	inicializaSlots(slots);

	Empilhadeira empilhadeiras[QTD_EMPILHADEIRAS];
	inicializaEmpilhadeiras(empilhadeiras);

	Fila<bool> caminhoes[QTD_FILAS_CAMINHOES];
	inicializaCaminhoes(caminhoes);

	int conteineresPendentes = 0;
	int conteineresArmazenados = 0;
	for(int tempoAtual = 0; tempoAtual < SETE_DIAS; tempoAtual++){
		system("cls");
		std::cout << "Tempo Atual: " << tempoAtual <<".\n";
		
		if(tempoAtual % SEIS_HORAS == 0){
			conteineresPendentes += 200;
		}
		adicionaCaminhoes(caminhoes);

		if(conteineresPendentes){
			insereContaineres(slots, empilhadeiras, conteineresPendentes, conteineresArmazenados);
		}

		if(conteineresArmazenados){
			removeContainers(slots, empilhadeiras, caminhoes, conteineresArmazenados);
		}
	
		
		/*for(int i = 0; i < QTD_FILAS_CAMINHOES; i++){
			std::cout << "Existem " << retornaTamanho(caminhoes[i]) << " caminhoes na fila " << i;
			if(retornaTamanho(caminhoes[i])){
				std::cout << " (" << caminhoes[i].primeiro->conteudo << ").\n";
			} else {
				std::cout << "\n";
			}
		}*/

		dTempoEmpilhadeiras(empilhadeiras, caminhoes);
		std::cout << "Containers pendentes: " << conteineresPendentes << " / " << "Conteiners armazenados: " << conteineresArmazenados << "\n";
		//std::cout << "-----\n";
	}
}