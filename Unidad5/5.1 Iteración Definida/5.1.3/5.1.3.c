//5.1.3 Se ingresan 50 números enteros. Determinar el promedio de los números pares.
#include <stdio.h>
int main ()
{
    int suma=0, cont=0,i,num;
    float prom;
    for(i=1;i<=50;i++)
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &num);
        if(num%2==0)
        {
            cont++;
            suma+=num;
        }
    }
    if(cont>0)
    {
        prom=(float) suma/cont;
        printf("Resultado: %.2f", prom);
    }
}