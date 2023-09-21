// Exercício 06

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 5

void somar_matrizes(int matriz1[TAM][TAM], int matriz2[TAM][TAM]);

int main()
{
    int i, j ;
    int matriz1[TAM][TAM], matriz2[TAM][TAM] ;
    
    srand(time(NULL));
    
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            matriz1[i][j] = rand() % 21;
            matriz2[i][j] = rand() % 21;
        }
    }
    
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            printf("%2.1i ", matriz1[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
        for(j=0; j<TAM; j++)
        {
            printf("%2.1i ", matriz2[i][j]);
        }
        printf("\n");
    }
    
    somar_matrizes(matriz1, matriz2);
    
    return 0;
    for(i=0; i<TAM; i++)
    {
}

void somar_matrizes(int matriz1[TAM][TAM], int matriz2[TAM][TAM])
{
    int i, j ;
    int matriz3[TAM][TAM];
    
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j] ;
        }
    }
    
    printf("\n");
    
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            printf(" %2.i ", matriz3[i][j]);
        }
        printf("\n");
    }
}