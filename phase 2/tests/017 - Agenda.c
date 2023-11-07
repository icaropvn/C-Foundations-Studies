/* Algoritmo que simula o funcionamento de uma agenda */

// limitação: só é possível adicionar um compromisso por dia
// adicionar: pegar mês do sistema
// adicionar: imprimir calendário certo a partir do mês, com dias da semana relacionados


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
	int dia_agenda;
	
	int hora, minutos;
	int dia_compromisso, mes;
	char descricao[50];
} compromisso;

void preencherAgenda(compromisso agenda[5][7]);
void registrarNome(char nome[]);
void menu(char nome[], compromisso agenda[5][7]);
void marcarCompromisso(compromisso agenda[5][7]);
int marcarDataCompromisso(compromisso agenda[5][7]);
int procurarDiaNaAgenda(int dia, compromisso agenda[5][7]);
void marcarHoraCompromisso(compromisso agenda[5][7], int ind_semana, int ind_dia);
void imprimirAgenda(compromisso agenda[5][7]);
void marcarDescricaoCompromisso();
void imprimirCompromissos(compromisso agenda[5][7]);

int main()
{
	char nome[50];
	compromisso agenda[5][7];
	
	setlocale(LC_ALL, "Portuguese");
	
	preencherAgenda(agenda);
	
	registrarNome(nome);
	
	menu(nome, agenda);
	
	return 0;
}

void preencherAgenda(compromisso agenda[5][7])
{
	int i, j;
	int contador_dia = 1;
	int contador_mes = 11;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			agenda[i][j].dia_agenda = contador_dia;
			agenda[i][j].dia_compromisso = contador_dia;
			agenda[i][j].mes = contador_mes;
			
			if(contador_dia == 30)
			{
				contador_dia = 0;
				contador_mes++;
			}
			
			contador_dia++;
		}
	}
}

void registrarNome(char nome[])
{
	printf("Insira o nome de usuário: ");
	scanf("%[^\n]", nome);
	
	fflush(stdin);
}

void menu(char nome[], compromisso agenda[5][7])
{
	int answer;
	
	while(answer != 3)
	{
		printf("\nBem-vindo à sua agenda Novembro/23, %s!", nome);
		printf("\n[1] Marcar Compromisso\n[2] Ver Agenda\n[3] Sair\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				imprimirAgenda(agenda);
				marcarCompromisso(agenda);
				break;
			case 2:
				imprimirAgenda(agenda);
				imprimirCompromissos(agenda);
				break;
			case 3:
				break;
			default:
				printf("Opção Inválida.");
				break;
		}
	}
}

void imprimirAgenda(compromisso agenda[5][7])
{
	int i, j;
	
	printf("\n|------------------------------------------------|\n");
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(j == 0)
				printf("|");
			
			if(agenda[i][j].dia_agenda == agenda[i][j].dia_compromisso)
				printf(" %4i |", agenda[i][j].dia_agenda);
			else
				printf(" X%3i |", agenda[i][j].dia_compromisso);
		}
		
		printf("\n|------------------------------------------------|\n");
	}
	
	printf("\n");
}

void marcarCompromisso(compromisso agenda[5][7])
{	
	int dia;
	
	dia = marcarDataCompromisso(agenda);
	
	procurarDiaNaAgenda(dia, agenda);
}

int marcarDataCompromisso(compromisso agenda[5][7])
{
	int dia;
	
	while(1)
	{
		printf("Dia do compromisso: ");
		scanf("%i", &dia);
		
		if(0 < dia && dia < 31)
			return dia;
		else
			printf("\nDia inválido.\n");
	}
}

int procurarDiaNaAgenda(int dia, compromisso agenda[5][7])
{
	int i, j;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(dia == agenda[i][j].dia_compromisso && agenda[i][j].mes == 11)
			{
				agenda[i][j].dia_agenda = 0;
				marcarHoraCompromisso(agenda, i, j);
				marcarDescricaoCompromisso(agenda, i, j);
			}
		}
	}
}

void marcarHoraCompromisso(compromisso agenda[5][7], int ind_semana, int ind_dia)
{
	printf("Insira a hora do compromisso: ");
	scanf("%i", &agenda[ind_semana][ind_dia].hora);
	
	printf("Insira os minutos do compromisso: ");
	scanf("%i", &agenda[ind_semana][ind_dia].minutos);
	
	fflush(stdin);
}

void marcarDescricaoCompromisso(compromisso agenda[5][7], int ind_semana, int ind_dia)
{	
	printf("Insira a descrição do compromisso: ");
	scanf("%[^\n]", &agenda[ind_semana][ind_dia].descricao);
	
	fflush(stdin);
}

void imprimirCompromissos(compromisso agenda[5][7])
{
	int i, j;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(agenda[i][j].dia_agenda == 0)
			{
				printf("==== Dia %02i/11 ====\n", agenda[i][j].dia_compromisso);
				printf("Compromisso: %s\n", agenda[i][j].descricao);
				printf("Hora: %02ih%02i\n", agenda[i][j].hora, agenda[i][j].minutos);
			}
		}
	}
	
	printf("\n===========================================");
}
