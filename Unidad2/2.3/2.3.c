// 2.3. Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes
// aclaratorios la suma, el producto, el cociente y el resto.
#include <stdio.h>
int main ()
{
    int num1,num2,sum,prod,coc,rest;
    printf("Ingrese un numero entero: ");
    scanf("%d",&num1);
    printf("Ingrese un numero distinto de 0: ");
    scanf("%d",&num2);
    sum = num1 + num2;
    prod = num1 * num2;
    coc = num1 / num2;
    rest = num1 - num2;
    printf("\nEl resultado de operar %d y %d es:", num1, num2);
    printf("\nSuma:%d",sum);
    printf("\nProducto:%d",prod);
    printf("\nCociente:%d",coc);
    printf("\nResto:%d",rest);
    return(0);
}