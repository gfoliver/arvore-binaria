#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *inserir(Node *raiz, int novoValor){
    if(raiz == NULL)
        return criar(novoValor);

    if (novoValor < raiz->valor )
        raiz->esq = inserir(raiz->esq, novoValor);

    if (novoValor > raiz->valor )
        raiz->dir = inserir(raiz->dir, novoValor);

    return raiz;
}

Node *criar(int novoValor){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->valor = novoValor;
    temp->esq = temp->dir = NULL;
    return temp;
}


void inOrder(Node *raiz){
    if (raiz != NULL) {
        inOrder(raiz->esq);
        printf("%d\n", raiz->valor);
        inOrder(raiz->dir);
    }
}


void preOrder(Node *raiz){
	
	if(raiz != NULL){
		printf("%d\n", raiz->valor);
		preOrder(raiz->esq);
		preOrder(raiz->dir);
	}
}

void posOrder (Node *raiz){
	if(raiz !=NULL){
		posOrder(raiz->esq);
		posOrder(raiz->dir);
		printf("%d\n", raiz->valor);	
	}
	
}

Node *remover(Node *raiz, int valorDesejado){
	if(raiz == NULL){
		printf("Valor n�o encontrado! \n");
		return NULL;
		
	}else {
		// remove n�s folhas (n�s sem filhos)
		if(raiz->valor == valorDesejado){
			if(raiz->esq == NULL && raiz->dir == NULL){
				free(raiz);
				return NULL;
			}
			else{
				//remove n�s que possuem apenas um filho
				if(raiz->esq != NULL || raiz->dir != NULL){
					Node *aux;
					if(raiz->esq != NULL)
						aux = raiz->esq;
					else
						aux->dir;
					free(raiz);
					return aux;		
				}
			}
		}else {
			if(valorDesejado < raiz->valor)
				raiz->esq = remover(raiz->esq, valorDesejado);
			else
				raiz->dir = remover(raiz->dir, valorDesejado);
			return raiz;	
		}
	}
}	

Node *removerMaior(Node *raiz) {
	if(raiz == NULL){
		printf("Arvore vazia \n");
		return NULL;
	}

	Node *atual = raiz;
	int maior = 0;

	while (atual != NULL) {
		maior = atual->valor;
		atual = atual->dir;
	}

	remover(raiz, maior);

	return atual;
}