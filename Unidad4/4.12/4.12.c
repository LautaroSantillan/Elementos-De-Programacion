// 4.12. Ingresar el valor de la hora y la cantidad de horas trabajadas por un empleado. Calcular su sueldo tomando
// en cuenta que recibe un premio de $500 si trabajo más de 50 horas y, además, si trabajó más de 150 horas
// se le otorgan $1000 adicionales.
#include <stdio.h>
int main()
{
    int valorH, horasTr, sueldo;
    printf("Ingrese el valor de la hora trabajada: ");
    scanf("%d", &valorH);
    printf("\nIngrese las horas trabajadas: ");
    scanf("%d", &horasTr);
    sueldo=valorH*horasTr;
    if(horasTr>50)
    {
        sueldo+=500;
        if(horasTr>150)
            sueldo+=1000;
    }
    printf("\nSu sueldo mas premios es de %d", sueldo);
}