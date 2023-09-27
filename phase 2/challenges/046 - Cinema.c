//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define L 6
#define C 10

void atribuir_lugares(int sala[L][C]);
void simular_escolhas(int sala[L][C]);
void menu(int sala[L][C], int reserva);
void mostrar_sala(int sala[L][C]);
void escolher(int sala[L][C], int *reserva);

int main()
{
    int sala[L][C];
    int reserva = 0;
    
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    
    atribuir_lugares(sala);
    simular_escolhas(sala);
    
    menu(sala, reserva);
    
    return 0;
}

void atribuir_lugares(int sala[L][C])
{
    int i, j;
    int cont = 1;
    
    for(i=0; i<L; i++)
    {
        for(j=0; j<C; j++)
        {
            sala[i][j] = cont ;
            cont++ ;
        }
    }
}

void simular_escolhas(int sala[L][C])
{
	int i, j;
	int temp, cont = 0;
	
	while(cont < 30)
	{
		temp = (rand() % 60) + 1;
		
		for(i=0; i<L; i++)
		{
			for(j=0; j<C; j++)
			{
				if(sala[i][j] == temp)
				{
					sala[i][j] = 0 ;
					cont++;
				}
			}
		}
	}
}

void menu(int sala[L][C], int reserva)
{
    int answer;
    
    while(answer != 3)
    {
        printf("Escolha uma opção:\n[1] Exibir Sala\n[2] Escolher Lugar\n[3] Sair\nR: ");
        scanf("%i", &answer);
        
        switch(answer)
        {
            case 1:
                mostrar_sala(sala);
                break;
            case 2:
                escolher(sala, &reserva);
                break;
            case 3:
                if(reserva == 0)
					printf("\nVocê não reservou lugares.\nTenha um bom dia!\n");
				else
					printf("\nEsperamos que goste do filme!\n");
                break;
            default:
                printf("\nResposta Inválida.\n\n");
                break;
        }
    }
}

void mostrar_sala(int sala[L][C])
{
    int i, j;
    
    printf("-----------------------------------------\n");
    printf("Lugares Disponíveis:\n\n");
    
    for(i=0; i<L; i++)
    {
        for(j=0; j<C; j++)
        {
            if(sala[i][j] == 0)
                printf(" X ");
            else
                printf("%2.1i ", sala[i][j]);
        }
        printf("\n");
    }
    
    printf("-----------------------------------------\n");
}

void escolher(int sala[L][C], int *reserva)
{
    int i, j;
    int lugar, lugar_livre = 0;
    int answer ;
    
    mostrar_sala(sala);
    
    while(lugar_livre == 0)
    {
        printf("Insira o lugar desejado para reservar: ");
        scanf("%i", &lugar);
        
        for(i=0; i<L; i++)
        {
            for(j=0; j<C; j++)
            {
                if(lugar == sala[i][j])
                {
                    sala[i][j] = 0 ;
                    lugar_livre = 1;
                    *reserva = 1;
                }
            }
        }
        
        if(!lugar_livre)
        {
            answer = 0;
			
			printf("\nLugar já reservado.\n");
            printf("-----------------------------------------\n");
            
            while(answer != 1 && answer != 2)
            {
            	printf("[1] Escolher Outro Lugar\n[2] Voltar para o Menu\nR: ");
            	scanf("%i", &answer);
            	
            	if(answer == 2)
            		lugar_livre = 1;
            	else if(answer != 1)
            		printf("\nEscolha Inválida\n");
			}
        }
        
        printf("-----------------------------------------\n");
    }
}
