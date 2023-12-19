/*
IMPLEMENTAÇÕES A SEREM FEITAS

1. criar uma variavel na struct dos emails pra guardar a quantidade de emails registrados por pessoa

2. fazer verificação de no maximo 3 emails cadastrados

3. fazer funcao de redefinir dados escolhidos por RA

4. trocar W por A e fazer verificação de alunos iguais através de RA a cada envio de dados

5. ordenar RAs por ordem crescente no arquivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define TAM 50

typedef struct
{
	char emails[50];
} emails;

typedef struct
{
	int codigo, etapa, ano_inicio;
	float mensalidade, bolsa;
	emails email[3];
} dadosAlunos;

void menu(dadosAlunos alunos[], int *contador);
void opcaoEscolhida(int resposta, dadosAlunos alunos[], int *contador);
void cadastrarAluno(dadosAlunos alunos[], int *contador);
void lerEmail(dadosAlunos alunos[], int contador);
void listarCadastros(dadosAlunos alunos[], int contador);
void imprimirEmails(dadosAlunos alunos[], int j);
void gerarArquivo(dadosAlunos alunos[], int contador);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	dadosAlunos alunos[TAM];
	int contador = 0;
	
	menu(alunos, &contador);
	
	return 0;
}

void menu(dadosAlunos alunos[], int *contador)
{
	int resposta = 0;
	
	while(resposta != 4)
	{
		printf("Alunos Cadastrados: %02i\nEscolha uma opção:\n", *contador);
		printf("[1] Cadastrar Novo Aluno\n[2] Listar Cadastros\n[3] Gerar Arquivo CSV\n[4] Sair\n");
		printf("R: ");
		scanf("%i", &resposta);
		
		opcaoEscolhida(resposta, alunos, &*contador);
	}
}

void opcaoEscolhida(int resposta, dadosAlunos alunos[], int *contador)
{	
	switch(resposta)
	{
		case 1:
			cadastrarAluno(alunos, &*contador);
			break;
		case 2:
			listarCadastros(alunos, *contador);
			break;
		case 3:
			gerarArquivo(alunos, *contador);
			break;
		case 4:
			break;
		default:
			printf("Ops! Opcao Invalida.");
			break;
	}
}

void cadastrarAluno(dadosAlunos alunos[], int *contador)
{
	printf("--------------------------------");
	
	printf("\nInsira o RA: ");
	scanf("%i", &alunos[*contador].codigo);
	
	printf("Insira a etapa: ");
	scanf("%i", &alunos[*contador].etapa);
	
	printf("Insira o ano de inicio: ");
	scanf("%i", &alunos[*contador].ano_inicio);
	
	printf("Insira a mensalidade: R$");
	scanf("%f", &alunos[*contador].mensalidade);
	
	printf("Insira valor da bolsa (se nao houver responder 0): R$");
	scanf("%f", &alunos[*contador].bolsa);
	
	printf("--------------------------------");
	
	lerEmail(alunos, *contador);
	
	(*contador)++;
}

void lerEmail(dadosAlunos alunos[], int contador)
{
	int quant_emails;
	int i;
	
	printf("\nQuantos e-mails deseja cadastrar?\nR: ");
	scanf("%i", &quant_emails);
	
	for(i=0; i<quant_emails; i++)
	{
		printf("\nInsira o e-mail %02i: ", i+1);
		scanf(" %50[^\n]", alunos[contador].email[i].emails);
	}
	
	printf("--------------------------------\n");
}

void listarCadastros(dadosAlunos alunos[], int contador)
{
	int i;
	
	if(contador == 0)
	{
		printf("\n========================");
		printf("\nNenhum aluno cadastrado.");
		printf("\n========================\n\n");
	}
	else
	{
		printf("\n|---RA---|-ETAPA-|-ANO DE INICIO-|-MENSALIDADE-|--BOLSA--|-E-MAILS--------------------------------------------|\n");
		
		for(i=0; i<contador; i++)
		{
			printf("|-------------------------------------------------------------------------------------------------------------|\n");
			
			printf("| %06i |    %02i |          %4i |    %08.2f |", alunos[i].codigo, alunos[i].etapa, alunos[i].ano_inicio, alunos[i].mensalidade);
			
			if(alunos[i].bolsa == 0)
		        printf("       - ");
		    else
		        printf(" %07.2f ", alunos[i].bolsa);
			
			imprimirEmails(alunos, i);
		}
		
		printf("|-------------------------------------------------------------------------------------------------------------|\n\n");
	}
}

void imprimirEmails(dadosAlunos alunos[], int j)
{
	int i;
	
	for(i=0; i<3; i++)
	{
		if(i == 0)
			printf("| %50s |\n", alunos[j].email[i].emails);
		else
			printf("|                                                        | %50s |\n", alunos[j].email[i].emails);
	}
		
}

void gerarArquivo(dadosAlunos alunos[], int contador)
{
	FILE *file;
	char nome_escolhido[50];
	int i;
	
	printf("\n---------------------------------");
	printf("\nEscolha o nome do arquivo CSV: ");
	scanf(" %50[^\n]", nome_escolhido);
	
	strcat(nome_escolhido, ".csv");
	
	file = fopen(nome_escolhido, "w");
	
	for(i=0; i<contador; i++)
	{
		fprintf(file, "%06i; %02i; %4i; %07.2f; %07.2f; %s\n", alunos[contador].codigo, alunos[contador].etapa, alunos[contador].ano_inicio, alunos[contador].mensalidade, alunos[contador].bolsa, alunos[contador].email);
	}
	
	sleep(2);
	printf("\nArquivo gerado com sucesso!");
	sleep(2);
	
	printf("\n---------------------------------\n\n");
}
