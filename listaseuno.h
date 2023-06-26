#ifndef LISTASE_H
#define LISTASE_H
#include<stdio.h>
#include <stdlib.h>

typedef struct{
int cor;
int numero;
int acao;	
}tp_item;

typedef struct tp_no{
	tp_item info;
	struct tp_no *prox;
}tp_listase;
tp_listase * inicializa_listase(){
	return NULL;
}

int listase_vazia(tp_listase *lista){
	if(lista==NULL) return 1;
	return 0;
}

tp_listase * aloca_listase(){
	tp_listase *novo_no;
	novo_no=(tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

int insere_listase_no_fim(tp_listase **l, tp_item e){
	tp_listase *novo_no, *atu;
	novo_no=aloca_listase();
	if(novo_no==NULL) return 0;
	novo_no ->info=e;
	novo_no->prox=NULL;
	if(listase_vazia(*l)){
		*l=novo_no;
	}
	else{
		atu=*l;
		while(atu->prox!=NULL){
			atu=atu->prox;
		}
		atu->prox=novo_no; 
	}
	return 1;
}

	int tamanho_listase(tp_listase *lista){
		int cont=0;
		tp_listase *atu;
		atu=lista;
		while(atu!=NULL){
			cont++;
			atu=atu->prox;
		}
		return cont;
	}


		
#endif