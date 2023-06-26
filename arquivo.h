#ifndef ARQUIVO_H
#define ARQUIVO_H
#define TAM_MAX 100
#include <stdio.h>
#include <string.h>
#include <locale.h>

int salvar_jogador(FILE *arq, char nomearq[], int quant, char jogador[][TAM_MAX]){
	int cont=1;
	char mensagem[1000];
	arq=fopen(nomearq, "w+");
	if(!arq) return 0;
	fputs("Jogadores\n", arq );
	for(int i=0; i<quant; i++){
	printf("Digite o nome do jogador %d: ", i + 1);
	scanf(" %[^\n]s", mensagem);
	strcpy(&jogador[i-1][TAM_MAX],  mensagem);
	fprintf(arq, "Jogador %d: ", cont);
	fprintf(arq, strcat(mensagem, "\n"));
	cont++;
	}
	fprintf(arq, "\nJogadas\n");
	fclose(arq);
	return 1;
}

	int vencedor(FILE *arq, char nomearq[], int quant, char jogador[][TAM_MAX], tp_listase *mao[], int fim){
		for(int k=0; k<quant; k++){
		fim=listase_vazia(mao[k]);
		if(fim==1){
		arq=fopen(nomearq, "a+");
		if(!arq) return 0;
		 printf("\nParabéns, %s você ganhou!!\n\n", jogador[k]);
		 fprintf(arq, "\nVencedor(a): %s", jogador[k]);
		 fclose(arq);
		 return 1;
		}
	}
return 0;
}
		
int salvar_jogada(FILE *arq, char nomearq[], int cont_jogada, tp_item temp, int posicao, char jogador[][TAM_MAX], int jogada, int quant){
	arq=fopen(nomearq, "a+");
	if(!arq) return 0;
	fprintf(arq, "%dº jogada: ",  cont_jogada);
	fprintf(arq, "%s", jogador[(jogada%quant)]);
	if(posicao==0){
		fprintf(arq, " cavou ");
	}
	if(posicao!=0)
	fprintf(arq, " jogou ");

	if(temp.numero<10)
		fprintf(arq, "%d ", temp.numero);
			else if(temp.numero==10)
			fprintf(arq, "Bloqueio ");
				else if(temp.numero==11)
				fprintf(arq, "Inverter ");
					else if(temp.numero==12)
					fprintf(arq, "+2 ");
						else if(temp.numero==13)
						fprintf(arq, "+4\n");
							else if(temp.numero==14)
							fprintf(arq, "Coringa\n");
		switch(temp.cor){
			case 0:
			fprintf(arq, "Azul\n");
			break;
				case 1:
				fprintf(arq, "Vermelho\n");
				break;
					case 2:
					fprintf(arq, "Amarelo\n");
					break;
						case 3:	
						fprintf(arq, "Verde\n");
						break;					 		
		}

	fclose(arq);
	return 1;
}


#endif