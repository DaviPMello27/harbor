#define SETE_DIAS 10080
#define SEIS_HORAS 360

#include <iostream>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"
#include "harbor.h"


int main(){
	srand(time(NULL));

	Terminal terminal = {0};
	solicitaEntradas(terminal);

	Slots slots;
	inicializaSlots(slots);

	Empilhadeira empilhadeiras[terminal.quantidadeEmpilhadeiras];
	inicializaEmpilhadeiras(empilhadeiras, terminal);

	Fila<bool> caminhoes[terminal.quantidadeFilas];
	inicializaCaminhoes(caminhoes, terminal);

	for(int tempoAtual = 0; tempoAtual < SETE_DIAS; tempoAtual++){
		
		if(tempoAtual % SEIS_HORAS == 0){
			terminal.conteineresPendentes += 200;
		}

		adicionaCaminhoes(caminhoes, terminal);

		if(terminal.conteineresPendentes){
			insereContaineres(slots, empilhadeiras, terminal);
		}

		if(terminal.conteineresArmazenados){
			removeContainers(slots, empilhadeiras, caminhoes, terminal);
		}

		dTempoEmpilhadeiras(empilhadeiras, caminhoes, terminal);

		if(terminal.modoOperacao){
			system("cls");
			std::cout << "Tempo Atual: " << tempoAtual <<".\n";
			std::cout << "Containers pendentes: " << terminal.conteineresPendentes << " / " << "Conteiners armazenados: " << terminal.conteineresArmazenados << "\n";
		}
	}
	system("cls");
	std::cout << "Simulacao encerrada.\t\t\t" << "Tempo Total: " << SETE_DIAS <<".\n";
	std::cout << "Restaram " << terminal.conteineresPendentes << " containers pendentes e " << terminal.conteineresArmazenados << " conteiners armazenados.\n";
	system("pause");
}