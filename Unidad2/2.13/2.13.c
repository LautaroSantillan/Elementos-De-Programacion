// 2.13. Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y pueda calcular
// e informar la suma de sus dígitos hasta llegar a una sola cifra. Ej:2561 → 5.
#include <stdio.h>
int main()
{
    int num, sum;
    printf("Ingrese un numero de 4 cifras: ");
    scanf("%d", &num);
    sum = num / 1000;
    num = num % 1000;
    sum += num / 100;
    num = num % 100;
    sum += num / 10 + num % 10;
    sum = sum / 10 + sum % 10;
    sum = sum / 10 + sum % 10;
    printf("\nEl resultado es: %d", sum);
    return(0);
}