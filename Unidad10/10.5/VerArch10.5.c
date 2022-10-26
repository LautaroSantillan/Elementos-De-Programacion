#include<stdio.h>
#include<stdlib.h>
//STRUCTS///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int codArt;
                char description[51];
                int stock;
                }T_Sto;
typedef struct {
                int codArt;
                int cantidad;
                }T_Falt;
//PROTOTIPADO DE FUNCIONES/////////////////////////////////////////////////////////////////////////////////////////
void MostrarArchivo1();
void MostrarArchivo2();
//MAIN/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    MostrarArchivo1();
    printf("\n\n");
    MostrarArchivo2();
    printf("\n\n");

    return 0;
}
//DECLARACIÓN FUNCIONES//////////////////////////////////////////////////////////////////////////////////////////////
void MostrarArchivo1()
{
    T_Sto aux;
    FILE *pf;
    pf=fopen("STOCK.dat", "rb");
    if(pf==NULL)
    {
        printf("\nERROR al abrir el archivo STOCK.dat***");
        exit(1);
    }
    printf("\nCODIGO ARTICULO\tDESCRIPCION\t\t\tSTOCK");
    fread(&aux, sizeof(T_Sto), 1, pf);
    while(!feof(pf))
    {
        printf("\n%d\t\t%s\t\t%d", aux.codArt, aux.description, aux.stock);
        fread(&aux, sizeof(T_Sto), 1, pf);
    }
    fclose(pf);
}
////////////////////////////////////////////////////////////////////////////////////
void MostrarArchivo2()
{
    T_Falt aux;
    FILE *pf;
    pf=fopen("FALTANTES.dat", "rb");
    if(pf==NULL)
    {
        printf("\nERROR al abrir el archivo Faltantes.dat***");
        exit(1);
    }
    printf("\nCODIGO ARTICULO\tCANTIDAD");
    fread(&aux, sizeof(T_Falt), 1, pf);
    while(!feof(pf))
    {
        printf("\n%d\t\t%d", aux.codArt, aux.cantidad);
        fread(&aux, sizeof(T_Falt), 1, pf);
    }
    fclose(pf);
}
