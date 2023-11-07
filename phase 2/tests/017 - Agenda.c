/* Algoritmo que simula o funcionamento de uma agenda */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
	int hora, minutos;
	int dia, mes, ano;
	char descricao[50];
} compromisso;

void preencherAgenda(compromisso agenda[5][7]);
void registrarNome(char nome[]);
void menu(char nome[], compromisso agenda[5][7]);
void marcarCompromisso(compromisso agenda[5][7]);
//int marcarDataCompromisso();
//int procurarDiaNaAgenda();
//void marcarHoraCompromisso();

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
	int contador = 1;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			agenda[i][j].dia = contador;
			contador++;
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
	
	while(answer != 2)
	{
		printf("\nBem-vindo à sua agenda Novembro/23, %s!", nome);
		printf("\n[1] Marcar Compromisso\n\n[2] Ver Agenda\n[3] Sair\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				imprimirAgenda();
				marcarCompromisso(agenda);
				break;
			case 2:
				imprimirAgenda();
				imprimirCompromissos();
				break;
			case 3:
				break;
			default:
				printf("Opção Inválida.");
				break;
		}
	}
}

void marcarCompromisso(compromisso agenda[5][7])
{	
	marcarDataCompromisso();
	marcarHoraCompromisso();
	marcarDescricaoCompromisso();
}

int marcarDataCompromisso()
{
	int dia;
	
	while(1)
	{
		printf("Dia do compromisso: ");
		scanf("%i", &dia);
		
		if(0 < dia && dia < 31)
			break;
		else
			printf("Dia inválido.");
	}
	
	procurarDiaNaAgenda();
}

int procurarDiaNaAgenda()
{
	int i, j;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(dia == agenda[i][j].dia)
			{
				agenda[i][j] = 0;
			}
		}
	}
}

void marcarHoraCompromisso()
{
	printf("Insira a hora do compromisso: ");
	scanf("%i", &compromissos[index_semana][index_dia].hora);
	printf("h");
	scanf("%i", &compromissos[index_semana][index_dia].minutos);
}
