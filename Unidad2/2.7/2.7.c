// 2.7. Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena.
#include <stdio.h>
int main ()
{
    int numin, cent, dec, unid, aux;
    printf("Ingresar un numero de 3 cifras: ");
    scanf("%d", &numin);
    cent = numin / 100;
    aux = numin % 100;
    dec = aux / 10;
    unid = aux % 10;
    printf("Su numero ha sido descompuesto:");
    printf("\nCentena: %d", cent * 100);
    printf("\nDecenas: %d", dec * 10);
    printf("\nUnidad: %d", unid);
    return(0);
}