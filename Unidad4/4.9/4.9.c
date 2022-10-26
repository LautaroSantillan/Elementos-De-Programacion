// 4.9. Confeccionar un programa que permita ingresar un carácter alfanumérico y 
// determine e informe si lo ingresado corresponde a una vocal, con el mensaje “VOCAL”. y su
// correspondiente valor numérico en ASCII.
#include <stdio.h>
int main()
{
    int car, aux;
    printf("Ingrese un caracter: ");
    scanf("%c", &car);
    aux=tolower(car);
    if(aux=='a'|| aux=='e'|| aux=='i'|| aux=='o'|| aux=='u')
    printf("\nIngreso una VOCAL y su valor en ASCII es %d", aux);
}