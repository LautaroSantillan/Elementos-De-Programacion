// 4.3. Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si alguno de ellos
// es igual a la suma de los otros dos.
#include <stdio.h>
int main ()
{
    int num1, num2, num3;
    printf("Ingresar un numero entero: ");
    scanf("%d", &num1);
    printf("\nIngresar un numero entero: ");
    scanf("%d", &num2);
    printf("\nIngresar un numero entero: ");
    scanf("%d", &num3);
    if(num1 == num2 + num3)
        printf("\n%d es igual a la suma entre %d y %d", num1, num2, num3);
    else
    {
        if(num2 == num1 + num3)
            printf("\n%d es igual a la suma entre %d y %d", num2, num1, num3);
        else
        {
            if(num3 == num1 + num2)
                printf("\n%d es igual a la suma entre %d y %d", num3, num1, num2);
            else
                printf("\nNingun numero es igual a la suma de los otros 2");
        }
    }
}