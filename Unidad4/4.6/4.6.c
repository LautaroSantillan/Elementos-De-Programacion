// 4.6. Confeccionar un programa que permita ingresar 4 números enteros, 
// de a uno por vez y determine el menor valor y su número de orden. Informe los valores 
// ingresados e identifique al menor con mensaje aclaratorio.
#include <stdio.h>
int main()
{
    int num1, num2, num3, num4, menor, orden;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    menor=num1;
    orden=1;
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &num2);
    if(num2<menor)
    {
        menor=num2;
        orden=2;
    }
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &num3);
    if(num3<menor)
    {
        menor=num3;
        orden=3;
    }
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &num4);
    if(num4<menor)
    {
        menor=num4;
        orden=4;
    }
    printf("\nSe ingresaron los numeros: %d %d %d %d", num1,num2,num3,num4);
    printf("\nEl menor es %d y se ingreso en el orden %d", menor, orden);
}