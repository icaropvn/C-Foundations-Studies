// Algoritmo de simulação de um Caixa Eletrônico

// colocar sistema de cadastramento inicial
// colocar sistema de login com senha (personalizar de acordo com o usuario)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int simular_cedulas(int notas[]);

void menu(float *saldo, int notas[], int quant_notas);

void sacar(float *saldo, int notas[], int quant_notas);
int verificar_notas(int saque, int notas[], int quant_notas);
void definir_cedulas(int saque, int notas[]);

void depositar(float *saldo);

int confirmar_transacao(int valor);

int main()
{
	float saldo;
	int notas[6] = {200, 100, 50, 20, 10, 5};
	int quantidade_notas;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	quantidade_notas = simular_cedulas(notas);
	saldo = (rand() % 5000) + ((float)(rand() % 100) / 100);
	
	menu(&saldo, notas, quantidade_notas);
	
	return 0;
}

int simular_cedulas(int notas[])
{
	int cont = 0;
	int quantidade_notas, temp;
	
	quantidade_notas = (rand() % 5) + 1;
	printf("Quantidade de notas: %i\n\n", quantidade_notas);
	
	while(cont < (6 - quantidade_notas))
	{
		temp = rand() % 6;
		
		if(notas[temp] != 0)
		{
			notas[temp] = 0;
			cont++;
		}
	}
	
	return quantidade_notas;
}

void menu(float *saldo, int notas[], int quant_notas)
{
	char answer;
	
	while(answer != 'D' && answer != 'd')
	{
		printf("Bem-Vindo [NOME DO USUARIO]!\nO que deseja fazer hoje?\n");
		printf("[A] Sacar\n[B] Depositar\n[C] Verificar Saldo\n[D] Sair\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a')
		{
			sacar(&saldo, notas, quant_notas);
		}
		else if(answer == 'B' || answer == 'b')
		{
			depositar(&saldo);
		}
	}
}

void sacar(float *saldo, int notas[], int quant_notas)
{
	int i;
	char answer;
	int saque;
	
	while(1)
	{
		printf("------------------------------------------\n");
		printf("[A] - Digitar Valor para Sacar\n[B] - Voltar para o Menu\nR: ");
		scanf(" %c", &answer);
		
		if(answer == 'A' || answer == 'a' || answer == 'B' || answer == 'b')
			break;
		else
			printf("\nOpção Inválida.\n");
	}
	
	if(answer == 'A' || answer == 'a')
	{
		printf("------------------------------------------\n");
		printf("Notas disponíveis hoje [colocar data do dia de hoje]:\n");
		
		for(i=0; i<6; i++)
		{
			if(notas[i] != 0)
				printf(" - R$%i,00\n", notas[i]);
		}
		
		printf("\nSaldo Atual: R$%.2f\n", *saldo);
		printf("Digite o valor desejado para sacar: R$");
		scanf("%i", &saque);	

		if(saque < *saldo)
		{	
			if(verificar_notas(saque, notas, quant_notas))
			{
				printf("------------------------------------------\n");
				printf("Você receberá:\n");
				definir_cedulas(saque, notas);
				
				printf("\n");
				
				if(confirmar_transacao(saque))
				{
					*saldo -= saque;
					printf("\nSaque realizado com sucesso! Retire as cédulas ao lado.\n");
					printf("----------------------------------------------------------\n");
				}
				else
				{
					printf("\nCancelando Operação...");
					sleep(2);
					printf("\nOperação Cancelada.\n");
					printf("------------------------------------------\n");
				}
			}
			else
			{
				printf("\nO valor desejado é inválido devido às notas disponíveis do dia.\n");
				printf("---------------------------------------------------------------\n");
			}
		}
		else
		{
			printf("\nOperação Cancelada. O valor de saque desejado é maior que seu saldo atual.\n");
			printf("---------------------------------------------------------------\n");
		}
	}
	else
	{
		printf("\nVoltando para o menu...\n");
		printf("--------------------------\n");
		sleep(2);
	}
}

int verificar_notas(int saque, int notas[], int quant_notas)
{
	int i;
	int cont = 0;
	
	for(i=0; i<6; i++)
	{
		if(notas[i] != 0 && saque % notas[i] == 0)
		{
			saque = saque % notas[i];
			
			if(saque == 0)
				break;
		}
	}
	
	if(saque == 0)
		return 1;
	else
		return 0;
}

void definir_cedulas(int saque, int notas[])
{
	int i;
	int cont;
	int quant_notas[6] = {0, 0, 0, 0, 0, 0};
	
	for(i=0; i<6; i++)
	{
		if(notas[i] != 0)
		{
			if(saque >= notas[i])
			{
				cont = i;
				break;
			}
		}
	}
		
	while(cont <= 6 && saque > 0)
	{
		if(notas[cont] != 0)
		{
			quant_notas[cont] = saque / notas[cont] ;
			saque = saque % notas[cont] ;
		}	
		else
			quant_notas[cont] = 0;
		
		cont++ ;
	}
	
	for(i=0; i<6; i++)
	{
		if(quant_notas[i] > 1)
			printf("%i Notas de R$%i,00\n", quant_notas[i], notas[i]);
		else if(quant_notas[i] == 1)
			printf("%i Nota de R$%i,00\n", quant_notas[i], notas[i]);
	}
		
	for(i=0; i<6; i++)
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
