#ifndef HARBOR_H
#define HARBOR_H

#define QTD_EMPILHADEIRAS 2
#define QTD_FILAS_CAMINHOES 1

#include <iostream>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#include "tadEsp.h"
#include "structs.h"

//Enviar um cerr quando todas empilhadeiras estiverem ocupadas *Douglas
void insereContaineres(Slots &slots, Empilhadeira empilhadeiras[], int &conteineresPendentes, int &conteineresArmazenados){
	for(int i = 0; i < QTD_EMPILHADEIRAS; i++){
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

void removeContainers(Slots &slots, Empilhadeira empilhadeiras[], Fila<bool> caminhoes[QTD_FILAS_CAMINHOES], int &conteineresArmazenados){
	for(int i = 0; i < QTD_FILAS_CAMINHOES; i++){
		if(retornaTamanho(caminhoes[i]) > 0){
			for(int j = 0, caminhoesAtendidos = 0; j < QTD_EMPILHADEIRAS; j++){
				if(conteineresArmazenados && empilhadeiras[j].estado == Estado::DISPONIVEL && retornaTamanho(caminhoes[i]) && caminhoes[i].primeiro->conteudo){
					std::cout << "Removendo conteiner;\n";
					removeUmConteiner(slots, conteineresArmazenados);
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

void adicionaCaminhoes(Fila<bool> caminhoes[]){
	for(int i = 0; i < /*(rand() % 6) + */1; i++){  //Quantidade a ser colocada
		int k = 0;
		bool flag = false;
		while(flag == false){ //Altura atual
			for(int filaAtual = 0; filaAtual < QTD_FILAS_CAMINHOES; filaAtual++){	//Caminhão atual
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