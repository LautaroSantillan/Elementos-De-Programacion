/*Ejercicio 10.3
Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual a cada uno de sus productos.

La empresa trabaja con a lo sumo 100 productos que están guardados en el archivo PRODUCTOS.dat con la siguiente estructura:

 •  Código (entero)
 •  Precio (float)
 •  Descripción (de hasta 50 caracteres)

Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación de precios finaliza con un código
de producto igual a 0.

Al finalizar:
a. Actualizar el archivo de productos con los nuevos precios
b. Exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser visualizada directamente utilizando un programa
de planillas de cálculo como por ejemplo el Excel.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ------------- STRUCTS ------------------ */
typedef struct{
                int cod;
                float pre;
                char des[50];
              }T_PROD;
/* ------------- PROTOTIPO ----------------- */
int CargarArch(T_PROD[], int);
int Busqueda(T_PROD[], int, int);
/* ------------- MAIN ------------------ */
int main()
{
    T_PROD Vprod[100];
    FILE *pf, *sf;
    int i, j, newcod, pos, cant;
    float newpr;
    cant=CargaArch(Vprod, 100);
    pf=fopen("PRODUCTOS.dat", "wb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo PRODUCTOS.dat en el MAIN");
        exit(1);
    }
    sf=fopen("PRODUCTOS.csv", "wb");
    if(sf==NULL)
    {
        printf("Error al abrir el archivo PRODUCTOS.xsls en el MAIN");
        exit(1);
    }
    printf("\nIngresar nuevo precio para modificarle a X producto, 0 para FINALIZAR: ");
    do{
        scanf("%f", &newpr);
    }while(newpr<0);
    while(newpr!=0)
    {
        printf("\nIngresar el codigo del producto a modificar: ");
        scanf("%d", &newcod);
        pos=Busqueda(Vprod, 100, newcod);
        if(pos!=-1)
            Vprod[pos].pre=newpr;
        printf("\nIngresar nuevo precio para modificarle a X producto, 0 para FINALIZAR: ");
        do{
            scanf("%f", &newpr);
        }while(newpr<0);
    }
    for(i=0; i<cant; i++)
        fwrite(&Vprod[i], sizeof(T_PROD), 1, pf);
    fclose(pf);
    for(j=0; j<cant; j++)
        fwrite(&Vprod[j], sizeof(T_PROD), 1, sf);
    fclose(sf);
}
/* ------------- FUNCIONES ------------------ */
int CargaArch(T_PROD v[], int ce)
{
    FILE *pf;
    T_PROD aux;
    int i=0;
    pf=fopen("PRODUCTOS.dat", "rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo PRODUCTOS.dat");
        exit(1);
    }
    fread(&aux, sizeof(T_PROD), 1, pf);
    while(!feof(pf) && i<ce)
    {
        v[i]=aux;
        i++;
        fread(&aux, sizeof(T_PROD), 1, pf);
    }
    fclose(pf);
    return i;
}
int Busqueda(T_PROD v[], int ce, int x)
{
    int i=0;
    while(v[i].cod!=x && i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}
