// Exercício 03

#include <stdio.h>
#include <locale.h>

void primos(int num);

int main()
{
    int num ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um número para encontrar os primos até ele: ");
    scanf("%i", &num);
    
    printf("\n");
    
    primos(num);
    
    return 0;
}

void primos(int num)
{
    int i, j, divisores ;
    
    for(i=1; i<=num; i++)
    {
        divisores = 0 ;
        
        for(j=2; j<i; j++)
        {
            if(i % j == 0)
                divisores++ ;
        }
        
        if(divisores == 0)
            printf("%i, ", i);
    }
}
