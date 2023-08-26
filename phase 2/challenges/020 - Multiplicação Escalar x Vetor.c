/*
020 - Multiplicação Escalar x Vetor

Crie um procedimento que faça a multiplicação
de um escalar qualquer em um vetor de inteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

void preencher_vetor(int vetor[]);
void multiplicar_vetor(int vetor[], int escalar);
void imprimir_vetor(int vetor[]);

int main()
{
	int vetor[TAM] ;
	int escalar ;
	
	preencher_vetor(vetor);
	
	printf("Insira um número para multiplicar o vetor por: ");
	scanf("%i", &escalar);
	
	multiplicar_vetor(vetor, escalar);
	
	printf("\nVetor = [");
	
	imprimir_vetor(vetor);
	
	return 0;
}

void preencher_vetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
		vetor[i] = i+1 ;
}

void multiplicar_vetor(int vetor[], int escalar)
{
	int i ;
	
	for(i=0; i<TAM; i++)
		vetor[i] = escalar * vetor[i] ;
}

void imprimir_vetor(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i ", vetor[i]);
	}
}
