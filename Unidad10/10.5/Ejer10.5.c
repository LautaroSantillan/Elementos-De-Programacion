/*Se dispone de un archivo llamado (Stock.dat) que contiene la informaci�n de los 10 productos que vende una f�brica. En el archivo se guarda:

 �  C�digo de art�culo (entero)
 �  Descripci�n (50 caracteres m�ximo)
 �  Stock (entero)

Luego se ingresan por teclado las ventas a realizar indicando:

 �  C�digo de art�culo
 �  Cantidad

La carga por teclado de las ventas finaliza con un c�digo de art�culo igual a 0.

Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino hay stock se debe vender lo que
quede disponible y grabar un registro en un archivo Faltantes.dat con la cantidad que no pudo venderse, dicho registro debe contener:

 �  C�digo de art�culo
 �  Cantidad

Se genera un registro por cada venta que no pudo concretarse, pudiendo quedar en el archivo varios registros faltantes del mismo producto. Al
finalizar actualizar el archivo Stock.dat con el stock actualizado luego de procesar las ventas.*/
//INCLUDES////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ESTRUCTURAS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
                int codArt;
                char description[51];
                int stock;
                }T_Sto;
//
typedef struct {
                int codArt;
                int cantidad;
                }T_Falt;
//PROTOTIPADO FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CargaArch(T_Sto[], int);
void ProcesarArch(T_Sto[], int);
void GrabarArch(T_Sto[], int);
int IngrDatoVal(int);
int Busqueda(T_Sto[], int, int);
//MAIN////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    T_Sto VSto[10];
    CargaArch(VSto, 10);
    ProcesarArch(VSto, 10);
    GrabarArch(VSto, 10);
    printf("\n\n");
    return 0;
}
//DECLARACION FUNCIONES///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CargaArch(T_Sto V[], int ce)
{
    FILE *pf;
    T_Sto aux;
    int i=0;
    pf=fopen("STOCK.dat", "rb");
    if(pf==NULL)
    {
        printf("\nNo se pudo abrir el archivo STOCK.dat");
        exit(1);
    }
    fread(&aux, sizeof(T_Sto), 1, pf);
    while(!feof(pf) && i<ce)
    {
        V[i]=aux;
        i++;
        fread(&aux, sizeof(T_Sto), 1, pf);
    }
    fclose(pf);
}
void ProcesarArch(T_Sto V[], int ce)
{
    FILE *pf, *sf;
    T_Falt auxFalt;
    int pos, cod, cantVta;
    //Apertura Archivos
    pf=fopen("STOCK.dat", "rb");
    if(pf==NULL)
    {
        printf("\nNo se pudo abrir el archivo STOCK.dat");
        exit(1);
    }
    sf=fopen("FALTANTES.dat", "wb");
    if(sf==NULL)
    {
        printf("\nNo se pudo abrir el archivo FALTANTES.dat");
        exit(1);
    }
    //Proceso
    printf("\nIngresar el codigo de articulo: ");
    cod=IngrDatoVal(0);
    while(cod!=0) //WHILE con condicion de fin
    {
        pos=Busqueda(V, ce, cod); //Busqueda del producto
        if(pos!=-1)
        {
            printf("\nDel producto %d, ingresar la cantidad vendida de este: ", cod);
            do{
                scanf("%d", &cantVta);
            }while(cantVta<=0);
            if(V[pos].stock>cantVta) //Verifica si el stock es mayor a la cantidad pedida
                V[pos].stock-=cantVta;
            else
                auxFalt.cantidad=cantVta;
                auxFalt.codArt=cod;
                fwrite(&auxFalt, sizeof(T_Falt), 1, sf);
        }
        printf("\nIngresar el codigo de articulo: ");
        cod=IngrDatoVal(0);
    }
}
void GrabarArch(T_Sto V[], int ce)
{
    FILE *pf;
    int i=0;
    pf=fopen("STOCK.dat", "wb");
    if(pf==NULL)
    {
        printf("\nNo abrio el archivo STOCK.dat");
        exit(1);
    }
    for(i=0; i<ce; i++)
        fwrite(&V[i], sizeof(T_Sto), 1, pf);
    fclose(pf);

}
//FUNCIONES COMPLEMENTARIAS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int IngrDatoVal(int lim)
{
    int dato;
    do{
        scanf("%d", &dato);
    }while(dato<lim);
    return dato;
}
int Busqueda(T_Sto V[], int ce, int x)
{
    int i=0;
    while(V[i].codArt!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}
