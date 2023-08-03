// 001 - Cadastro de Alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int codigo, faltas ;
    char nome[50], status[3] ;
    float parcial, exame, media ;
} dados_alunos;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int i, answer = 1, student_counter = 0;
    dados_alunos aluno[30];
    
    do
    {
        if(answer == 1)
        {
            if(student_counter < 30)
            {
                printf("Codigo (RA): ");
                scanf("%i", &aluno[student_counter].codigo);
                
                printf("Nome: ");
                scanf(" %[^\n]s", aluno[student_counter].nome);

                printf("Nota da prova parcial: ");
                scanf("%f", &aluno[student_counter].parcial);
                    
                printf("Nota do exame: ");
                scanf("%f", &aluno[student_counter].exame);
                
                aluno[student_counter].media = 0.4 * aluno[student_counter].parcial + 0.6 * aluno[student_counter].exame ;
                
                if(aluno[student_counter].media >= 6.0)
                    strcpy(aluno[student_counter].status, "APR");
                else
                    strcpy(aluno[student_counter].status, "REP");
                    
                printf("Faltas do aluno: ");
                scanf("%i", &aluno[student_counter].faltas);
                
                student_counter++ ;
            }
            else
                printf("QUANTIDADE MAXIMA DE ALUNOS CADASTRADOS\n");
        }
        else if(answer == 2)
        {
            printf("---------------------------------------------------------------------------------\n");
            printf(" Codigo  |      Nome      |  Parcial  |  Exame  |  Media  |  Faltas  |  Status  |\n");
            
            for(i=0; i<student_counter; i++)
            {
                printf(" %6.i  | %s              |  %7.1f  |  %5.1f  |  %5.1f  |  %6.i  |     %s  |\n", aluno[i].codigo, aluno[i].nome, aluno[i].parcial, aluno[i].exame, aluno[i].media, aluno[i].faltas, aluno[i].status);
                if(i == student_counter - 1)
                    printf("---------------------------------------------------------------------------------\n");
            }
            
        }
        else
            printf("Resposta invalida\n");
        
        printf("\nTotal de alunos: %i\n1) Adicionar\n2) Listar\n3) Sair\nR: ", student_counter);
        scanf("%i", &answer);
        
        printf("\n");
        
    } while(answer != 3);
    
    printf("Ate a proxima!\n");
    
    return 0;
}