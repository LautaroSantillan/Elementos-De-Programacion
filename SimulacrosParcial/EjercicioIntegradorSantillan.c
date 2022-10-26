/*Ejercicio Integrador NO obligatorio Archivos con corte de control

La empresa San Luis, conocida por su sigla “ESaL”, dedicada a la venta de hidrocarburos, posee 5
divisiones cada una dedicada a un rubro específico de la actividad y requiere una serie de informes de
su división “GAS”. Nos encomiendan elaborar un informe referido a la venta individual de cada uno de
sus posibles 20 vendedores como máximo para esa división.
Para ello se cuenta con un archivo llamado “VENDEGAS” que contiene datos actualizados a diciembre
del año anterior al año que se desea procesar (Año de proceso 2021):

• DNI del vendedor.
• Nombre y apellido (máximo 50 caracteres)
• Año de ingreso a la empresa (obviamente menor al año de proceso)

Otro archivo, llamado “ESALGAS”, contiene los registros de cada venta de todos los vendedores, sin
importar la división de pertenencia, del año en estudio (2021), ordenado por DNI del vendedor:

• DNI del vendedor
• Fecha de venta (Estructura con D-M-A)
• Importe
• División (alfanumérico 15 caracteres).
No se conoce cantidad de registros de ESALGAS.

Se pide:

1) Es posible que en ESALGAS figure un vendedor no cargado en el archivo VENDEGAS porque ingresó el
año de análisis. En este caso debemos solicitar nombre y apellido del mismo para completar los datos e
ingresarlo al staff (sólo si pertenece a la división GAS).

2) El registro que motivó el alta del nuevo vendedor se guardará en el archivo “NUEVOS” creado a este fin.

3) Al finalizar el proceso completo se debe actualizar el archivo VENDEGAS para que incluya a los nuevos
vendedores sabiendo que nunca pasará que se pase del límite de 20 vendedores (Agregar los registros
faltantes sin comenzar a generar nuevamente el archivo).

4) Emitir un listado por vendedor indicando si realizó o no ventas en cada mes con el siguiente formato
S (SI) y N (NO):
            Vendedor/Mes    1   2   3 … 12
            Carlos García   S   S   N   S
            Rodolfo Páes    N   S   S   S
            …
            Maria Espósito  N   N   N   S

5) Generar un nuevo archivo llamado “CAPACITAR” con el siguiente diseño:

• Nombre y Apellido
• Mes (con la cantidad de meses que no realizó ventas)
El mismo debe contener a todos los vendedores que en más de tres meses no cuenten con ventas
(Tener en cuenta el listado del punto 4) sin incluir a aquellos que ingresaron el año de estudio.

6) Informar la cantidad y el importe vendido por cada vendedor, mostrando el DNI del mismo, en la división GAS.*/
//INCLUDE////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//STRUCTS////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int DNI;
                char NomyApe[51];
                int anioIngreso;
                }T_Vendedores;

typedef struct {
                int dia;
                int mes;
                int anio;
                }T_Fecha;

typedef struct {
                int DNI; //Ordenado para corte de control
                T_Fecha fecha;
                float importe;
                char division[16];
                }T_Venta;

typedef struct {
                char NomyApe[51];
                int mes;
                }T_Cap;
//PROTIPADO FUNCIONES////////////////////////////////////////////////////////////////////////////////////////////
int CargaArch(T_Vendedores[], int);
int Busqueda(T_Vendedores[], int, int);
void SumFilaEnV(char[][12], int[], int, int);
void Listado(char [][12], T_Vendedores[], int, int);
void inicializarMatrizChar(char [][12],int,int);
//MAIN///////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    T_Vendedores vVendedores[20];
    T_Venta auxVta;
    T_Cap auxCap;
    int cant, pos, dniAnt, cantVta, vCont[20]={0},i;
    float impVta;
    char nomVend[51], M[20][12];
    inicializarMatrizChar(M,20,12);
    cant=CargaArch(vVendedores, 20); //Obtener la cantidad exacta de vendedores
    //Apertura Archivos
    FILE *vta, *esal, *nuev, *capa;
    vta=fopen("VENDEGAS.dat", "ab"); //Archivo VENDEGAS
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
    fread(&auxVta, sizeof(T_Venta), 1, esal);
    while(!feof(esal))
    {
        dniAnt=auxVta.DNI;
        cantVta=0;
        impVta=0;
        while(!feof(esal) && dniAnt==auxVta.DNI)
        {
            if(strcmpi(auxVta.division,"GAS")==0) //Si el vendedor pertenece a la division GAS
            {
                pos=Busqueda(vVendedores, cant, auxVta.DNI); //Busqueda del vendedor
                if(pos==-1)
                {
                    if(cant<20)
                    {
                        printf("\nIngrese el nombre y apellido del vendedor: ");
                        gets(nomVend);
                        strcpy(vVendedores[cant].NomyApe,nomVend);
                        vVendedores[cant].DNI = auxVta.DNI;
                        vVendedores[cant].anioIngreso = 2021;
                        fwrite(&vVendedores[cant], sizeof(T_Vendedores), 1, vta);
                        fwrite(&auxVta,sizeof(T_Venta),1,nuev);
                        cantVta++;
                        impVta+=auxVta.importe;
                        cant++;
                        M[cant][auxVta.fecha.mes-1]='S';
                    }
                }
                else
                {
                    cantVta++;
                    impVta+=auxVta.importe;
                    M[pos][auxVta.fecha.mes-1]='S';
                }
            }
            fread(&auxVta, sizeof(T_Venta), 1, esal);
        }
        printf("\nEl vendedor con DNI: %d. Ha vendido una cantidad de %d veces, con un importe total de %.2f", dniAnt, cantVta, impVta);
    }
    //Listado y vector para contar los meses que no se vendieron
    printf("\nVendedor/Mes  1   2   3   4   5   6   7   8   9   10  11  12");
    Listado(M, vVendedores, 20, 12);
    SumFilaEnV(M, vCont, 20, 12);
    for(i=0;i<cant;i++){
        if(vCont[i]>3 && vVendedores[i].anioIngreso!=2021)
        {
            strcpy(auxCap.NomyApe,vVendedores[i].NomyApe);
            auxCap.mes=vCont[i];
            fwrite(&auxCap, sizeof(T_Cap), 1, capa);
        }
    }
    //Cierre de archivos
    fclose(vta);
    fclose(esal);
    fclose(nuev);
    fclose(capa);
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
    while(V[i].DNI!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}
void SumFilaEnV(char M[][12], int V[], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            if(M[i][j]=='N')
                V[i]++;
        }
    }
}
void Listado(char M[][12], T_Vendedores vVend[], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        printf("\n%s", vVend[i].NomyApe);
        for(j=0; j<c; j++)
            printf("\t%c", M[i][j]);
    }
}

void inicializarMatrizChar(char ventaPorMes[][12],int f,int c){
    int i,x;
    for(i=0;i<f;i++){
        for(x=0;x<c;x++){
            ventaPorMes[i][x] = 'N';
        }
    }
}
