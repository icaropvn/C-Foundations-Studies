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
#define TAM 50

typedef struct
{
	char emails[50];
} emails;

typedef struct
{
	int codigo, etapa, ano_inicio;
	float mensalidade, bolsa;
	emails email[50];
} dadosAlunos;

void menu(dadosAlunos alunos[], int *contador);
void opcaoEscolhida(int resposta, dadosAlunos alunos[], int *contador);
void cadastrarAluno(dadosAlunos alunos[], int *contador);
void lerEmail(dadosAlunos alunos[], int *contador);
void listarCadastros(dadosAlunos alunos[], int contador);
void gerarArquivo(dadosAlunos alunos[], int contador);

int main()
{
	// Ícaro Costa Pavan - 840790
	dadosAlunos alunos[TAM];
	int contador = 0;
	
	menu(alunos, &contador);
}

void menu(dadosAlunos alunos[], int *contador)
{
	int resposta;
	
	while(resposta != 4)
	{
		printf("Alunos Cadastrados: %02i\nEscolha uma opcao:\n", *contador);
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
	
	lerEmail(alunos, &*contador);
	
	(*contador)++;
}

void lerEmail(dadosAlunos alunos[], int *contador)
{
	int quant_emails;
	int i;
	
	printf("\nQuantos e-mails deseja cadastrar?\nR: ");
	scanf("%i", &quant_emails);
	
	for(i=0; i<quant_emails; i++)
	{
		printf("\nInsira o e-mail %02i: ", i+1);
		scanf(" %50[^\n]", alunos[*contador].email[i]);
	}
	
	printf("--------------------------------");
}

void listarCadastros(dadosAlunos alunos[], int contador)
{
	int i;
	
	printf("\n|---RA---|-ETAPA-|-ANO DE INICIO-|-MENSALIDADE-|-BOLSA-|-E-MAILS------------------------|\n");
	
	if(contador == 0)
	{
		printf("Nenhum aluno cadastrado.\n");
	}
	
	for(i=0; i<contador; i++)
	{
		printf("| %06i |    %02i |          %4i |      %07.2f | %07.2f | %50s |\n", alunos[contador].codigo, alunos[contador].etapa, alunos[contador].ano_inicio, alunos[contador].mensalidade, alunos[contador].bolsa, alunos[contador].email);
	}
	
	printf("|---------------------------------------------------------------------------------------|\n\n");
}

void gerarArquivo(dadosAlunos alunos[], int contador)
{
	FILE *file;
	char nome_arquivo[50];
	int i;
	
	printf("Escolha o nome do arquivo CSV: ");
	scanf(" %50[^\n]", nome_arquivo);
	
	file = fopen("Cadastro de Alunos.csv", "w");
	
	for(i=0; i<contador; i++)
	{
		fprintf(file, "%06i; %02i; %4i; %07.2f; %07.2f; %s\n", alunos[contador].codigo, alunos[contador].etapa, alunos[contador].ano_inicio, alunos[contador].mensalidade, alunos[contador].bolsa, alunos[contador].email);
	}
}
