/*10.1. Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//ESTRUCTURA////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int dni;
                char ApyNom[81];
                int Nota1, Nota2;
                float Prom;
                }T_Alum;
//PROTOTIPADO DE FUNCIONES//////////////////////////////////////////////////////////////////////////
int esDatoVal(int, int, int);
void GenerarArch();
void Lectura();
//MAIN//////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
    setlocale(LC_ALL, "spanish"); //CONFIGURACIÓN PARA ACEPTAR LA "Ñ" Y LOS ACENTOS
    GenerarArch();
    Lectura();
}
//FUNCIONES/////////////////////////////////////////////////////////////////////////////////////////
void GenerarArch()
{
    T_Alum aux;
    FILE *pf;
    pf=fopen("ALUMNOS.dat", "wb"); //SE ABRE EL ARCHIVO
    if(pf==NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit(1); //CON EXIT SE CIERRA EL PROGRAMA
    }
    printf("\nIngrese Nro. DNI - Cero para terminar...\t");
    scanf("%d", &aux.dni);
    while(aux.dni>0)
    {
        fflush(stdin);
        printf("\nIngrese Apellido y Nombre: ");
        gets(aux.ApyNom);
        printf("\nIngrese la nota del Parcial 1: ");
        scanf("%d", &aux.Nota1);
        printf("\nIngrese la nota del Parcial 2: ");
        scanf("%d", &aux.Nota2);
        if(aux.dni<=99999999&&esDatoVal(aux.Nota1, 1, 10)&&esDatoVal(aux.Nota2, 1, 10))
        {
            aux.Prom=(aux.Nota1+aux.Nota2)/2.; //CON 2. SE CASTEA A FLOAT
            fwrite(&aux, sizeof(T_Alum), 1, pf); //SE GRABA LA INFORMACIÓN (REGISTRO) EN EL ARCHIVO
        }
        else
            printf("\nAlguno de los datos ingresados es erróneo...\t");
        printf("\nIngrese Nro. DNI - Cero para terminar...\t");
        scanf("%d", &aux.dni);
    }
    fclose(pf);
}
void Lectura()
{
    T_Alum reg;
    FILE *arch;
    arch=fopen("ALUMNOS.dat", "rb");
    if(arch==NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit(1); //CON EXIT SE CIERRA EL PROGRAMA
    }
    printf("\nDNI\tAPELLIDO Y NOMBRE\tNOTA P1\tNOTA P2\tPROMEDIO");
    fread(&reg, sizeof(T_Alum), 1, arch);
    while(!feof(arch))
    {
        printf("\n%d\t%s\t%d\t%d\t%.2f", reg.dni, reg.ApyNom, reg.Nota1, reg.Nota2, reg.Prom);
        fread(&reg, sizeof(T_Alum), 1, arch);
    }
    fclose(arch);
    printf("\n\n\n");
}
//FUNCIONES ADICIONALES////////////////////////////////////////////////////////////////////////////
int esDatoVal(int Nota, int lim1, int lim2)
{
    if(Nota>=lim1&&Nota<=lim2)
        return 1;
    else
        return 0;
}
