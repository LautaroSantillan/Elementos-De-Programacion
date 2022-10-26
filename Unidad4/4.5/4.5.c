// 4.5. Se ingresan 3 números enteros. Informarlos en orden creciente.
#include <stdio.h>
int main ()
{
    int num1, num2, num3;
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("\nIngrese otro numero: ");
    scanf("%d", &num2);
    printf("\nIngrese el ultimo numero: ");
    scanf("%d", &num3);
    if(num1 > num2 && num1 > num3)
        if(num2 < num3)
            printf("\n%d %d %d", num2, num3, num1);
        else
            printf("\n%d %d %d", num3, num2, num1);
    else
    {
        if(num2 > num3)
            if(num1 < num3)
                printf("\n%d %d %d", num1, num3, num2);
            else
                printf("\n%d %d %d", num3, num1, num2);
        else
        {
            if(num2 < num1)
                printf("\n%d %d %d", num2, num1, num3);
            else
                printf("\n%d %d %d", num1, num2, num3);
        }
    }
}