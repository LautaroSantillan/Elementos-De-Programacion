// 5.1.7 Dadas 20 notas y legajos de alumnos de un curso. Determinar:
// a. Cantidad de alumnos aplazados.
// b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha Promocionado”.
#include <stdio.h>
int main ()
{
    int i, nota, cont = 0;
    for(i = 1; i <= 20; i++)
    {
        printf("Ingrese la nota del alumno: ");
        scanf("%d", &nota);
        if(nota < 4)
            cont++;
        else
        {
            if(nota > 7)
                printf("\nEl alumno con legajo %d ha promocionado\n\n", i);
        }
    }
    printf("\nLa cantidad de alumnos aplazados es de: %d\n", cont);
}