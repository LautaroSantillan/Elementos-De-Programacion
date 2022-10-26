/*9.1. Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES  IMPORTE TOTAL
                VENDIDAS          VENDIDO

XXXXXXX          XXXX           $XXXXX,XX
*/
#include <stdio.h>
#include <string.h>
//DECLARACION ESTRUCTURA/////////////////////////////////////////////////////////
struct TProducto{
    char codigo[6];
    float precio;
    char descripcion[31];
    int cantUnidVta;
    float importeTotal;
};
//PROTOTIPADO////////////////////////////////////////////////////////////////////
int CargaEstructura(struct TProducto prod[], int);
void IngrProduc(struct TProducto prod[], int);
void Listar(struct TProducto prod[], int);
int BusquedaSecCad(struct TProducto prod[], int, char[]);
//MAIN///////////////////////////////////////////////////////////////////////////
int main()
{
    struct TProducto prod[50];
    int ce;
    ce=CargaEstructura(prod, 50);
    IngrProduc(prod, ce);
    Listar(prod, ce);
    return 0;
}
int CargaEstructura(struct TProducto prod[], int max)
{
    int i=0,desc[31];
    printf("Ingrese la descripcion del producto: ");
    fflush(stdin);
    gets(desc);
    while(i<max&& strcmpi(desc,"FIN")!=0)
    {
        strcpy(prod[i].descripcion,desc);
        printf("Ingrese el codigo del producto (5 caracteres): ");
        fflush(stdin);
        gets(prod[i].codigo);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &prod[i].precio);
        printf("Ingrese la cantidad de unidades vendidas al mes anterior: ");
        scanf("%d", &prod[i].cantUnidVta);
        printf("Ingrese el importe total vendido al mes anterior: ");
        scanf("%f", &prod[i].importeTotal);
        printf("\nIngrese la descripcion del producto: ");
        fflush(stdin);
        gets(desc);
        i++;
    }
    return i;
}
void IngrProduc(struct TProducto prod[], int ce)
{
    int cantidad, pos,i;
    char dato[6];
//    for(i=0;i<ce;i++){
//        prod[i].cantUnidVta=0;
//        prod[i].importeTotal=0;
//    }
    printf("Ingrese cantidad pedida de algun articulo (0 para terminar): ");
    scanf("%d", &cantidad);
    while(cantidad!=0)
    {
        printf("Ingrese el codigo de dicho producto: ");
        fflush(stdin);
        gets(dato);
        pos=BusquedaSecCad(prod, ce, dato);
        if(pos!=-1)
        {
            prod[pos].cantUnidVta +=cantidad;
            prod[pos].importeTotal +=cantidad*prod[pos].precio;

        }
        else
            printf("Producto Inexistente...");
        printf("Ingrese cantidad pedida (0 para terminar): ");
        scanf("%d", &cantidad);
    }
}
int BusquedaSecCad(struct TProducto prod[], int ce, char dato[])
{
    int i=0;
    while(strcmpi(prod[i].codigo,dato)!=0 && i<ce)
    {
        i++;
    }
    if(i==ce)
        return -1;
    else
        return i;
}
void Listar(struct TProducto prod[], int ce)
{
    int i;
    printf("\nDESCRIPCION  CANTIDAD UNIDADES VENDIDAS  IMPORTE TOTAL VENDIDO");
    for(i=0;i<ce;i++)
    {
        printf("\n%s\t\t%d\t\t%.2f", prod[i].descripcion, prod[i].cantUnidVta, prod[i].importeTotal);
    }
}
