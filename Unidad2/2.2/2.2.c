//2.2. Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio.
#include <stdio.h>
int main()
{
    int not1, not2, prom;
    printf("Ingrese su primera nota de examen: ");
    scanf("%d",&not1);
    printf("Ingrese su segunda nota de examen: ");
    scanf("%d", &not2);
    prom = (not1+not2)/2;
    printf("La nota promedio es: %d", prom);
    return(0);
}