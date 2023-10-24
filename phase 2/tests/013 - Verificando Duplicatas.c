/*
- Implementar print dos números na ordem que eles aparecem no vetor original

- Implementar print formatado: "Número X duplicado X vez(es), na(s) posição(ões) X1, X2 e X3"
*/

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
	int answer;
	int vetor[TAM];
	int vet_aux[TAM];
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	preencher(vetor, vet_aux);
	
	printf("Vetor Sorteado = ");
	imprimir(vetor);
	
	ordenar(vetor);
	
	/*
	printf("\nVetor Ordenado = ");
	imprimir(vetor);
	*/
	
	printf("\n");
	
	verificar(vetor);
	
	printf("\n");
	
	return 0;
}

void preencher(int vetor[], int vet_aux[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = (rand() % 10) + 1 ;
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
	int i = 0, j;
	int posicao;
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
				posicao = i;
			}
			else
				break;
		}
		
		if(cont != 0)
		{
			if(cont == 1)
				printf("\nNúmero %i duplicado %i vez!", vetor[i], cont, posicao);
			else if(cont > 1)
				printf("\nNúmero %i duplicado %i vezes!", vetor[i], cont);
		}
		
		i++;	
		cont = 0;
	}	
}
