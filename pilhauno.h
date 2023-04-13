#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#define MAX_PILHA 109
typedef struct{
    int cor;
    int numero;
    int acao;	
} tp_item;

typedef struct{
    int topo;
    tp_item item[MAX_PILHA];
} tp_pilha;

// Inicia uma pilha, atribuindo -1 ao topo
void inicializa_pilha(tp_pilha *p){
    p->topo = -1;
}

// Vê se a pilha está vazia, retornando 1 se estiver vazia ou 0, caso contrário
int pilha_vazia(tp_pilha *p){
    if (p->topo == -1)
        return 1;
    return 0;
}

// Vê se a pilha está cheia, retornando 1 se estiver cheia ou 0, caso contrário
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
int pop(tp_pilha *p, tp_item *e){
    if (pilha_vazia(p))
        return 0;
    *e = p->item[p->topo];
    p->topo--;
    return 1;
}

// Retorna o elemento que está no topo, sem desempilhar
int top(tp_pilha *p, tp_item *e){
    if (pilha_vazia(p))
        return 0;
    *e = p->item[p->topo];
    return 1;
}

int altura_pilha(tp_pilha *p){
    return p->topo + 1;
}

void imprime_pilha(tp_pilha p){
    tp_item e;
    while (pilha_vazia(&p) == 0){
       top(&p, &e);
        printf("%d\n", e);
    }
}
int empilha_pilhas(tp_pilha *p1, tp_pilha *p2){
    tp_item e;
    tp_pilha paux;
    inicializa_pilha(&paux);
    if(altura_pilha(p1)+altura_pilha(p2) > MAX_PILHA) return 0;
    while (!pilha_vazia(p2)){
    pop(p2, &e);
    push(&paux, e);
    }
    while(!pilha_vazia(&paux)){
    pop(&paux, &e);
    push(p1, e);
    }
    return 1;
}

#endif
