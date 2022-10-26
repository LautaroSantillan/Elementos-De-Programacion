// 2.9. Confeccionar un programa que ingrese un valor expresado en Kibibyte (KiB)1
// y lo informe expresado en: TiB, GiB, MiB, con leyendas aclaratorias. 
// (1MiB = 1024 KiB; 1GiB = 1024 MiB; 1TiB = 1024 GiB)
#include <stdio.h>
int main ()
{
    float kib, mib, gib, tib;
    printf("Ingrese un valor expresado en KIB: ");
    scanf("%f", &kib);
    mib = kib / 1024;
    gib = mib / 1024;
    tib = gib / 1024;
    printf("\nEl valor ingresado se mostrara en otras unidades: ");
    printf("\nmib: %f", mib);
    printf("\ngib: %f", gib);
    printf("\ntib: %f", tib);
    return(0);
}