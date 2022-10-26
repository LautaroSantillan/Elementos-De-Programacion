// 2.4. Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a yardas, pulgadas, cms.
// y mts. NOTA: 1 pie = 12 pulgadas; 1 yarda = 3 pies; 1 pulgada = 2,54 cms.
#include <stdio.h>
int main ()
{
    float pies;
    printf("Ingrese una medida de pies:");
    scanf("%f", &pies);
    printf("Su medida de pies se mostrara en otras unidades aproximdas: ");
    printf("\nYardas = %.2f", pies / 3);
    printf("\nPulgadas = %.2f", pies * 12);
    printf("\nCentimetros = %.2f", pies * 30.48);
    printf("\nMetros = %.2f", pies * 0.3048);
    return(0);
}