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
    char codigo[50][6];
    float precio[50];
    char descripcion[50][31];
    int cantUnidVta[50];
    float importeTotal[50];
};
//PROTOTIPADO////////////////////////////////////////////////////////////////////
int BusquedaSecCad(struct TProducto, int, char);
//MAIN///////////////////////////////////////////////////////////////////////////
int main()
{
    struct TProducto prod[50];
    int i=0, j, max=50, cantidad=0, pos, band=0;
    char dato[6];
    printf("Ingrese la descripcion del producto: "); //INGRESO PRODUCTOS
    fflush(stdin);
    gets(prod[i].descripcion);
    while(i<max&&prod[i].descripcion!="FIN")
    {
        printf("Ingrese el codigo del producto (5 caracteres): ");
        fflush(stdin);
        gets(prod[i].codigo);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &prod[i].precio);
        printf("Ingrese la cantidad de unidades vendidas al mes anterior: ");
        scanf("%d", &prod[i].cantUnidVta);
        printf("Ingrese el importe total vendido al mes anterior: ");
        scanf("%f", &prod[i].importeTotal);
        i++;
    }
    printf("Ingrese cantidad pedida este mes, (0 para terminar): "); //CARGA PRODUCTOS
    do{
        scanf("%d", &cantidad);
    }while(cantidad<0);
    while(cantidad!=0)
    {
        printf("Ingrese el codigo del producto: ");
        fflush(stdin);
        gets(dato[6]);
        pos=BusquedaSecCad(prod, i, dato); //LLAMADO A FUNCION
        if(pos!=-1)
        {
            prod.cantUnidVta[pos]+=cantidad;
            prod.importeTotal[pos]+=cantidad*prod.precio[pos];
            band=1;

        }
        else
            printf("Producto Inexistente...");
        printf("Ingrese cantidad pedida (0 para terminar): ");
        scanf("%d", &cantidad);
    }
    if(band==1) //LISTADO
    {
        printf("DESCRIPCION  CANTIDAD UNIDADES VENDIDAS  IMPORTE TOTAL VENDIDO");
        for(j=0;j<i;j++)
            printf("\n%c\t%d\t%f", prod[i].descripcion, prod[i].cantUnidVta, prod[i].importeTotal);
    }

}
//FUNCIONES
int BusquedaSecCad(struct TProducto prod[], int ce, char x[])
{
    int i=0;
    while(strcmpi(prod[i], x)!=0&&i<ce)
    {
        i++;
    }
    if(i==ce)
        return -1;
    else
        return i;
}

