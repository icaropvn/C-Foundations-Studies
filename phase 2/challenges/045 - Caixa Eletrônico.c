// Algoritmo de simulação de um Caixa Eletrônico

// colocar sistema de cadastramento inicial
// colocar sistema de login com senha (personalizar de acordo com o usuario)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void menu(float saldo);
void sacar(float *saldo);
void definir_cedulas(int saque);
int confirmar_transacao(int valor);

int main()
{
	float saldo;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	saldo = (rand() % 5000) + ((float)(rand() % 100) / 100);
	
	menu(saldo);
	
	return 0;
}

void menu(float saldo)
{
	char answer;
	
	while(answer != 'D' && answer != 'd')
	{
		printf("Bem-Vindo [NOME DO USUARIO]!\nO que deseja fazer hoje?\n");
		printf("[A] Sacar\n[B] Depositar\n[C] Verificar Saldo\n[D] Sair\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a')
		{
			sacar(&saldo);
		}
		else if(answer == 'B' || answer == 'b')
		{
			
		}
	}
}

void sacar(float *saldo)
{
	char answer;
	int saque;
	
	printf("------------------------------------------\n");
	printf("[A] - Digitar Valor para Sacar\n[B] - Voltar para o Menu\nR: ");
	scanf(" %c", &answer);
	
	printf("------------------------------------------\n");
	
	if(answer == 'A' || answer == 'a')
	{
		printf("Notas disponíveis hoje: [colocar data do dia de hoje]\n");
		printf("[randomizar notas disponiveis]\n - R$200,00\n - R$100,00\n - R$50,00\n - R$20,00\n - R$10,00\n - R$5,00\n\n");
		
		printf("Saldo Atual: R$%.2f\n", *saldo);
		printf("Digite o valor desejado para sacar: R$");
		scanf("%i", &saque);
		
		if(saque < *saldo)
		{
			printf("------------------------------------------\n");
			printf("Você receberá:\n");
			definir_cedulas(saque);
			
			if(confirmar_transacao(saque))
			{
				*saldo -= saque;
				printf("Saque realizado com sucesso! Retire as cédulas ao lado.");
			}
			else
				printf("\nOperação Cancelada.\n");
		}
	}
	else if(answer == 'B' || answer == 'b')
	{
		
	}
}

void definir_cedulas(int saque)
{
	int i;
	int cont;
	int notas[4] = {100, 50, 20, 10};
	int quant_notas[4] = {0, 0, 0, 0};
	
	for(i=0; i<4; i++)
	{
		if(saque >= notas[i])
		{
			cont = i;
			break;
		}
	}
		
	while(cont <= 3 && saque > 0)
	{		
		quant_notas[cont] = saque / notas[cont] ;
		saque = saque % notas[cont] ;
		cont++ ;
	}
	
	for(i=0; i<4; i++)
	{
		if(quant_notas[i] > 1)
			printf("%i Notas de R$%i,00\n", quant_notas[i], notas[i]);
		else if(quant_notas[i] == 1)
			printf("%i Nota de R$%i,00\n", quant_notas[i], notas[i]);
	}
		
	for(i=0; i<4; i++)
	{
		quant_notas[i] = 0;
	}
}

int confirmar_transacao(int valor)
{
	char answer;
	
	printf("Confirmar Transação?\n");
	printf("[A] Confirmar\n[B] Cancelar Transação\nR: ");
	scanf(" %c", &answer);
	
	if(answer == 'A' || answer == 'a')
		return 1;
	else if(answer == 'B' || answer == 'b')
		return 0;
	else
		printf("\nResposta Inválida.\n");
}
