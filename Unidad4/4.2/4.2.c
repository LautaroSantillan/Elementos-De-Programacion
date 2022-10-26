// 4.2. Dados tres números determinar e informar con un mensaje si el primer número ingresado es menor que
// los otros dos.
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
    if(num1<num2 && num1<num3)
        printf("\n%d es el numero menor", num1);
    else
        printf("\nEl primer numero no es menor que los otros 2");
}