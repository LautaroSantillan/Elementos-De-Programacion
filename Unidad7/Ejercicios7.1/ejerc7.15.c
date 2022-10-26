/*7.1.15 La empresa TODOMODA desea controlar las ventas de sus productos. La empresa vende 200 productos
diferentes. La información de los productos se ingresa por teclado. Cada producto contiene:
• Código de producto (int, 301 y 900).
• Unidades en stock. (int, mayor o igual a 0).
Luego ingresar la información de las ventas diarias, también por teclado. Los datos ingresados son (este
lote de datos finaliza con un código de producto igual a 0):
• Código de producto (int, 301 y 900).
• Cantidad de unidades vendidas (int, 1 y 150).
Se piden procesar las ventas diarias y luego determinar:
a. Informar el stock de cada código de producto, indicando el código de producto y el stock del
mismo.
b. Informar el código del producto que tiene el stock más alto.
c. Informar el código del producto de aquellos que hayan superado el stock promedio.
FUNCIONES:
I. Para controlar los datos ingresados por teclado (la función debe controlar un solo dato).
II. Para informar el punto a).*/
#include <stdio.h>
void IngresaCodigos(int[], int, int, int);
int esDatoVal1(int, int, int);
void IngresaStock(int[], int, int);
int esDatoVal(int, int);
int EstaDentroDelRango(int, int, int);
int BusquedaSec1 (int[], int, int);
int EstaDentroDelRangoVentas(int, int);
int esDatoVal2(int, int, int);
int main()
{
    int VCodigo[10]={0}, VStock[10]={0}, VCantidad[10]={0}, cantidad, pos, codigo;
    IngresaCodigos(VCodigo, 301, 900, 10);
    IngresaStock(VStock, 0, 10);
    do{
        printf("\nIngrese un codigo de producto entre 301 y 900 (CERO = Fin): ");
        scanf("%d", &codigo);
    } while (EstaDentroDelRango(codigo, 1000, 9999)== 0 && codigo != 0);
    while(codigo!=0)
    {
        pos=BusquedaSec1(VCodigo, 10, codigo);
        if(pos!=-1)
        {
            printf("Cantidad de productos vendidos: ");
            cantidad=EstaDentroDelRangoVentas(1, 150);
            VCantidad[pos]+=cantidad;
        }
        else
            printf("\nCodigo de producto inexistente\t");
        do{
        printf("\nIngrese un codigo de producto entre 301 y 900 (CERO = Fin): ");
        scanf("%d", &codigo);
        } while (EstaDentroDelRango(codigo, 301, 900)== 0 && codigo != 0);
    }
}
void IngresaCodigos(int V[], int lim1, int lim2, int ce)
{
    int i, dato;
    printf("Ingrese los codigos de los productos (de 301 a 900): ");
    for(i=0; i<ce; i++)
    {
        do{
            scanf("%d", &dato);
        }while(esDatoVal1(dato, lim1, lim2)==0);
        V[i]=dato;
    }
}
int esDatoVal1(int x, int lim1, int lim2)
{
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
void IngresaStock (int V[], int lim, int ce)
{
    int i, dato;
    printf("\nIngrese las unidades de stock de cada producto (mayor o igual a 0): ");
    for(i=0; i<ce; i++)
    {
        do{
        scanf("%d", &dato);
        }while(esDatoVal(dato, lim)==0);
        V[i]=dato;
    }
}
int esDatoVal(int x, int lim)
{
    if(x>=lim)
        return 1;
    else
        return 0;
}
int EstaDentroDelRango(int num, int x, int y)
{
    if(num>=x&&num<=y)
        return 1;
    else
        return 0;
}
int BusquedaSec1 (int V[], int ce, int x)
{
    int i=0;
    while(V[i]!=x&&i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return 1;
}
int EstaDentroDelRangoVentas(int x, int y)
{
    int dato;
    do{
    scanf("%d", &dato);
    } while (esDatoVal2(dato, x, y)==0);
    return dato;
}
int esDatoVal2 (int dato, int x, int y){
    if(x>=x&&x<=y)
        return 1;
    else
        return 0;
}
