// 2.6. El precio para un vuelo es de $8800 en clase turista y se aplica un incremento del 30% en primera clase.
// Se ingresan la cantidad de pasajes vendidos de clase turista y de primera clase.
// Obtener la recaudación total del vuelo.
#include <stdio.h>
int main()
{
    int pasven1, pasven2, clast, primc, rec;
    printf("Ingrese cantidad de pasajes vendidos en clase turista: ");
    scanf("%d", &pasven1);
    printf("Ingrese cantidad de passajes vendidos de primera clase: ");
    scanf("%d", &pasven2);
    clast = 8800 * pasven1;
    primc = (8800 * 1.3) * pasven2;
    rec = clast + primc;
    printf("La recaudacion total del vuelo es de: %d", rec);
    return(0);
}