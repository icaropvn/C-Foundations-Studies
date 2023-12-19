#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Foi atualizada a l�gica de registrar um aluno.

No entanto, h� problemas ao puxar os dados do documento. Por algum motivo ele s�
executa o 'while' uma vez, e depois encerra o software. --> isso ainda acontece??

IMPLEMENTA��ES:

1 - linha 144
2 - linha 192

*/

typedef struct
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
} studentData;

void menu(studentData students[], int *counter);
    void selectOption(int answer, studentData students[], int *counter);
        void registerNewStudent(studentData students[], int *counter);
            void pullDataDocument(studentData students[], int *counter);
            void getDataNewRegister(studentData students[], int *counter);
            void sortStudentsCode(studentData students[], int counter);
            void writeRegistersDocument(studentData students[], int counter);
        void showRegisters(studentData students[]);

int verifyErrorFile(FILE *file);

int main()
{
    studentData students[60];
    int counter = 0;
    
    menu(students, &counter);
    
    return 0;
}

void menu(studentData students[], int *counter)
{
    int answer;
    
    while(answer != 3)
    {
        printf("Escolha uma op��o:\n");
        printf("[1] Cadastrar Novo Aluno\n[2] Exibir Alunos Cadastrados\n[3] Sair\nR: ");
        scanf("%i", &answer);
        
        selectOption(answer, students, &*counter);
    }
}

void selectOption(int answer, studentData students[], int *counter)
{
    switch(answer)
    {
        case 1:
            registerNewStudent(students, &*counter);
            break;
        case 2:
            showRegisters(students);
            break;
        case 3:
            printf("\nAté mais!");
            break;
        default:
            printf("\nOpção Inválida.\n-----------------------------");
            break;
    }
    
    printf("\n");
}

void registerNewStudent(studentData students[], int *counter)
{
    pullDataDocument(students, &*counter);
    
    getDataNewRegister(students, &*counter);
        
    sortStudentsCode(students, *counter);
        
    writeRegistersDocument(students, *counter);
}

void pullDataDocument(studentData students[], int *counter)
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
    FILE *file;
    
    file = fopen("Cadastros.txt", "r");
    *counter = 0;
    
    if(!verifyErrorFile(file))
    {
        while(fscanf(file, "%i%s%f%f%f", &students[*counter].code, students[*counter].name, &students[*counter].parcial_grade, &students[*counter].exam_grade, &students[*counter].avarage) != -1)
            (*counter)++;
    }
    
    fclose(file);
}

void getDataNewRegister(studentData students[], int *counter)
{
    printf("\nInsira o código do aluno: ");
    scanf("%6i", &students[*counter].code);
    fflush(stdin);
        
    printf("Insira o nome do aluno: ");
    scanf(" %50[^\n]", students[*counter].name);
    fflush(stdin);
        
    printf("Insira a nota parcial: ");
    scanf("%f", &students[*counter].parcial_grade);
        
    printf("Insira a nota do exame: ");
    scanf("%f", &students[*counter].exam_grade);
        
    students[*counter].avarage = students[*counter].parcial_grade * 0.4 + students[*counter].exam_grade * 0.6;
        
    (*counter)++;
}

void sortStudentsCode(studentData students[], int counter)
{
	int i, j;
	int aux;
	char str_aux[50];
	
	for(i=0; i<counter; i++)
	{
		for(j=0; j<counter-1; j++)
		{
			if(students[j].code > students[j+1].code)
			{
			    // implementar uma função de troca para cada um dos blocos abaixo
			    
				aux = students[j].code;
				students[j].code = students[j+1].code;
				students[j+1].code = aux;
				
				strcpy(str_aux, students[j].name);
				strcpy(students[j].name, students[j+1].name);
				strcpy(students[j+1].name, str_aux);
				
				aux = students[j].parcial_grade;
				students[j].parcial_grade = students[j+1].parcial_grade;
				students[j+1].parcial_grade = aux;
				
				aux = students[j].exam_grade;
				students[j].exam_grade = students[j+1].exam_grade;
				students[j+1].exam_grade = aux;
				
				aux = students[j].avarage;
				students[j].avarage = students[j+1].avarage;
				students[j+1].avarage = aux;
			}
		}
	}
}

void writeRegistersDocument(studentData students[], int counter)
{
    FILE *file;
    
    file = fopen("Cadastros.txt", "w");
    
    for(int i=0; i<counter; i++)
    {
        fprintf(file, " %6i  %50s  %5.2f  %5.2f  %5.2f\n", students[i].code, students[i].name, students[i].parcial_grade, students[i].exam_grade, students[i].avarage);
    }
    
    fclose(file);
}

void showRegisters(studentData students[])
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
    
    FILE *file = fopen("Cadastros.txt", "r");
    
    // implementação da função 'sortRegisters' para ordenar a lista de cadastros inteira em ordem crescente antes de mostrar
    // para isso, ela puxará os registros do arquivo e colocará-los no vetor, depois irá ordená-lo chamando a função
    
    printf("\n|-- RA --|----------------------- NOME -----------------------|- PARCIAL -|- EXAME -|- MÉDIA -|\n");
    
    if(!verifyErrorFile(file))
    {
        while(fscanf(file, "%i%s%f%f%f", &code, name, &parcial_grade, &exam_grade, &avarage) != -1 )
        {
            printf("| %6i | %50s | %9.2f | %7.2f | %7.2f |\n", code, name, parcial_grade, exam_grade, avarage);
        }
        
        printf("|---------------------------------------------------------------------------------------------|\n");
        
        fclose(file);
    }
}

int verifyErrorFile(FILE *file)
{
    if(file == NULL)
    {
        printf("\nAlgo deu errado. Arquivo pode estar corrompido.\n");
        return 1;
    }
    
    return 0;
}
