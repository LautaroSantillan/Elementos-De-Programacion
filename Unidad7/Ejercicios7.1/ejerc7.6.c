/*7.1.6 Ídem ejercicio anterior, pero con código de productos no correlativos de 4 dígitos. Los códigos deben
solicitarse al iniciar el programa mediante la función IngresaCodigos. Luego de la carga determinar:
a. El / los productos del cual se solicitaron mayor cantidad de unidades.
b. El / los productos del cual se solicitaron menos cantidad de unidades.*/
#include <stdio.h>
void IngresaCodigos(int[], int, int, int);
int esDatoVal1(int, int, int);
int BusquedaSec1(int[], int, int);
int IngrDatoVal (int);
int esDatoVal(int, int);
int EstaDentroDelRango(int, int, int);
void ListarProductos(int[], int);
int BuscarMayorCant(int[], int);
int BuscarMenorCant(int[], int);
void MostrarIgualQue(int[], int[], int, int);
int main()
{
    int VCodigo[10], VCantidad[10]={0}, pos, codigo, cantidad, MayorCant, MenorCant;
    IngresaCodigos(VCodigo, 1000, 9999, 10);
    do{
        printf("Ingrese un codigo entre 1000 a 9999 (CERO = Fin): ");
        scanf("%d", &codigo);
    } while (EstaDentroDelRango(codigo, 1000, 9999)== 0 && codigo != 0);
    while(codigo != 0)
    {
        pos=BusquedaSec1(VCodigo, 10, codigo);
        if(pos!=-1)
        {
            printf("Cantidad de productos pedidos: ");
            cantidad=IngrDatoVal(0);
            VCantidad[pos]+=cantidad;
        }
        else
            printf("\nCodigo de producto inexistente\t");
        do{
        printf("Ingrese un codigo entre 1000 a 9999 (CERO = Fin): ");
        scanf("%d", &codigo);
        } while (EstaDentroDelRango(codigo, 1000, 9999)== 0 && codigo != 0);
    }
    ListarProductos(VCodigo,10);
    MayorCant=BuscarMayorCant(VCantidad, 10);
    printf("\nProductos con Mayor cantidad pedida: ");
    MostrarIgualQue(VCodigo, VCantidad, MayorCant, 10);
    MenorCant=BuscarMenorCant(VCantidad, 10);
    printf("\nProductos con Menor cantidad pedida: ");
    MostrarIgualQue(VCodigo, VCantidad, MenorCant, 10);
}
void IngresaCodigos (int V[], int lim1, int lim2, int ce){
    int i, dato;
    printf("Ingrese los codigos de los productos (de 1000 a 9999): ");
    for (i=0; i<ce; i++)
    {
        do{
            scanf("%d", &dato);
        } while (esDatoVal1(dato, lim1, lim2)==0);
        V[i]=dato;
    }
}
int esDatoVal1 (int x, int lim1, int lim2){
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
int BusquedaSec1 (int V[], int ce, int x){
    int i=0;
    while(V[i]!=x&&i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
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
int EstaDentroDelRango(int num, int x, int y){
    if(num>=x&&num<=y)
        return 1;
    else
        return 0;
}
void ListarProductos(int V[], int ce){
    int i;
    printf("\nListado de productos");
    printf("\nOrden\tCodigo del producto");
    for(i=0; i<ce; i++)
        printf("\n%d\t%d", i+1, V[i]);
}
int BuscarMayorCant (int V[], int ce){
    int i, M;
    for(i=0;i<ce;i++)
    {
        if(i==0||V[i]>M)
            M=V[i];
    }
    return M;
}
int BuscarMenorCant (int V[], int ce){
    int i, M;
    for(i=0;i<ce;i++)
    {
        if(i==0||V[i]<M)
            M=V[i];
    }
    return M;
}
void MostrarIgualQue (int VCod[], int VCant[], int x, int ce){
    int i;
    for(i=0;i<ce;i++)
    {
        if(VCant[i]==x)
            printf("\nEl producto: %d con: %d unidades pedidas", VCod[i], x);
    }
}
