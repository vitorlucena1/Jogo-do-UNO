#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "pilhauno.h"
#include "arquivo.h"
#define TAM_MAX 100
#define MAX_JOGADORES 4
#define NUM_CARTAS 108
#include <locale.h>

//#include"ArvoreAVL.h">
    // 0 - Azul, 1 - vermelho, 2 - Amarelo, 3 - Verde, 4 - preto.
 // 0 - 9, 10-Pular, 11-inverter, 12-+2, 13-+4, 14-Coringa.
//0 - nenhuma, 1 - pular, 2 - inverter, 3 - +2, 4 - +4, 5 - Coringa
void embaralhar(tp_item deck[109]){
  int j, troca=0, i=0;
  srand(time(NULL));
  for (i=0;i<109;i++){
      j = (rand()%109);
      deck[troca] = deck[i];
      deck[i] = deck[j];
      deck[j] = deck[troca];
   }

}


void printar_mao(tp_listase *mao){
	int cont=1;
	tp_listase *atu;
	atu=mao;
	while(atu!=NULL){
			switch(atu->info.cor){
			case 0:
			cor_azul();
			break;
				case 1:
				cor_vermelho();
				break;
					case 2:
					cor_amarelo();
					break;
						case 3:
						cor_verde();
						break;		
							case 4:
							cor_branco();
							break;
								
		}
		
		if(atu->info.numero<10)
		printf(" %d ", atu->info.numero);
			else if(atu->info.numero==10)
			printf(" Bloqueio ");
				else if(atu->info.numero==11)
				printf(" Inverter ");
					else if(atu->info.numero==12)
					printf("+2 ");
						else if(atu->info.numero==13)
						printf("+4");
							else if(atu->info.numero==14)
							printf("Coringa");
		switch(atu->info.cor){
			case 0:
			printf("Azul");
			break;
				case 1:
				printf("Vermelho");
				break;
					case 2:
					printf("Amarelo");
					break;
						case 3:	
						printf("Verde");
						break;					 		
		}
		printf(" [%d]\n", cont);
		cont++;
		atu=atu->prox;
	}
	cor_branco();
}

int inverter(int a){
	a=a*-1;
	return a;
}

int main(){
setlocale(LC_ALL, "Portuguese_Brazil");
tp_item card [109]; // sao 108 cartas no uno
int quant, i, cores, numeros, j, cont, posicao, teste, fim=0, passa=1, cont_jogada=1, resp, cor_buscada, num_buscado=15;
tp_pilha *monte, *descarte;
ArvAVL *arv_verm=criarAVL(), *arv_amar=criarAVL(), *arv_azul=criarAVL(), *arv_verd=criarAVL(), *arv_pret=criarAVL();
monte=(tp_pilha*)malloc(sizeof(tp_pilha));
descarte=(tp_pilha*) malloc(sizeof(tp_pilha));
FILE *arq;

char jogador[5][TAM_MAX] = { '\0' };
cont=5;
char imprime_nome[] = "|---------------------------|\n|********JOGO DO UNO********|\n|---------------------------|\n";
printf("%s", imprime_nome);
printf("Seja Bem-Vindo!\n\nDigite a quantidade de jogadores: ");
      scanf(" %d", &quant);
      tp_listase *mao[quant];
              if(quant > 4 || quant <2){
               while(1){
                printf("Opção inválida \nDigite novamente: ");
                 scanf("%d", &quant);
                 if(quant > 1 && quant <= 4)
                   break;
              }
}

int jogada=quant*10000;

	salvar_jogador(arq, "uno.txt", quant, jogador); 
	   	      
	printf("\nBoa sorte aos jogadores: ");
	for (int i = 0; i < quant; i++){
		printf("%s",jogador[i]);
		if (i + 1 == quant)
			break;
		printf(", ");
	}
	printf("!\n\n");
	
	Sleep(2000);
	system("cls");
  
card[0].cor='\0';
card[0].numero='\0';
card[0].acao='\0';
  for(i=1; i<5; i++){ //cria as cartas 0
      card[i].cor=i-1;
      card[i].numero=0;
      card[i].acao=0;
  }

    for(j=0; j<2; j++){ //cria duas cópias da carta
      for(numeros=1; numeros<13; numeros++){
        for(cores=0; cores<4; cores++){
      card[cont].cor=cores;
      card[cont].numero=numeros;
          if(card[cont].numero>9){
            card[cont].acao=card[cont].numero%9;
          }
          else{
            card[cont].acao=0;
          }
       cont++;
        }
      }
    }

  for(i=101; i<109; i++){//criação das cartas especiais
    card[i].cor=4;
  }

  for(i=101; i<105; i++){
    card[i].acao=4;
    card[i].numero=13;
  }

  for(i=105; i<109; i++){
    card[i].acao=5;
    card[i].numero=14;
  }
 
 for(i=0; i<14; i++){ // embaralhar melhor(segundo estudos, pra embaralhar um baralho de 54 cartas, é necessário 7 embaralhamentos)
  embaralhar(card);
}

  inicializa_pilha(descarte);
  inicializa_pilha(monte);
  
  for(i=1; i<109; i++){
   push(monte, card[i]);
}

tp_item temp, confere, selec_arv;
for(i=0; i<quant; i++){//insere as cartas já embaralhadas nas mãos dos jogadores (7 cartas)
	mao[i]=inicializa_listase();
	for(j=0; j<7; j++){
	temp=pop(monte);
	insere_listase_no_fim(&mao[i], temp);
	}
}

while(fim==0){
	printf("%s",imprime_nome);
	if(!pilha_vazia(descarte)){	
	printf("\nÉ a vez do Jogador: %s\nPressione ENTER quando estiver pronto.\n", jogador[jogada%quant]);
	fflush(stdin);
	getchar();
}
	if(pilha_vazia(descarte)){
		temp=pop(monte);
			switch(temp.cor){
		case(0):
			inserir(arv_azul, temp.numero);
			break;
				case(1):
				inserir(arv_verm, temp.numero);
				break;
					case(2):
					inserir(arv_amar, temp.numero);
					break;
						case(3):
						inserir(arv_verd, temp.numero);
						break;
							case(4):
							inserir(arv_pret, temp.numero);
							break;
	}
	
		if(temp.numero==14) printf("Coringa\n");
		if(temp.numero==13) printf("+4\n");
		switch(temp.acao){
			case(0):
				break;
				case(1):
					jogada++;
					break;
					case(2):
						passa=passa*-1;
						break;
						case(3):
							cava_dois(jogada, quant, monte, mao[((jogada)%quant)]);
							break;
							case(4):
								cava_quatro(jogada, quant, monte, mao[((jogada)%quant)]);
								break;
									
		}
		int novacor=5;
	if(temp.cor==4){
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
	}	
	push(descarte, temp);
	printf("\nÉ a vez do Jogador: %s\nPressione ENTER quando estiver pronto.\n", jogador[jogada%quant]);
	fflush(stdin);
	getchar();

}
	
	temp=top(descarte);
	switch(temp.cor){
			case 0:
			cor_azul();
			break;
				case 1:
				cor_vermelho();
				break;
					case 2:
					cor_amarelo();
					break;
						case 3:
						cor_verde();
						break;		
							case 4:
							cor_branco();
							break;
								
		}
		if(temp.numero<10)
		printf(" %d ", temp.numero);
			else if(temp.numero==10)
			printf(" Bloqueio ");
				else if(temp.numero==11)
				printf("Inverter ");
					else if(temp.numero==12)
					printf("+2 ");
						else if(temp.numero==13)
						printf("+4 ");
							else if(temp.numero==14)
							printf("Coringa ");
		switch(temp.cor){
			case 0:
			printf("Azul\n");
			break;
				case 1:
				printf("Vermelho\n");
				break;
					case 2:
					printf("Amarelo\n");
					break;
						case 3:	
						printf("Verde\n");
						break;					 		
		}
	cor_branco();
	
	printf("\nMão do Jogador %s\n", jogador[jogada%quant]);
	printar_mao(mao[jogada%quant]);
	teste=0;
	while(teste==0){
	
	printf("Digite a posição da carta que deseja jogar. Caso deseje comprar uma carta, digite 0. Caso deseje buscar uma carta, digite %d: \n", tamanho_listase(mao[jogada%quant])+1);
	scanf(" %d", &posicao);
	
		if(posicao==0){
		temp=pop(monte);
		insere_listase_no_fim(&mao[jogada%quant], temp);
		salvar_jogada(arq, "uno.txt", cont_jogada, temp, posicao, jogador, jogada, quant);
		cont_jogada++; 
		jogada+=passa;
		teste=1;
		}
		resp=posicao;
			while(resp==tamanho_listase(mao[jogada%quant])+1){
			printf("Digite o número correspondente a cor da carta que deseja buscar:\n");
			cor_azul();
			printf("1-Azul\n");
			cor_vermelho();
			printf("2-Vermelho\n");
			cor_amarelo();
			printf("3-Amarelo\n");
			cor_verde();
			printf("4-Verde\n");
			cor_branco();
			printf("5-Coringa/+4\n");
			scanf(" %d", &cor_buscada);
			if(cor_buscada>0&&cor_buscada<6){
				num_buscado=15;	
			if(cor_buscada!=5){
			
			while(num_buscado>12||num_buscado<0){
			printf("Escolha a carta que deseja consultar: \n0-Número 0\n1-Número 1\n2-Número 2\n3-Número 3\n4-Número 4\n5-Número 5\n6-Número 6\n7-Número 7\n8-Número 8\n9-Número 9\n10-Bloqueio\n11-Inverter\n12-+2\n");
			scanf(" %d", &num_buscado);
			if(num_buscado>12||num_buscado<0) printf("Resposta Inválida\n");
			else{
			switch(cor_buscada){
				case(1):
				if(consultarValorAVL(arv_azul, num_buscado)) printf("A carta já foi jogada.\n");
				else printf("A carta não foi jogada\n");
				break;
					case(2):
					if(consultarValorAVL(arv_verm, num_buscado)) printf("A carta já foi jogada.\n");
					else printf("A carta não foi jogada\n");
					break;
						case(3):
						if(consultarValorAVL(arv_amar, num_buscado)) printf("A carta já foi jogada.\n");
						else printf("A carta não foi jogada\n");
						break;
							case(4):
							if(consultarValorAVL(arv_verd, num_buscado)) printf("A carta já foi jogada.\n");
							else printf("A carta não foi jogada\n");
							break;
						}
					}
					}
			}
			else{
			while(num_buscado<13||num_buscado>14){
			printf("Digite uma opção:\n1-Coringa\n2-+4\n");
			scanf(" %d", &num_buscado);
			if(num_buscado==1) num_buscado=14;
		    if(num_buscado==2) num_buscado=13;
		    if(num_buscado==13||num_buscado==14){
			if(consultarValorAVL(arv_pret, num_buscado)) printf("A carta já foi jogada.\n");
					else printf("A carta não foi jogada\n");
				
				}
				
				else printf("Escolha inválida\n");
	}
			}
			printf("Caso deseje procurar outra carta, digite 1, caso queira jogar, digite outro número\n");
			scanf(" %d", &resp);
			if(resp==1) resp=posicao;
			else resp=0;
}	
else {
	printf("Resposta inválida\n");
	Sleep(1000);
}
	system("cls");
	printf("%s", imprime_nome);
	temp=top(descarte);
		printf("\nÉ a vez do Jogador: %s\nPressione ENTER quando estiver pronto.\n", jogador[jogada%quant]);
		fflush(stdin);
		getchar();
	switch(temp.cor){
			case 0:
			cor_azul();
			break;
				case 1:
				cor_vermelho();
				break;
					case 2:
					cor_amarelo();
					break;
						case 3:
						cor_verde();
						break;		
							case 4:
							cor_branco();
							break;
								
		}
		if(temp.numero<10)
		printf(" %d ", temp.numero);
			else if(temp.numero==10)
			printf(" Bloqueio ");
				else if(temp.numero==11)
				printf("Inverter ");
					else if(temp.numero==12)
					printf("+2 ");
						else if(temp.numero==13)
						printf("+4 ");
							else if(temp.numero==14)
							printf("Coringa ");
		switch(temp.cor){
			case 0:
			printf("Azul\n");
			break;
				case 1:
				printf("Vermelho\n");
				break;
					case 2:
					printf("Amarelo\n");
					break;
						case 3:	
						printf("Verde\n");
						break;					 		
		}
	cor_branco();
	printf("\nMão do Jogador %s\n", jogador[jogada%quant]);	
	printar_mao(mao[jogada%quant]);
	}
		int tam_mao=tamanho_listase(mao[jogada%quant]);
		if(posicao>0&&posicao<=tam_mao){
		temp=percorre_mao(posicao, mao[jogada%quant]);	
		confere=top(descarte);
	}
		if(posicao<=tamanho_listase(mao[jogada%quant])&&(temp.cor==confere.cor||temp.numero==confere.numero||temp.cor==4)&&posicao>0&&posicao<=tam_mao){
		selec_arv=percorre_mao(posicao, mao[jogada%quant]);
		switch(selec_arv.cor){
			case(0):
			teste=jogar_carta(&mao[jogada%quant], posicao, descarte, arv_azul);	
			break;
				case(1):
				teste=jogar_carta(&mao[jogada%quant], posicao, descarte, arv_verm);
				break;
					case(2):
					teste=jogar_carta(&mao[jogada%quant], posicao, descarte, arv_amar);
					break;
						case(3):
						teste=jogar_carta(&mao[jogada%quant], posicao, descarte, arv_verd);	
						break;
							case(4):
							teste=jogar_carta(&mao[jogada%quant], posicao, descarte, arv_pret);
							break;					  		
		}
		salvar_jogada(arq, "uno.txt", cont_jogada, temp, posicao, jogador, jogada, quant);
		cont_jogada++;
		if(temp.acao==3) cava_dois(jogada, quant, monte, mao[((jogada+passa)%quant)]);
	    if(temp.acao==4) cava_quatro(jogada, quant, monte, mao[((jogada+passa)%quant)]);
		if(temp.acao==2){
		 passa=inverter(passa);
		 jogada+=passa;
		}
			else if(temp.acao==1) jogada+=2*passa;
				else jogada+=passa;
			}
			else if (posicao!=0&&posicao!=tam_mao+1) printf("Jogada Inválida\n");
			
		fim=vencedor(arq, "uno.txt", quant, jogador, mao, fim);
	
}

	if(fim!=1){
	Sleep(500);
	system("cls");
	}
}
free(monte);
free(descarte);
system("pause");
return 0;
}