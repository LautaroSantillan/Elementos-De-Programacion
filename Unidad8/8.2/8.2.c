// 8.2. Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. Utilizando 
//las funciones de la biblioteca string.h generar un tercer string formado por: NOMBRE, APELLIDO (nombre 
//coma espacio y apellido) y mostrarlo.
#include <stdio.h>
#include <string.h>
int main()
{
    char nomyape[41];
    printf("Ingrese su nombre y apellido: ");
    gets(nomyape); //Este guarda strings después del espacio
    //scanf("%s", &nomyape); //Este guarda hasta el espacio
    printf("\n%s", nomyape);
}