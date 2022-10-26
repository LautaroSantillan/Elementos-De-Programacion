// 5.1.11 Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar cuantas ternas (tres
// valores seguidos) de valores positivos y cuantas de negativos hay.
#include <stdio.h>
int main ()
{
    int i, valortemp = 0, tempPos = 0, tempNeg = 0, ternapos = 0, ternaneg = 0;
    for(i = 1; i <= 18; i++)
    {
        printf("\nIngrese un valor de temperatura distinto de cero: ");
        scanf("%d", &valortemp);
        if(valortemp > 0)
        {
            tempPos ++;
            tempNeg = 0;
            if(tempPos == 3)
            {
                ternapos++;
                tempPos = 0;
            }
        }
        else
        {
            tempNeg++;
            tempPos = 0;
            if(tempNeg == 3)
            {
                ternaneg++;
                tempNeg = 0;
            }
        }
    }
    printf("\nHay %d ternas positivas y %d ternas negativas\n", ternapos, ternaneg);
}