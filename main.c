#include <stdio.h>
#include <locale.h>
#include<time.h>//necessário p/ função time()
#include <stdlib.h>// necessário p/ as funções rand() e srand() e limpar terminal
#include <conio.h>//gecht(
#include <conio.h> //Cores

int frente(int campo[11][11]){
	int i, j;
	for(i=0;i<11;i++){
    	for(j=0;j<11;j++){
    		if(campo[i][j]==1){
    			if(i==0){
				}else{
    				campo[i-1][j]=1;
    				campo[i][j]=0;
   				}
			}
		}
	}
	return(campo[11][11]);				
}

int traz(int campo[11][11]){
	int i, j ,k;
	for(i=0,k=0;i<11;i++){
		for(j=0;k!=1&&j<11;j++){
			if(campo[i][j]==1){
				if(i==10){
				}else{
					campo[i+1][j]=1;
					campo[i][j]=0;
					k=1;
				}
			}
		}
	}
	return(campo[11][11]);
}

int direita(int campo[11][11]){
	int i, j, k;
	for(i=0,k=0;i<11;i++){
		for(j=0;j<11&&k!=1;j++){
			if(campo[i][j]==1){
				if(j==10){
				}else{
					campo[i][j+1]=1;
					campo[i][j]=0;
					k=1;
				}
			}
		}
	}
	return(campo[11][11]);
}

int esquerda(int campo[11][11]){
	int i, j;
		for(i=0;i<11;i++){
			for(j=0;j<11;j++){
				if(campo[i][j]==1){
					if(j==0){
					}else{
						campo[i][j-1]=1;
						campo[i][j]=0;
					}
				}
			}
		}
	return(campo[11][11]);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Numerar a Matirz
    int campo[11][11];
    int i, j, k, contador, pontuacao, jogadas;
    char l;
    for(i=0;i<11;i++){
    	for(j=0;j<11;j++){
    		campo[i][j]=0;
		}
	}
	//INCLUIR O OBJETIVO
	
	srand(time(NULL));
	i=rand() % 10;
	j=rand() % 10;
	campo[i][j]=2;
	
	//MENU PRINCIPAL
	do{
		printf("MENU PRINCIPAL:\n");
		printf("1-Iniciar\n");
		printf("2-Ajuda\n");
		scanf("%d", &i);
		system("cls"); //limpar terminal
	
		switch(i){
			case 1:{
				campo[5][5]=1;
				do{
					printf("Pontuação:%d	Jogadas:%d\n", pontuacao, jogadas);
					for(i=0;i<11;i++){
    					for(j=0;j<11;j++){
    						//textbackgroundcolor(1);
    						printf("%d", campo[i][j]);
    						printf(" ");
						}
    				printf("\n");
    				//Fazer a leitura do usuario
					}
				//scanf("%c", &l);
				l=getch(); //Para não precisar mais dar enter
				fflush(stdin);
				switch (l){
					//Funcionando
					case 'w': {
						frente(campo);
						jogadas=jogadas+1;
					break;
					}
					//Resolvido !!!
					case 's':{
						traz(campo);
						jogadas=jogadas+1;
					break;
					}
					//Resolvido
					case 'd':{
						direita(campo);
						jogadas=jogadas+1;
						break;
					}
					//Funcionando!!!
					case 'a':{
						esquerda(campo);
						jogadas=jogadas+1;
						break;
					}
				}
				for(i=0, contador=0;i<11;i++){
					for(j=0;j<11;j++){
						if(campo[i][j]!=0){
							contador=contador+1;
						}
					}
				}
				if(contador<2){
					srand(time(NULL));
					i=rand() % 10;
					j=rand() % 10;
					campo[i][j]=2;
					pontuacao=pontuacao+1;		
				}
				system("cls");
				}while(l!='f');
				break;
			}
			case 2:{
				system("cls");
				printf("Para se movimentar:\n");
				printf("'w'= para cima\n");
				printf("'s'= para baixo\n");
				printf("'a'= para esquerda\n");
				printf("'d'= para direita\n");
				printf("'f'- para sair\n");
				break;
			}
		}
	}while(i!=3);
	
	
}
