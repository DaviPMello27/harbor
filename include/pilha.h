#ifndef PILHA_H
#define PILHA_H

#include <iostream>

template <class type>
struct TElemento {
	type conteudo;
	TElemento<type>* proximo;
};

template <class type>
struct Pilha {
	TElemento<type>* topo;
};

template <class type>
void inicializaPilha(Pilha<type> &pilha){
	pilha.topo = NULL;
}

template <class type>
int retornaTamanho(Pilha<type> &pilha){
	TElemento<type>* nav = pilha.topo;
	int i;
	for(i = 0; nav != NULL; nav = nav->proximo, i++){}
	return i;
}

template <class type>
bool estaContido(Pilha<type> &pilha, type elemento){
	for(TElemento<type>* nav = pilha.topo; nav != NULL; nav = nav->proximo){
		if(nav->conteudo == elemento){
			return true;
		}
	}
	return false;
}

template <class type>
int retornaPosicao(Pilha<type> &pilha, type elemento){
	TElemento<type>* nav = pilha.topo;
	for(int i = 0; nav != NULL; nav = nav->proximo, i++){
		if(nav->conteudo == elemento){
			return i;
		}
	}
	return -1;
}

template <class type>
TElemento<type>* retornaElemento(Pilha<type> &pilha, int pos){
	TElemento<type>* nav = pilha.topo;
	for(int i = 0; nav != NULL; nav = nav->proximo, i++){
		if(i == pos){
			return nav;
		}
	}
	return NULL;
}

template <class type>
void push(Pilha<type> &pilha, type elemento){
	TElemento<type>* novo = new TElemento<type>;
	novo->conteudo = elemento;
	if(pilha.topo == NULL){
		pilha.topo = novo;
		novo->proximo = NULL;
	} else {
		novo->proximo = pilha.topo;
		pilha.topo = novo;
	}
}

template <class type>
bool pop(Pilha<type> &pilha){
	if(pilha.topo == NULL){
		return false;
	} else {
		TElemento<type>* segundo = pilha.topo->proximo;
		delete pilha.topo;
		pilha.topo = segundo;
		return true;
	}
}

template<class type>
void imprimePilha(Pilha<type> &pilha){
	if(pilha.topo == NULL){
		std::cout << "Pilha vazia.\n";
	} else {
		TElemento<type>* nav = pilha.topo;
		int contador = 0;
		while(nav != NULL){
			std::cout << "Elemento[" << contador << "]: val: " << nav->conteudo << ", addr: " << nav << ", prox: " << nav->proximo << ";\n";
			contador++;
			nav = nav->proximo;
		}
	}
}

#endif
