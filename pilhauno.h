#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <windows.h>
#define MAX_PILHA 109
#include "listaseuno.h"
#include "ArvoreAVL.h"

typedef struct{
    int topo;
    tp_item item[MAX_PILHA];
} tp_pilha;

// inicia uma pilha, atribuindo -1 ao topo
void inicializa_pilha(tp_pilha *p){
    p->topo = -1;
}

void cor_vermelho(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

void cor_amarelo(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
}

void cor_verde(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

void cor_azul(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

void cor_branco(){	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// vê se a pilha está vazia, retornando 1 se estiver vazia ou 0, caso contrário
int pilha_vazia(tp_pilha *p){
    if (p->topo == -1)
        return 1;
    return 0;
}

// vê se a pilha tá cheia, retornando 1 se estiver cheia ou 0, caso contrário
int pilha_cheia(tp_pilha *p){
    if (p->topo == MAX_PILHA - 1)
        return 1;
    return 0;
}

// Empilha um elemento
int push(tp_pilha *p, tp_item e){
    if (pilha_cheia(p))
        return 0;
    p->topo++;
    p->item[p->topo] = e;
    return 1;
}

// Desempilha um elemento
tp_item pop(tp_pilha *p){
	tp_item erro, e;
	erro.cor=5;
	erro.numero=15;	
	erro.acao=6;
    if (pilha_vazia(p))
        return erro;
    e = p->item[p->topo];
    p->topo--;
    return e;
}

// retorna o elemento que está no topo, sem desempilhar
tp_item top(tp_pilha *p){
	tp_item erro, e;
	erro.cor=5;
	erro.numero=15;	
	erro.acao=6;
    if (pilha_vazia(p))
        return erro;
    e = p->item[p->topo];
    return e;
}

int cava_dois(int jogada, int numjog, tp_pilha *cava, tp_listase *mao){
	int i;
	tp_item temp;
	for(i=0; i<2; i++){
	temp=pop(cava);
	
		insere_listase_no_fim(&mao, temp);		
	}
	return 1;
}

int cava_quatro(int jogada, int numjog, tp_pilha *cava, tp_listase *mao){
	int i;
	tp_item temp;
	for(i=0; i<4; i++){
	temp=pop(cava);
		insere_listase_no_fim(&mao, temp);		
	}
	return 1;
}

tp_item percorre_mao(int posic, tp_listase *mao){
	int cont=1;
	tp_listase *atu;
	atu=mao;
	while(cont!=posic){
		atu=atu->prox;
		cont++;
	}
	return atu->info;
}

int jogar_carta(tp_listase **lista, int posicao, tp_pilha *descarte, ArvAVL *arvore){
	tp_listase * ant, *atu;
	tp_item carta, temp;
	atu=*lista;
	int cont=1;
	ant=NULL;
	int novacor=5;
			temp=top(descarte);

			if(temp.cor==4){
				while(novacor>4||novacor<1){
			printf("Digite o número correspondente a cor que deseja escolher:\n");
			cor_azul();
			printf("1-Azul\n");
			cor_vermelho();
			printf("2-Vermelho\n");
			cor_amarelo();
			printf("3-Amarelo\n");
			cor_verde();
			printf("4-Verde\n");
			cor_branco();
			scanf(" %d", &novacor);
			if(novacor>4||novacor<1) printf("Cor Inválida\n");
			temp.cor=novacor-1;
		}
			
			}
			
	while(posicao!=cont){
		cont++;
		ant=atu;
		atu=atu->prox;
	}
	
	carta=top(descarte);

	if(atu->info.cor==carta.cor||atu->info.numero==carta.numero||atu->info.cor==4){
		if(atu->info.cor==4){
			while(novacor>4||novacor<1){
			printf("\nDigite o número correspondente a cor que deseja escolher:\n");
			cor_azul();
			printf("1-Azul\n");
			cor_vermelho();
			printf("2-Vermelho\n");
			cor_amarelo();
			printf("3-Amarelo\n");
			cor_verde();
			printf("4-Verde\n");
			cor_branco();
			scanf(" %d", &novacor);
			if(novacor>4||novacor<1) printf("Cor Inválida\n");
			atu->info.cor=novacor-1;
		}
		}
		
		push(descarte, atu->info);
		inserir(arvore, atu->info.numero);
			if(atu==NULL) return 0;
				if(ant==NULL){
				*lista=atu->prox;
				}
					else{
					ant->prox=atu->prox;
					}
	free(atu);
	atu=NULL;
	return 1;
}
return 0;
}


#endif