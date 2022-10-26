/*7.1.5 Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día. Por
cada pedido se recibe:
• Código de producto (de 1 a 10)
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.*/
#include <stdio.h>
int IngresaCodigo (int, int, int);
int esDatoVal1 (int, int, int);
int IngrDatoVal (int);
int esDatoVal (int, int);
void ListarProductos (int[], int);
int main()
{
    int VCantUn[10]={0}, codigo, cantidad;
    printf("Ingrese codigo de producto 1 a 10 (CERO = Fin): ");
    codigo = IngresaCodigo(1, 10, 0);
    while(codigo !=0)
    {
        printf("\nIngrese cantidad de unidades (mayor que CERO): ");
        cantidad = IngrDatoVal(0);
        VCantUn[codigo-1]+=cantidad;
        printf("\nIngrese codigo de producto 1 a 10 (CERO = Fin): ");
        codigo = IngresaCodigo(1, 10, 0);
    }
    ListarProductos(VCantUn, 10);
}
int IngresaCodigo (int lim1, int lim2, int cFin){
    int dato;
    do{
        scanf("%d", &dato);
    } while (esDatoVal1(dato, lim1, lim2)==0 && dato != cFin);
    return dato;
}
int esDatoVal1 (int x, int lim1, int lim2){
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
int IngrDatoVal (int lim){
    int dato;
    do{
        scanf("%d", &dato);
    }while (esDatoVal(dato, lim)==0);
    return dato;
}
int esDatoVal(int x, int lim){
    if(x>lim)
        return 1;
    else
        return 0;
}
void ListarProductos(int V[], int ce){
    int i;
    printf("\nListado de pedidos");
    printf("\nProducto\tCantidad");
    for(i=0; i<ce; i++)
        printf("\n%d\t\t%d", i+1, V[i]);
}
