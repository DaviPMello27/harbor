#ifndef HARBOR_H
#define HARBOR_H

#include <iostream>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"

void solicitaEntradas(Terminal &terminal){
	std::cout << "Insira a quantidade de empilhaderias: ";
	std::cin >> terminal.quantidadeEmpilhadeiras;
	std::cout << "Insira a quantidade de filas para caminhoes: ";
	std::cin >> terminal.quantidadeFilas;
	std::cout << "Insira o modo de simulacao.\n";
	std::cout << "1 - Apresentar resultados ao final.\n";
	std::cout << "2 - Acompanhar simulacao em tempo real.\n";
	std::cin >> terminal.modoOperacao;
	terminal.modoOperacao--;
}

void insereContaineres(Slots &slots, Empilhadeira empilhadeiras[], Terminal &terminal){
	for(int i = 0; i < terminal.quantidadeEmpilhadeiras; i++){
		if(empilhadeiras[i].estado == Estado::DISPONIVEL && terminal.conteineresPendentes){
			if(insereUmConteiner(slots, empilhadeiras[i])){
				terminal.conteineresPendentes--;
				terminal.conteineresArmazenados++;
			}
		} else if(empilhadeiras[i].estado != Estado::DISPONIVEL){
			//std::cout << "Empilhadeira[" << i << "]: " << empilhadeiras[i].tempoOcupada << " min;\n";
		}
	}
}

void removeContainers(Slots &slots, Empilhadeira empilhadeiras[], Fila<bool> caminhoes[], Terminal &terminal){
	for(int i = 0; i < terminal.quantidadeFilas; i++){
		if(retornaTamanho(caminhoes[i]) > 0){
			for(int j = 0, caminhoesAtendidos = 0; j < terminal.quantidadeEmpilhadeiras; j++){
				if(terminal.conteineresArmazenados && empilhadeiras[j].estado == Estado::DISPONIVEL && retornaTamanho(caminhoes[i]) && caminhoes[i].primeiro->conteudo){
					//std::cout << "Removendo conteiner;\n";
					removeUmConteiner(slots, terminal.conteineresArmazenados);
					//dequeue(caminhoes[i]);
					caminhoes[i].primeiro->conteudo = false;
					empilhadeiras[j].estado = Estado::REMOVENDO;
					empilhadeiras[j].tempoOcupada = 2;
					caminhoesAtendidos++;
					break;
				}
			}
		}
	}
}

void adicionaCaminhoes(Fila<bool> caminhoes[], Terminal terminal){
	for(int i = 0; i < /*(rand() % 6) + */1; i++){  //Quantidade a ser colocada
		int k = 0;
		bool flag = false;
		while(flag == false){ //Altura atual
			for(int filaAtual = 0; filaAtual < terminal.quantidadeFilas; filaAtual++){	//Caminhão atual
				if(retornaTamanho(caminhoes[filaAtual]) < k || retornaTamanho(caminhoes[filaAtual]) == 0){
					queue(caminhoes[filaAtual], true);
					flag = true;
					break;
				}
			}
			k++;
		}
	}
}

#endif