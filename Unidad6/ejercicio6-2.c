/*ejercicio 6.2*/

#include <stdio.h>
int LeerYValidar (int, int);
int EstaDentroDelRango (int, int, int);
int main ()
{
    int cont=0, numpar=0, acum=0, contfinal=0, num, x, y, N1, N2, eddr, band;
    float numprom;
    printf("Ingrese numeros enteros entre 100 y 2000 (99-Finaliza)");
    eddr=LeerYValidar(99,2000);
    while(eddr!=99)
    {
        if(EstaDentroDelRango(eddr,100,500)==1)
            cont++;
        if(EstaDentroDelRango(eddr,500,1200)==1)
        {
            if(eddr%2==0)
                numpar++;
        }
        if(EstaDentroDelRango(eddr,1200,2000)==1)
        {
            contfinal++;
            acum+=eddr;
        }
        printf("\nIngrese numeros enteros entre 100 y 2000 (99-Finaliza)");
        eddr=LeerYValidar(99,2000);
    }
    printf("\nCantidad de numeros entre 100 y 500: %d", cont);
    printf("\nCantidad de numeros pares ingresados entre 500 y 1200: %d", numpar);
    if(contfinal>0)
    {
        numprom=(float)acum/contfinal;
        printf("\nPromedio de numeros ingresados entre 1200 y 2000: %.2f", numprom);
    }
    else
        printf("\nNo ingresaron numeros entre 1200 y 2000");
}
int LeerYValidar (int N1, int N2){
    int band, num;
    band=0;
    do{
        if(band==0)
        {
            printf("\nIngrese un valor valido: ");
            band=1;
        }
        else
            printf("\nERROR. Ingrese un valor valido: ");
        scanf("%d", &num);
    }while(EstaDentroDelRango(num, N1, N2)==0);
    return num;
}
int EstaDentroDelRango(int num, int x, int y){
    if(num<x||num>y)
        return 0;
    else
        return 1;
}
