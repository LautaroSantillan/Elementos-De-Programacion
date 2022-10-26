// 2.11. Una pizzería vende empanadas por unidad o por docena, la docena cuesta $300 pero si se compra
// individualmente se cobra $30 la unidad. Si se compran más empanadas que no se agrupen en docenas las
// adicionales se cobran como por unidad. Indicar el precio total a abonar.
#include <stdio.h>
int main ()
{
    int cantemp, docena, indiv, prectot;
    int precdoc = 300;
    int precind = 30;
    printf("Ingresar cuantas empanadas quiere: ");
    scanf("%d", &cantemp);
    docena = cantemp / 12;
    indiv = cantemp % 12;
    prectot = (docena * precdoc) + (indiv * precind);
    printf("\nEl precio total de la compra es de: %d", prectot);
    return(0);
}