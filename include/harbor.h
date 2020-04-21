#ifndef HARBOR_H
#define HARBOR_H

#include <iostream>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"

//Entrada de parâmetros para a simulação.
void solicitaEntradas(Terminal &terminal){
	std::cout << "Insira a quantidade de empilhadeiras: ";
	std::cin >> terminal.quantidadeEmpilhadeiras;
	std::cout << "Insira a quantidade de filas para caminhoes: ";
	std::cin >> terminal.quantidadeFilas;
	std::cout << "Insira o modo de simulacao:\n";
	std::cout << "1 - Apresentar resultados ao final.\n";
	std::cout << "2 - Acompanhar simulacao em tempo real.\n";
	std::cin >> terminal.modoOperacao;
	terminal.modoOperacao--;
}

//Insere conteires recebidos pelos navios no porto.
void insereContaineres(Slots &slots, Empilhadeira empilhadeiras[], Terminal &terminal){
	for(int i = 0; i < terminal.quantidadeEmpilhadeiras; i++){
		if(empilhadeiras[i].estado == Estado::DISPONIVEL && terminal.conteineresPendentes){
			if(insereUmConteiner(slots, empilhadeiras[i])){
				terminal.conteineresPendentes--;
				terminal.conteineresArmazenados++;
			}
		}
	}
}

//Remove containers do pátio para os caminhões nas filas.
void removeContainers(Slots &slots, Empilhadeira empilhadeiras[], Fila<bool> caminhoes[], Terminal &terminal){
	for(int i = 0; i < terminal.quantidadeFilas; i++){
		if(retornaTamanho(caminhoes[i]) > 0){
			for(int j = 0, caminhoesAtendidos = 0; j < terminal.quantidadeEmpilhadeiras; j++){
				if(terminal.conteineresArmazenados && empilhadeiras[j].estado == Estado::DISPONIVEL && retornaTamanho(caminhoes[i]) && caminhoes[i].primeiro->conteudo){
					removeUmConteiner(slots, terminal.conteineresArmazenados);
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

//Chegada de caminhões ao porto, conforme enunciado da avaliação.
void adicionaCaminhoes(Fila<bool> caminhoes[], Terminal terminal){
	for(int i = 0; i < (rand() % 6) + 1; i++){  //Quantidade a ser colocada "i".
		int k = 0;
		bool flag = false;
		while(flag == false){ //Tamanho de fila atual "k".
			for(int filaAtual = 0; filaAtual < terminal.quantidadeFilas; filaAtual++){	//Fila atual.
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