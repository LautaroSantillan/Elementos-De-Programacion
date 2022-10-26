#include <stdio.h>
#include <conio.h>
#include <string.h>
struct alumno
{
     char nombre [31];
     int dni;
     int notas[2];
};
int carga(struct alumno[], int);
void listar(struct alumno[], int);
int main()
{
     struct alumno vecAl[50];
     int ca;
     ca = carga(vecAl,50);
     listar(vecAl,ca);
     getch();
     return 0;
}
int carga(struct alumno va[], int max)
{
     int i=0,j;
     printf("Ingrese el dni del alumno (0 para terminar): ");
     scanf("%d", &va[i].dni);
     while (i<max && va[i].dni!=0)
     {
         printf("Ingrese el nombre del alumno:");
         getchar();
         gets(va[i].nombre);
         for (j=0;j<2;j++)
         {
         do
         {
         printf("Ingrese la nota del parcial %d: ", j+1);
         scanf("%d", &va[i].notas[j]);
         }while(va[i].notas[j]<1 || va[i].notas[j]>10);
         }

