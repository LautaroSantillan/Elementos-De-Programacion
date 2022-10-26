// 5.1.13 Realizar un programa que:
// a. Muestre todos los números primos entre 1 y 100. (Un nro. es primo cuando es divisible solamente
// por 1 y por sí mismo)
// b. Contar y mostrar la cantidad de primos encontrados.
#include <stdio.h>
int main ()
{
    int i, num=2, cantprimos=4;
    printf("2 3 5 7");
    for(i=1; i<100; i++)
    {
        if(num%2==0 || num%3==0 || num%5==0 || num%7==0)
            num++;
        else
        {
            if(num%1==0 || num%num==0)
            {
                printf("\n%d",num);
                cantprimos++;
                num++;
            }
        }
    }
    printf("\nSe contaron %d numeros primos", cantprimos);
}