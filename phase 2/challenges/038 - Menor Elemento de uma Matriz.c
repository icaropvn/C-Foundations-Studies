// Lista - Exerc�cio 12

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 3

void menu();
void preencher_manual(int matriz[TAM][TAM]);
void preencher_auto(int matriz[TAM][TAM]);
void imprimir(int matriz[TAM][TAM]);
int encontrar_menor(int matriz[TAM][TAM]);

int main()
{
	int matriz[TAM][TAM];
	int menor;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	menu(matriz);
	
	menor = encontrar_menor(matriz);
	printf("\nMenor Elemento = %i\n", menor);
	
	return 0;
}

void menu(int matriz[TAM][TAM])
{
	int answer;
	
	while(1)
	{
		printf("Como deseja preecnher a matriz?\n[1] - Manualmente\n[2] - Aleatoriamente\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				
				preencher_manual(matriz);
				printf("\n");
				imprimir(matriz);
				
				break;
			case 2:
				
				preencher_auto(matriz);
				printf("\n");
				imprimir(matriz);
				
				break;
			default:
				printf("\nResposta Inv�lida.\n\n");
		}
		
		if(answer == 1 || answer == 2)
			break;
	}
}

void preencher_manual(int matriz[TAM][TAM])
{
	int i, j;
	
	printf("\n");
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			printf("Elemento (%i, %i): ", i+1, j+1);
			scanf("%i", &matriz[i][j]);
		}
	}
}

void preencher_auto(int matriz[TAM][TAM])
{
	int i, j;
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			matriz[i][j] = rand() % 16 ;
		}
	}
}

void imprimir(int matriz[TAM][TAM])
{
	int i, j;
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(j == 0)
				printf("| %2.1i ", matriz[i][j]);
			else if(j == TAM-1)
				printf("%2.1i |", matriz[i][j]);
			else
				printf("%2.1i ", matriz[i][j]);
		}
		printf("\n");
	}
}

int encontrar_menor(int matriz[TAM][TAM])
{
	int i, j;
	int menor;
	
	for(i=0; i<TAM; i++)
	{
		for(j=0; j<TAM; j++)
		{
			if(i == 0 && j == 0)
				menor = matriz[i][j];
			else
			{
				if(matriz[i][j] < menor)
					menor = matriz[i][j];
			}
		}
	}
	
	return menor;
}
