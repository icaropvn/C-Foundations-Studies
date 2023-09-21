// Exercício 02

#include <stdio.h>
#include <locale.h>

int fatorial(int num1);

int main()
{
    int num1, fatorial_num1;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num1);
    
    fatorial_num1 = fatorial(num1);
    
    printf("\n%i! = %i", num1, fatorial_num1);
    
    return 0;
}

int fatorial(int num1)
{
    int i, fat = 1 ;
    
    for(i=num1; i>=1; i--)
    {
        fat *= i ;
    }
    
    return fat;
}