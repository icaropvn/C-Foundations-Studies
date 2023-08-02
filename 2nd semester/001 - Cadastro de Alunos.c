// 001 - Cadastro de Alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo, faltas ;
    char nome[50], status[3] ;
    float parcial, exame, media ;
} dados_alunos;

int main()
{
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
                
                // printf("Nome: ");
                // scanf("%s", &aluno[student_counter].nome);
                
                printf("Nota da prova parcial: ");
                scanf("%f", &aluno[student_counter].parcial);
                    
                printf("Nota do exame: ");
                scanf("%f", &aluno[student_counter].exame);
                
                aluno[student_counter].media = 0.4 * aluno[student_counter].parcial + 0.6 * aluno[student_counter].exame ;
                
                if(aluno[student_counter].media >= 6.0)
                    aluno[student_counter].status[0] = 'a';
                else
                    aluno[student_counter].status[0] = 'r';
                    
                printf("Faltas do aluno: ");
                scanf("%i", &aluno[student_counter].faltas);
                
                student_counter++ ;
            }
            else
                printf("QUANTIDADE MAXIMA DE ALUNOS CADASTRADOS\n");
        }
        else if(answer == 2)
        {
            printf("----------------------------------------------------------------\n");
            printf(" Codigo  |      Nome      |  Parcial  |  Exame  |  Media  |  Faltas  |  Status  |\n");
            
            for(i=0; i<student_counter; i++)
                printf(" %6.i  | %s             |    %.1f    |   %.1f   |   %.1f   |     %i    |          |\n", aluno[i].codigo, aluno[student_counter].nome, aluno[i].parcial, aluno[i].exame, aluno[i].media, aluno[i].faltas);
                if(i == student_counter)
                    printf("----------------------------------------------------------------\n");
            
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