/*
- Implementar print dos números na ordem que eles aparecem no vetor original

- Implementar print da posição original do número, além de suas duplicatas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 15

void preencher(int vetor[], int vet_aux[]);
void imprimir(int vetor[]);
void ordenar(int vetor[]);
void verificar(int vetor[], int vet_og[]);
void verificarPosicao(int vet_og[], int valor, int cont);

int main()
{
	int answer;
	int vetor[TAM];
	int vet_og[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(vetor, vet_og);
	
	printf("Vetor Sorteado = ");
	imprimir(vetor);
	
	ordenar(vetor);
	
	/*
	printf("\nVetor Ordenado = ");
	imprimir(vetor);
	*/
	
	printf("\n");
	
	verificar(vetor, vet_og);
	
	printf("\n");
	
	return 0;
}

void preencher(int vetor[], int vet_og[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = (rand() % 10) + 1 ;
		vet_og[i] = vetor[i];
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

void verificar(int vetor[], int vet_og[])
{
	int i = 0, j;
	int cont = 0;
	
	while(i < TAM)
	{
		while(1)
		{
			j = i + 1;
			
			if(vetor[i] == vetor[j])
			{
				cont++;
				i++;
			}
			else
				break;
		}
		
		if(cont != 0)
		{
			if(cont == 1)
			{
				printf("\nNúmero %i duplicado %i vez, na posição: ", vetor[i], cont);
				verificarPosicao(vet_og, vetor[i], cont);
			}
				
			else if(cont > 1)
			{
				printf("\nNúmero %i duplicado %i vezes, nas posições: ", vetor[i], cont);
				verificarPosicao(vet_og, vetor[i], cont);
			}
		}
		
		i++;	
		cont = 0;
	}	
}

void verificarPosicao(int vet_og[], int valor, int cont)
{
	int i;
	int temp = -1;
	
	for(i=0; i<TAM; i++)
	{
		if(vet_og[i] == valor)
		{
			temp++;
			
			if(temp > 0)
			{
				if(temp == cont)
					printf("%i.", i);
				else if(temp == cont-1)
					printf("%i e ", i);
				else
					printf("%i, ", i);
			}
		}
	}
}
