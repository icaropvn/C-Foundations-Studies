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

void registrarNome(char nome[]);
void menu(char nome[]);
void marcarCompromisso(compromisso compromissos[5][7]);
int marcarDataCompromisso(compromisso compromissos[5][7], int *index_dia, int *index_semana);
int procurarDiaNaAgenda(int dia, compromisso compromissos[5][7], int *index_dia, int *index_semana);

int main()
{
	char nome[50];
	
	setlocale(LC_ALL, "Portuguese");
	
	registrarNome(nome);
	
	menu(nome);
	
	return 0;
}

void registrarNome(char nome[])
{
	printf("Insira o nome de usuário: ");
	scanf("%[^\n]", nome);
	
	fflush(stdin);
}

void menu(char nome[])
{
	int answer;
	compromisso compromissos[5][7];
	
	while(answer != 2)
	{
		printf("\nBem-vindo à sua agenda Novembro/23, %s!", nome);
		printf("[1] Marcar Compromisso\n[2] Sair\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				marcarCompromisso(compromissos);
				break;
			case 2:
				break;
			default:
				printf("Opção Inválida.");
		}
	}
}

void marcarCompromisso(compromisso compromissos[5][7])
{
	int index_dia;
	int index_semana;	
	
	marcarDataCompromisso(compromissos, &index_dia, &index_semana);
	marcarHoraCompromisso();
	
	printf("Descrição do compromisso: ");
	scanf("%[^\n]", &compromissos[index_semana][index_dia].descricao);
}

int marcarDataCompromisso(compromisso compromissos[5][7], int *index_dia, int *index_semana)
{
	int dia;
	
	while(1)
	{
		printf("Dia do compromisso: ");
		scanf("%i", &dia);
		
		if(0 < dia < 31)
			procurarDiaNaAgenda(dia, compromissos, &*index_dia, &*index_semana);
		else
			printf("Dia inválido.");
	}
}

int procurarDiaNaAgenda(int dia, compromisso compromissos[5][7], int *index_dia, int *index_semana)
{
	int i, j;
	int contador = 1;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<7; j++)
		{
			if(contador == dia)
			{
				*index_dia = j;
				*index_semana = i;
			}
		}
	}
}
