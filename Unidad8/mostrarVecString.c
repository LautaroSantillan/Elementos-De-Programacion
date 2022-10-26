#include <stdio.h>
#include <string.h>
void carga(char[][31], int);
void mostrar(char[][31], int);
int main()
{
    int cant=5;
    char nombres[5][31];
    carga(nombres, cant);
    mostrar(nombres, cant);
    printf("\n");
    return 0;
}
void carga(char vn[][31], int cant)
{
    int i;
    for (i=0; i<cant; i++)
    {
        printf ("Ingrese el nombre Num.%d: ", i+1);
        gets(vn[i]);
    }
}
void mostrar(char vn[][31],int cant)
{
    int i;
    for (i=0; i<cant; i++)
        puts(vn[i]);
}