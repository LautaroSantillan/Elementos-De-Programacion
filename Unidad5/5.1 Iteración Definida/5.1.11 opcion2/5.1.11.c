// 5.1.11 Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar cuantas ternas (tres
// valores seguidos) de valores positivos y cuantas de negativos hay.
#include <stdio.h>
int main()
{
    int ternap=0,ternan=0,pos=0,neg=0,temp,i;
    for(i=1; i<=18; i++)
    {
        printf("\nIngrese una temperatura distinto de 0: ");
        scanf("%d", &temp);
        if(temp>0)
        {
            neg=0;
            pos++;
            if(pos>2)
                ternap++;
        }
        else
        {
            pos=0;
            neg++;
            if(neg>2)
                ternan++;
        }
    }
    printf("\nSe ingresaron %d ternas positivas y %d ternas negativas", ternap, ternan);
}