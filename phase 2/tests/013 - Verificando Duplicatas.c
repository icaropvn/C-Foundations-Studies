#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 10

void preencher(int vetor[], int vet_aux[]);
void imprimir(int vetor[]);
void ordenar(int vetor[]);
void verificar(int vetor[]);

int main()
{
	int vetor[TAM];
	int vet_aux[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(vetor, vet_aux);
	
	printf("Vetor Sorteado = ");
	imprimir(vetor);
	
	ordenar(vetor);
	
	printf("\nVetor Ordenado = ");
	imprimir(vetor);
	
	printf("\n\n");

	verificar(vetor);
	
	return 0;
}

void preencher(int vetor[], int vet_aux[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = rand() % 11 ;
		vet_aux[i] = vetor[i];
	}
}

void imprimir(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == 0)
			printf("[%i, ", vetor[i]);
		else if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}

void ordenar(int vetor[])
{
	int i, j;
	int aux;
	
	for(i=0; i<TAM; i++)
	{
		for(j=i; j<TAM; j++)
		{
			if(vetor[j] < vetor[i])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

void verificar(int vetor[])
{
	int i = 0, j = 1;
	int cont = 0;
	
	while(i < TAM)
	{
		while(1)
		{
			if(vetor[i] != vetor[j])
				break;
			
			cont++;
			j++;
		}
		
		if(vetor[i] != vetor[j])
		{	
			i = j;
			j = i+1;
		}
		
		if(cont != 0)
			printf("\nNúmero %i duplicado %i vez(es)!", vetor[i], cont);
			
		cont = 0;
	}	
}	
