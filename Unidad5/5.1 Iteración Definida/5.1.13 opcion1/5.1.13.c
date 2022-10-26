// 5.1.13 Realizar un programa que:
// a. Muestre todos los números primos entre 1 y 100. (Un nro. es primo cuando es divisible solamente
// por 1 y por sí mismo)
// b. Contar y mostrar la cantidad de primos encontrados.
#include <stdio.h>
int main()
{
    int i, j, divisores, contprimos=0;
    for(i=2; i<=100; i++)
    {
        divisores=0;
        for(j=2; j<i; j++)
            if(i%j==0)
                divisores++;
        if(divisores==0)
        {
            printf("El numero %d es primo\n", i);
            contprimos++;
        }
    }
    printf("\nLa cantidad de numeros primos encontrados es %d\n", contprimos);
}