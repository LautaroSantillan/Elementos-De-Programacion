// 4.1. Se ingresan 3 números distintos. Determinar el mayor.
#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf("Ingresar un numero: ");
    scanf("%d", &num1);
    printf("\nIngrese otro numero: ");
    scanf("%d", &num2);
    printf("\nIngrese el ultimo numero: ");
    scanf("%d", &num3);
    if(num1>num2 && num1>num3)
        printf("\n%d es el numero mayor", num1);
    else
    {
        if(num2>num1 && num2>num3)
            printf("\n%d es el numero mayor", num2);
        else
            printf("\n%d es el numero mayor", num3);
    }
}