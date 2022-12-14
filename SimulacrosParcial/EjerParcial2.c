/*Ejercicio Integrador NO obligatorio Archivos con corte de control

La empresa San Luis, conocida por su sigla ?ESaL?, dedicada a la venta de hidrocarburos, posee 5
divisiones cada una dedicada a un rubro espec?fico de la actividad y requiere una serie de informes de
su divisi?n ?GAS?. Nos encomiendan elaborar un informe referido a la venta individual de cada uno de
sus posibles 20 vendedores como m?ximo para esa divisi?n.
Para ello se cuenta con un archivo llamado ?VENDEGAS? que contiene datos actualizados a diciembre
del a?o anterior al a?o que se desea procesar (A?o de proceso 2021):

? DNI del vendedor.
? Nombre y apellido (m?ximo 50 caracteres)
? A?o de ingreso a la empresa (obviamente menor al a?o de proceso)

Otro archivo, llamado ?ESALGAS?, contiene los registros de cada venta de todos los vendedores, sin
importar la divisi?n de pertenencia, del a?o en estudio (2021), ordenado por DNI del vendedor:

? DNI del vendedor
? Fecha de venta (Estructura con D-M-A)
? Importe
? Divisi?n (alfanum?rico 15 caracteres).
No se conoce cantidad de registros de ESALGAS.

Se pide:

1) Es posible que en ESALGAS figure un vendedor no cargado en el archivo VENDEGAS porque ingres? el
a?o de an?lisis. En este caso debemos solicitar nombre y apellido del mismo para completar los datos e
ingresarlo al staff (s?lo si pertenece a la divisi?n GAS).

2) El registro que motiv? el alta del nuevo vendedor se guardar? en el archivo ?NUEVOS? creado a este fin.

3) Al finalizar el proceso completo se debe actualizar el archivo VENDEGAS para que incluya a los nuevos
vendedores sabiendo que nunca pasar? que se pase del l?mite de 20 vendedores (Agregar los registros
faltantes sin comenzar a generar nuevamente el archivo).

4) Emitir un listado por vendedor indicando si realiz? o no ventas en cada mes con el siguiente formato
S (SI) y N (NO):
            Vendedor/Mes    1   2   3 ? 12
            Carlos Garc?a   S   S   N   S
            Rodolfo P?es    N   S   S   S
            ?
            Maria Esp?sito  N   N   N   S

5) Generar un nuevo archivo llamado ?CAPACITAR? con el siguiente dise?o:

? Nombre y Apellido
? Mes (con la cantidad de meses que no realiz? ventas)
El mismo debe contener a todos los vendedores que en m?s de tres meses no cuenten con ventas
(Tener en cuenta el listado del punto 4) sin incluir a aquellos que ingresaron el a?o de estudio.

6) Informar la cantidad y el importe vendido por cada vendedor, mostrando el DNI del mismo, en la divisi?n GAS.*/
//INCLUDE////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//STRUCTS////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int DNI;
                char NomyApe[51];
                int a?oIngreso;
                }T_Vendedores;

typedef struct {
                int dia;
                int mes;
                int anio;
                }T_Fecha;

typedef struct {
                int DNI;
                T_Fecha fecha;
                float importe;
                char division[16];
                }T_Venta;

typedef struct {
                char NomyApe[51];
                int mes;
                }T_Cap;
//PROTIPADO FUNCIONES////////////////////////////////////////////////////////////////////////////////////////////
int CargaArch[T_Vendedores[], int);
int Busqueda(T_Vendedores[], int, int);

//MAIN///////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    T_Vendedores vVendedores[20];
    T_Vendedores auxVend;
    T_Venta auxVta;
    T_Cap auxCap;
    int cant, pos;
    char nomVend[51];
    cant=CargaArch(vVendedores, 20); //Obtener la cantidad exacta de vendedores
    //Apertura Archivos
    FILE *vta, *esal, *nuev, *capa;
    vta=fopen("VENDEGAS.dat", "wb"); //Archivo VENDEGAS
    if(vta==NULL)
    {
        printf("\nError al abrir el archivo VENDEGAS.dat");
        exit(1);
    }
    esal=fopen("ESALGAS.dat", "rb"); //Archivo ESALGAS
    if(esal==NULL)
    {
        printf("\nError al abrir el archivo ESALGAS.dat");
        exit(1);
    }
    nuev=fopen("NUEVOS.dat", "wb"); //Archivo NUEVOS
    if(nuev==NULL)
    {
        printf("\nError al abrir el archivo NUEVOS.dat");
        exit(1);
    }
    capa=fopen("CAPACITAR.dat", "wb"); //Archivo CAPACITAR
    if(capa==NULL)
    {
        printf("\nError al abrir el archivo CAPACITAR.dat");
        exit(1);
    }
    fread(%auxVta, sizeof(T_Venta), 1, esal);
    while(!feof(esal))
    {
        pos=Busqueda(vVendedores, cant, auxVta.DNI); //Busqueda del vendedor
        if(pos!=-1)
        {

        }
        else
        {
            if(strcmpi(auxVta.division, "GAS")==0) //Si el vendedor no fue encontrado y pertenege a division "GAS"
            {
                printf("\nIngrese el nombre y apellido del vendedor: ");
                scanf("%c", &nomVend);
                auxVend.NomyApe=nomVend;
                fwrite(&auxVend, sizeof(T_Vendedores), 1, nuev);
            }
        }
        fread(%auxVta, sizeof(T_Venta), 1, esal);
    }
}
//DESARROLLO FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////
int CargaArch(T_Vendedores V[], int ce)
{
    int i=0;
    FILE *pf;
    T_Vendedores aux;
    pf=fopen("VENDEGAS.dat", "rb");
    if(pf==NULL)
    {
        printf("\nError al abrir el archivo VENDEGAS.dat");
        exit(1);
    }
    fread(&aux, sizeof(T_Vendedores), 1, pf);
    while(!feof(pf))
    {
        V[i]=aux;
        i++;
        fread(&aux, sizeof(T_Vendedores), 1, pf);
    }
    fclose(pf);
    return i;
}
//FUNCIONES COMPLEMENTARIAS//////////////////////////////////////////////////////////////////////////////////////
int Busqueda(T_Vendedores V[], int ce, int x)
{
    int i=0;
    while(V[i]!=x && i<ce)
        i++
    if(i==ce)
        return -1;
    else
        return i;
}
