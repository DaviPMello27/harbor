#ifndef HARBOR_H
#define HARBOR_H

#define QTD_EMPILHADEIRAS 50
#define QTD_FILAS_CAMINHOES 14

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
				if(conteineresArmazenados && empilhadeiras[j].estado == Estado::DISPONIVEL && retornaTamanho(caminhoes[i]) && caminhoesAtendidos < QTD_FILAS_CAMINHOES){
					//std::cout << "Removendo conteiner;\n";
					removeUmConteiner(slots, conteineresArmazenados);
					dequeue(caminhoes[i]);
					empilhadeiras[j].estado = Estado::REMOVENDO;
					empilhadeiras[j].tempoOcupada = 2;
					caminhoesAtendidos++;
				}
			}
		}
	}
}

void adicionaCaminhoes(Fila<bool> caminhoes[QTD_FILAS_CAMINHOES]){
	for(int i = 0; i < (rand() % 6) + 1; i++){  //Quantidade a ser colocada
		int k = 0; bool flag = false;
		while(k < retornaTamanho(caminhoes[0]) + 2 && flag == false){ //Altura atual
			for(int j = 0; j < QTD_FILAS_CAMINHOES; j++){	//Caminhão atual
				if(retornaTamanho(caminhoes[j]) < k || retornaTamanho(caminhoes[j]) == 0){
					queue(caminhoes[j], true);
					flag = true;
					break;
				}
			}
			k++;
		}
	}
}

#endif