#include <stdio.h>
void cargaVec (int[], int);
void copiaVec (int[], int[], int);
void sumaDosVec (int[], int[], int[], int);
void invierteVec (int[], int[], int);
void imprimeVec (int[], int[], int[], int[], int);
void impPosElemenParVec (int[], int);
void impPosElemenImpVec (int[], int);
int sumaVec (int[], int);
//float promeVec (int[], int);
int contarIgualesVec (int[], int, int);
int main()
{
    int VecA[10], VecB[10], VecC[10], VecD[10], num, suma, cont;
    float prom;
    cargaVec(VecA, 10);
    copiaVec(VecA, VecB, 10);
    sumaDosVec(VecA, VecB, VecC, 10);
    invierteVec(VecA, VecD, 10);
    imprimeVec(VecA, VecB, VecC, VecD, 10);
    impPosElemenParVec(VecA, 10);
    impPosElemenImpVec(VecA, 10);
    suma = sumaVec(VecA, 10);
    //prom = promeVec (VecA, 10);
    printf("\nIngrese un numero para ver si hay uno igual: ");
    scanf("%d", &num);
    cont = contarIgualesVec(VecA, 10, num);
    printf("Hay %d numero/s iguales al ingresado\n", cont);
    return 0;
}
void cargaVec (int V[], int ce)
{
    int dato, i;
    printf("Ingrese un numero entero: ");
    for(i=0; i<ce; i++)
    {
        scanf("%d", &V[i]);
    }
}
void copiaVec (int V1[], int V2[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        V2[i]=V1[i];
}
void sumaDosVec(int V1[], int V2[], int V3[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        V3[i]=V1[i]+V2[i];
}
void invierteVec (int V1[], int V2[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        V2[ce-1-i]=V1[i];
}
void imprimeVec (int V1[], int V2[], int V3[], int V4[], int ce)
{
    int i;
    printf("\nOrden\tVecA\tVecB\tVecC\tVecD");
    for(i=0; i<ce; i++)
        printf("\n%d\t%d\t%d\t%d\t%d\t", i+1, V1[i], V2[i], V3[i], V4[i]);
}
void impPosElemenParVec (int V[], int ce)
{
    int i;
    printf("\nNumero pares:");
    for(i=0; i<ce; i++)
    {
        if(V[i]%2==0)
            printf("\n%d", i+1);
    }
}
void impPosElemenImpVec (int V[], int ce)
{
    int i;
    printf("\nNumero en posiciones impares:");
    for(i=0; i<ce; i+=2)
        printf("\n%d", V[i]);
}
int sumaVec (int V[], int ce)
{
    int i, suma=0;
    for(i=0; i<ce; i++)
        suma+=V[i];
    return suma;
}
/*float promeVec (int V[], int ce)
{
    return (float) sumaVec(int V[], int ce)/ce;
}*/
int contarIgualesVec (int V[], int ce, int n)
{
    int i, cont=0;
    for(i=0; i<ce; i++)
    {
        if(V[i]==n)
            cont++;
    }
    return cont;
}
