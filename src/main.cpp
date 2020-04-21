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
	//Declaração e inicialização de variáveis e estruturas.
	srand(time(NULL));

	//Terminal.
	Terminal terminal = {0};
	solicitaEntradas(terminal);
	Slots slots;
	inicializaSlots(slots);

	//Empilhadeiras.
	Empilhadeira empilhadeiras[terminal.quantidadeEmpilhadeiras];
	inicializaEmpilhadeiras(empilhadeiras, terminal);

	//Fila de caminhões.
	Fila<bool> caminhoes[terminal.quantidadeFilas];
	inicializaCaminhoes(caminhoes, terminal);

	//Loop principal com duração de sete dias, conforme proposto no enunciado da avaliação.
	for(int tempoAtual = 0; tempoAtual < SETE_DIAS; tempoAtual++){
		
		//Um navio chega a cada 6 horas no porto. 
		if(tempoAtual % SEIS_HORAS == 0){
			terminal.conteineresPendentes += 200;
		}
		//Adição de caminhões.
		adicionaCaminhoes(caminhoes, terminal);

		//Gerenciamento dos conteineres.
		if(terminal.conteineresPendentes){
			insereContaineres(slots, empilhadeiras, terminal);
		}
		if(terminal.conteineresArmazenados){
			removeContainers(slots, empilhadeiras, caminhoes, terminal);
		}

		//Gerenciamento tempo empilhadeiras.
		dTempoEmpilhadeiras(empilhadeiras, caminhoes, terminal);

		//Impressão de informações conforme modo de operação da simulação.
		if(terminal.modoOperacao){
			system("cls");
			std::cout << "Tempo Atual: " << tempoAtual <<".\n";
			std::cout << "Containers pendentes: " << terminal.conteineresPendentes << " / " << "Conteiners armazenados: " << terminal.conteineresArmazenados << "\n";
		}
	}
	//Impressão dos resultados da simulação.
	system("cls");
	std::cout << "Simulacao encerrada.\t\t\t" << "Tempo Total: " << SETE_DIAS <<".\n";
	std::cout << "Restaram " << terminal.conteineresPendentes << " containers pendentes e " << terminal.conteineresArmazenados << " conteiners armazenados.\n";
	system("pause");
}