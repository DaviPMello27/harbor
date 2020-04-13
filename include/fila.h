#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "pilha.h"

template <class type>
struct Fila {
	TElemento<type>* primeiro;
};

template <class type>
void inicializaFila(Fila<type> &fila){
	fila.primeiro = NULL;
}

template <class type>
int retornaTamanho(Fila<type> &fila){
	TElemento<type>* nav = fila.primeiro;
	int i;
	for(i = 0; nav != NULL; nav = nav->proximo, i++){}
	return i;
}

template <class type>
bool estaContido(Fila<type> &fila, type elemento){
	for(TElemento<type>* nav = fila.primeiro; nav != NULL; nav = nav->proximo){
		if(nav->conteudo == elemento){
			return true;
		}
	}
	return false;
}

template <class type>
int retornaPosicao(Fila<type> &fila, type elemento){
	TElemento<type>* nav = fila.primeiro;
	for(int i = 0; nav != NULL; nav = nav->proximo, i++){
		if(nav->conteudo == elemento){
			return i;
		}
	}
	return -1;
}

template <class type>
TElemento<type>* retornaElemento(Fila<type> &fila, int pos){
	TElemento<type>* nav = fila.primeiro;
	for(int i = 0; nav != NULL; nav = nav->proximo, i++){
		if(i == pos){
			return nav;
		}
	}
	return NULL;
}

template <class type>
void queue(Fila<type> &fila, type elemento){
	TElemento<type>* novo = new TElemento<type>;
	novo->conteudo = elemento;
	novo->proximo = NULL;
	if(fila.primeiro == NULL){
		fila.primeiro = novo;
	} else {
		TElemento<type>* nav = fila.primeiro;
		while(nav->proximo != NULL){
			nav = nav->proximo;
		}
		nav->proximo = novo;
	}
}

template <class type>
TElemento<type>* dequeue(Fila<type> &fila){
	if(fila.primeiro == NULL){
		return NULL;
	} else {
		TElemento<type>* retorno = fila.primeiro;
		fila.primeiro = fila.primeiro->proximo;
		return retorno;
	}
}



template <class type>
void imprimeFila(Fila<type> &fila){
	if(fila.primeiro == NULL){
		std::cout << "Fila vazia.\n";
		return;
	} else {
		TElemento<type>* nav = fila.primeiro;
		int contador = 0;
		while(nav != NULL){
			std::cout << "Elemento[" << contador << "]: " << nav->conteudo << ", addr: " << nav << ", prox: " << nav->proximo << ";\n";
			nav = nav->proximo;
			contador++;
		}
		//---
		nav = fila.primeiro;
		while(nav->proximo != NULL){
			std::cout << nav->conteudo << ", ";
			nav = nav->proximo;
		}
		std::cout << nav->conteudo << ".\n";
	}
}
#endif