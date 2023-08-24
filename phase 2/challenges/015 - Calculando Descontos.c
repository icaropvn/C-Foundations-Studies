/*
015 - Calculando Descontos

Escreva uma função que receba um valor de um produto e retorne o
valor com cálculo do desconto seguindo as seguintes regras:

a) valor entre 0 e 1000,00 5%;
b) valor entre 1000,01 e 2000,00, 10%;
c) acima de 2000,00, 15%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcular_desconto(float preco);

int main()
{
	float preco ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o preço do produto: R$");
	scanf("%f", &preco);
	
	calcular_desconto(preco);
}

float calcular_desconto(float preco)
{
	float preco_final ;
	
	if(preco <= 1000.00)
	{
		printf("Você recebeu 5% de desconto!");
		preco_final = preco * 0.95;
	}
}
