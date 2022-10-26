// 2.1. Se ingresan la cantidad de horas trabajadas y el valor por hora de un empleado. Determinar el sueldo.
#include <stdio.h>
int main ()
{
    int hstrab, hsvalor, sueldo;
    printf("Ingrese cantidad de horas trabajadas: ");
    scanf("%d", &hstrab);
    printf("Ingrese el valor por hora: ");
    scanf("%d", &hsvalor);
    sueldo = hstrab * hsvalor;
    printf("A partir de los datos ingresados, el sueldo es: %d", sueldo);
    return(0);
}