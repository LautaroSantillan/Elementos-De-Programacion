/*10.21.Un banco tiene el archivo secuencia SALDOS, con los saldos de sus casi 20.000 clientes de caja de ahorro,
al inicio del mes. Cada registro tiene los siguientes datos:
• Número de caja de ahorro (entero, de 6 cifras)
• Apellido y nombre (alfanuméricos de 30 caracteres)
• Saldo (real, mayor o igual a cero)
Existe, además, un segundo archivo secuencial con los movimientos del mes, MOVI, ordenado por sucursal
del banco, Cada registro contiene:
• Sucursal del banco (entero de 4 cifras no correlativos)
• Número de cuenta de ahorro
• Mes (entero)
• Día (entero)
• Código de Operación (entero 1: depósito (suma al saldo); 2: extracción (resta al saldo))
• Importe (real, mayor que cero)
En el caso de las extracciones, antes de proceder a realizar la resta del importe al saldo, evaluar si éste es
mayor al importe (no puede quedar saldo negativo en la Caja de Ahorro). En este caso, guardar en el archivo
SIN_SALDO los datos que vienen en el archivo MOVI.
Confeccionar un programa para que:
a. Se actualice el archivo SALDOS con los movimientos registrados.
b. Imprima un listado con las cuentas que en el mes han realizado más de 5 extracciones.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//STRUCTS///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct{
                int cah;
                char ApyNom[31];
                float sdo;
                }T_Sdo;

typedef struct{
                int suc;
                int nca;
                int mes;
                int dia;
                int cop;
                float imp;
                }T_Mov;
//PROTOTIPADO DE FUNCIONES/////////////////////////////////////////////////////////////////////////////////////////
int CargarArch(T_Sdo[], int);
void ProcesarArch(T_Sdo[], int[], int);
void GrabarArch(T_Sdo[], int);
void MostrarMayorQue(T_Sdo[], int[], int, int);
int Busqueda(T_Sdo[], int, int);
//MAIN/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int VExt[20000]={0}, cant;
    T_Sdo VSal[20000];
    cant=CargarArch(VSal, 20000);
    ProcesarArch(VSal, VExt, cant);
    GrabarArch(VSal, cant);
    printf("\nLas cuentas que en el mes realizaron mas de 5 extracciones son: ");
    MostrarMayorQue(VSal, VExt, cant, 5);
    printf("\n\n\n");

    return 0;
}
//DECLARACIÓN FUNCIONES//////////////////////////////////////////////////////////////////////////////////////////////
int CargarArch(T_Sdo V[], int ce)
{
    FILE *pf;
    T_Sdo aux;
    int i=0;
    pf=fopen("SALDOS", "rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    fread(&aux, sizeof(T_Sdo), 1, pf);
    while(!feof (pf) && i<ce)
    {
        V[i]=aux;
        i++;
        fread(&aux, sizeof(T_Sdo), 1, pf);
    }
    fclose(pf);
    return i;
}
void ProcesarArch(T_Sdo V[], int Extr[], int ce)
{
    FILE *pf, *ss;
    T_Mov aux;
    int pos;
    pf=fopen("MOVI", "rb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    ss=fopen("SIN_SALDO", "wb");
    if(ss==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    fread(&aux, sizeof(T_Mov), 1, pf);
    while(!feof(pf))
    {
        pos=Busqueda(V, ce, aux.nca);
        if(pos!=-1)
        {
            if(aux.cop==1)
                V[pos].sdo+=aux.imp;
            else
            {
                if(V[pos].sdo>=aux.imp)
                {
                    V[pos].sdo-=aux.imp;
                    Extr[pos]++;
                }
                else
                    fwrite(&aux, sizeof(T_Mov), 1, ss);
            }
        }
        fread(&aux, sizeof(T_Mov), 1, pf);
    }
    fclose(pf);
    fclose(ss);
}
void GrabarArch(T_Sdo V[], int ce)
{
    int i;
    FILE *pf;
    pf=fopen("SALDOS", "wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo...");
        exit(1);
    }
    for(i=0; i<ce; i++)
        fwrite(&V[i], sizeof(T_Sdo), 1, pf);
    fclose(pf);
}
void MostrarMayorQue(T_Sdo V[], int E[], int ce, int x)
{
    int i;
    for(i=0; i<ce; i++)
    {
        if(E[i]>x)
            printf("\n%d", V[i].cah);
    }
}
int Busqueda(T_Sdo V[], int ce, int x)
{
    int i=0;
    while(V[i].cah!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return 1;
}
