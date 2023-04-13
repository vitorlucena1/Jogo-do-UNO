#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "pilhauno.h"
#define TAM_MAX 50

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

void printar(tp_item aux[109], tp_pilha monte, tp_item *p[109]){
	int i;
	for(i=1; i<109; i++){
    pop(&monte, p[i]);
    if(aux[i].numero<13){
    	if(aux[i].cor==0){
   		cor_azul();
   }  
   else if(aux[i].cor==1){
	cor_vermelho();
   }  
   else if(aux[i].cor==2){
   	cor_amarelo();
   }  
    else if(aux[i].cor==3){
    cor_verde();
   }
    if(aux[i].numero<10){   	 
   	printf(" %i ", aux[i].numero);
    }
    else if(aux[i].numero==10){	
      printf(" Bloqueio");
    }
    else if(aux[i].numero==11){
      printf(" Inverter");
    }
    else if(aux[i].numero==12){
      printf(" +2");
    }
   if(aux[i].cor==0){
     printf(" Azul\n");
   }  
   else if(aux[i].cor==1){
     printf(" Vermelho\n");
   }  
   else if(aux[i].cor==2){
     printf(" Amarelo\n");
   }  
    else if(aux[i].cor==3){
     printf(" Verde\n");
   }
    }
    else if(aux[i].numero==13){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  
    printf(" +4\n");
    }
     else if(aux[i].numero==14){
 	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);    	
    printf(" Coringa\n");
    }
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void imprime_nome(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("|");
		SetConsoleTextAttribute(hConsole,((FOREGROUND_BLUE)));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, ((FOREGROUND_BLUE)));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("|");
	printf("\n");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("|");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED ));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("J");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("O");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("G");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("O");
	printf(" ");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("D");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("O");
	printf(" ");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("U");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("N");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("O");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("*");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("|");
	printf("\n");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("|");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE));
	printf("-");
		SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
	printf("-");
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
	printf("|");
	printf("\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
}

int main(){
setlocale(LC_ALL, "Portuguese_Brazil");
tp_item card [109], aux[109], *p[109]; // sao 108 cartas no uno
int quant, i, cores, numeros, j, cont=5;
tp_pilha monte;
char jogador[5][TAM_MAX] = { '\0' };
imprime_nome();
printf("Seja Bem-vindo!\n\n");
printf("Podem jogar de 2 a 10 jogadores ou 1 jogador x computador\n");
printf("Digite a quantidade de jogadores: ");
      scanf(" %d", &quant);
              if(quant > 10 || quant <1){
               while(1){
                printf("Opção inválida \nDigite novamente: ");
                 scanf("%d", &quant);
                 if(quant > 0 && quant <= 10)
                   break;
              }
}
for (i=0; i<quant; i++){
    printf("Digite o nome do jogador %i: ", i + 1);
    scanf(" %[^\n]s", jogador[i]);

}          
          printf("\n");
          printf("Jogadores \n");
          for(i=0; i<quant; i++){
              printf("Jogador %i: %s\n", i+1, jogador[i]);
	}
        printf("\n");
  
card[0].cor='\0';
card[0].numero='\0';
card[0].acao='\0';
  for(i=1; i<5; i++){ //cria as cartas 0
      card[i].cor=i-1;
      card[i].numero=0;
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

  for(i=101; i<109; i++){
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
 
  embaralhar(card);
  inicializa_pilha(&monte);
  for(i=1; i<109; i++){
   push(&monte, card[i]);
   p[i]=&aux[i];
}
  printf("Monte:\n");
  printar(aux, monte, p);
  return 0;
}
