#include <stdio.h>
#include <string.h>
void CargaDatos(char[][21], float[], int);
int IngrDatoVal(int, int, int);
int Busqueda(char[][21], char[], int);
void SumFilaEnV(int[], int[][5], int, int);
void SumColEnV(int[], int[][5], int, int);
void Mostrar(char [][21], int[][5], int[], int[], int, int);
int ContarIgualA(int[], int, int);
void CargaVecVta(float[], int[], float[], int);
void OrdenarParal(float[], char[][21], int);
void MostrarVecParal(float[], char[][21], int);
int main()
{
    int Mat[5][5]={{0}}, vTotTour[5]={0}, vTotVend[5]={0}, CodVend, Cant=0, SinVta, Band=0, Max, VendMax, pos;
    float vPrUnit[5], vImpTot[5]={0};
    char vNomTour[5][21], vNomClie[21], vTourEleg[21], vMaxClie[21], vTourMax[21];
    CargaDatos(vNomTour, vPrUnit, 5);
    printf("\nIngresar nombre del cliente: ");
    fflush(stdin);
    gets(vNomClie);
    while(strcmpi(vNomClie, "ultimo")!=0)
    {
        printf("\nIngresar codigo de vendedor, entre 1 y 5: ");
        do{
            scanf("%d", &CodVend);
        }while(IngrDatoVal(1, 5, CodVend)==0);
        printf("\nIngrese el tour elegido: ");
        fflush(stdin);
        gets(vTourEleg);
        pos=Busqueda(vNomTour, vTourEleg, 5);
        if(pos!=-1)
        {
            printf("\nIngrese la cantidad: ");
            do{
                scanf("%d", &Cant);
            }while(Cant<=0);
            Mat[pos][CodVend-1]+=Cant;
            if(Band==0||Cant*vPrUnit[pos]>Max)
            {
                Max=Cant*vPrUnit[pos];
                strcpy(vMaxClie, vNomClie);
                VendMax=CodVend;
                strcpy(vTourMax, vTourEleg);
                Band=1;
            }
        }
        printf("\nIngresar nombre del cliente: ");
        fflush(stdin);
        gets(vNomClie);
    }
    SumFilaEnV(vTotTour, Mat, 5, 5);
    SumColEnV(vTotVend, Mat, 5, 5);
    printf("\nCantidad de tours vendidos por vendedor");
    printf("\nNombre Tour   1   2   3   4   5   Total por Tour");
    Mostrar(vNomTour, Mat, vTotTour, vTotVend, 5, 5);
    SinVta=ContarIgualA(vTotVend, 5, 0);
    printf("\nEl porcentaje de vendedores sin ventas: %d", SinVta*100/25);
    printf("\nEl cliente que realizo la mayor compra %c, eligiendo el tour %c, con el vendedor %d", vMaxClie, vTourMax, VendMax);
    CargaVecVta(vImpTot, vTotTour, vPrUnit, 5);
    OrdenarParal(vImpTot, vNomTour, 5);
    MostrarVecParal(vImpTot, vNomTour, 5);
    return 0;
}
void CargaDatos(char vNTour[][21], float vPUnit[], int ce)
{
    int i;
    float dato;
    for(i=0; i<ce; i++)
    {
        printf("\nIngrese nombre del tour: ");
        fflush(stdin);
        gets(vNTour[i]);
        printf("\nIngrese precio unitario del tour: ");
        do{
            scanf("%f", &dato);
        }while(dato<=0);
        vPUnit[i]=dato;
    }
}
int IngrDatoVal(int lim1, int lim2, int x)
{
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
int Busqueda(char vNTour[][21], char x[], int ce)
{
    int i=0;
    while(strcmpi(vNTour[i], x)!=0&&i<ce)
    {
        i++;
    }
    if(i==ce)
        return -1;
    else
        return i;
}
void SumFilaEnV(int vTTour[], int Mat[][5], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
            vTTour[i]+=Mat[i][j];
    }
}
void SumColEnV(int vTVend[], int Mat[][5], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
            vTVend[i]+=Mat[i][j];
    }
}
void Mostrar(char vNomT[][21], int Mat[][5], int vTotT[], int vTotV[], int f , int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        printf("\n%c", vNomT[i+1][21]);
        for(j=0; j<c; j++)
            printf("\t%d", Mat[i][j]);
        printf("\t%d", vTotT[i]);
    }
    printf("\n");
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
            printf("\t%d", vTotV[i]);
    }
}
int ContarIgualA(int V[], int ce, int x)
{
    int i, cont;
    for(i=0; i<ce; i++)
    {
        if(V[i]==x)
            cont++;
    }
    return cont;
}
void CargaVecVta(float vImpT[], int vTotT[], float vPrUn[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        vImpT[i]=vTotT[i]*vPrUn[i];
}
void OrdenarParal(float vImpT[], char vNomT[][21], int ce)
{
    int i, j, IndMayor, aux;
    char auxCH;
    for(i=0; i<ce; i++)
    {
        IndMayor=i;
        for(j=i+1; j<=ce; j++)
        {
            if(vImpT[j]>vImpT[IndMayor])
                IndMayor=j;
        }
        if(i!=IndMayor)
        {
            aux=vImpT[i];
            vImpT[i]=vImpT[IndMayor];
            vImpT[IndMayor]=aux;
            strcpy(auxCH, vNomT[i]);
            strcpy(vNomT[i], vNomT[IndMayor]);
            strcpy(vNomT[IndMayor], auxCH);
        }
    }
}
void MostrarVecParal(float vImpT[], char vNomT[][21], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        printf("\n%c\t%d", vNomT[i][21], vImpT[i]);
}
