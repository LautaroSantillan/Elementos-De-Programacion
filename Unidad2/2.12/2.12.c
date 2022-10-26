// 2.12. Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%. Confeccionar un
// programa que recibiendo el precio original y un código que indica si es o no con descuento, informe el
// precio final (0 no aplica el descuento y 1 aplica el descuento).
#include <stdio.h>
int main ()
{
    int desc, precior;
    float preciof;
    printf("Ingrese el precio del producto: ");
    scanf("%d", &precior);
    printf("\nIngresar codigo 0 o 1. 0 no aplica descuento y 1 aplica un descuento del 20%: ");
    scanf("%d", &desc);
    preciof = precior - desc * precior * 0.2;
    printf("\nEl precio final es de: %.2f", preciof);
    return(0);
}