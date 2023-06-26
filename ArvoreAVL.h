#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoAvl* ArvAVL;

struct NoAvl{
   struct NoAvl *esq;
   int info;
   int alt; //altura da sub-árvore (facilita o cálculo do fator de balanceamento!)
   struct NoAvl *dir;
};

ArvAVL* criarAVL();
int inserir(ArvAVL* raiz, int valor);
int consultarValorAVL(ArvAVL* raiz, int valor);
int alt_NoAvl(struct NoAvl* no);
int fb_NoAvl(struct NoAvl* no);
int maior(int x, int y);
void RotacaoLL(ArvAVL* raiz);
void RotacaoRR(ArvAVL* raiz);
void RotacaoRL(ArvAVL* raiz);
void RotacaoLR(ArvAVL* raiz);

int contPrint=0;

ArvAVL* criarAVL(){
	ArvAVL* raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
	if(raiz!=NULL){
		*raiz = NULL;
	}
	return raiz;
}


int inserir(ArvAVL* raiz, int valor){	
	int res;
	if(*raiz==NULL){
		struct NoAvl* novo;
		novo = (struct NoAvl*)malloc(sizeof(struct NoAvl));
		if(novo==NULL) return 0;
		novo->info = valor;
		novo->alt = 0;
		novo->dir = NULL;
		novo->esq = NULL;
		*raiz = novo;
		return 1;	
	} else {
		struct NoAvl* atual = *raiz;
		if(valor < atual->info){
			if((res=inserir(&(atual->esq), valor))==1){
				if(fb_NoAvl(atual) >= 2){
					if(valor < (*raiz)->esq->info){
						RotacaoLL(raiz);
					}else{
						RotacaoLR(raiz);
					}
				}
			}
		}else{
			if(valor > atual->info){
				if((res=inserir(&(atual->dir), valor))==1){
					if(fb_NoAvl(atual) >= 2){
						if(valor > (*raiz)->dir->info){
							RotacaoRR(raiz);
						}else{
							RotacaoRL(raiz);
						}
					}
				}
			}else{
				return 0; // Valor Duplicado
			}
		}
		atual->alt = maior(alt_NoAvl(atual->esq), alt_NoAvl(atual->dir)) + 1;
		return res;
	} 
}


int consultarValorAVL(ArvAVL* raiz, int valor){
	if(raiz == NULL) return 0;
	if(*raiz == NULL) return 0;
	struct NoAvl* atual = *raiz;
	while(atual != NULL){
		if(atual->info == valor){
			return 1;
		}else{
			if(atual->info > valor){
				atual = atual->esq;
			}else{
				atual = atual->dir;
			}
		}
	}
	return 0;
}

int alt_NoAvl(struct NoAvl* no){
   if(no == NULL) return -1;
   else return no->alt;
}

int fb_NoAvl(struct NoAvl* no){
	int esq = alt_NoAvl(no->esq);
	int dir = alt_NoAvl(no->dir);
	return labs(esq - dir);
}

int maior(int x, int y){
	return (x>y)?x:y;
}

void RotacaoLL(ArvAVL* raiz){
   struct NoAvl* no;
   no = (*raiz)->esq;
   (*raiz)->esq = no->dir;
   no->dir = *raiz;
   (*raiz)->alt = maior(alt_NoAvl((*raiz)->esq), alt_NoAvl((*raiz)->dir)) + 1;
   no->alt = maior(alt_NoAvl(no->esq), (*raiz)->alt) + 1;
   *raiz = no;
}

void RotacaoRR(ArvAVL* raiz){
   struct NoAvl* no;
   no = (*raiz)->dir;
   (*raiz)->dir = no->esq;
   no->esq = *raiz;
   (*raiz)->alt = maior(alt_NoAvl((*raiz)->esq), alt_NoAvl((*raiz)->dir)) + 1;
   no->alt = maior(alt_NoAvl(no->dir), (*raiz)->alt) + 1;
   *raiz = no;
}

void RotacaoLR(ArvAVL* raiz){
	RotacaoRR(&(*raiz)->esq);
	RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL* raiz){
	RotacaoLL(&(*raiz)->dir);
	RotacaoRR(raiz);
}
