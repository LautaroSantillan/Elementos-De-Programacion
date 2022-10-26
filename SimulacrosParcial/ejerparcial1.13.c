#include <stdio.h> //Declaracion de Funciones
void CargaFabrica(int[], int);
void CargaProduc(int[], int);
void CargaCosto(int[], int);
void CargaMat(int[][10], int, int, int[], int[]);
int Busqueda(int[], int, int);
int IngrDatoVal(int, int);
int EsDatoVal(int, int);
void MostrarVec(int[], int);
void MostrarMat(int[][10], int, int);
void SumFilaEnVec(int[], int[][10], int, int);
int Maximo(int[], int);
void MostrarIgualA(int[], int, int, int[]);
void SumColEnVec(int[], int[][10], int, int);
int CostxProd(int[], int, int[]);
int main() //Programa Principal
{
    int Mat[5][10]={{0}}, vProd[10], vFabr[5], vCosto[10], vCantS[5]={0}, vCantPr[10]={0}, vCostPr[10]={0}, max, tot;
    CargaFabrica(vFabr, 5);
    CargaProduc(vProd, 10);
    CargaCosto(vCosto, 10);
    CargaMat(Mat, 5, 10, vProd, vFabr);
    printf("\nFabrica/Código");
    MostrarVec(vProd, 10);
    MostrarMat(Mat, 5, 10);
    SumFilaEnVec(vCantS, Mat, 5, 10);
    max=Maximo(vCantS, 5);
    printf("\nLa/Las fábricas que produjeron más cantidad de productos: ");
    MostrarIgualA(vCantS, 5, max, vFabr);
    printf("\nLa/Las fábricas que no produjeron 3 o más productos: ");
    MostrarIgualA(vCantS, 5, 3, vFabr);
    SumColEnVec(vCantPr, Mat, 5, 10);
    tot=CostxProd(vCantPr, 10, vCosto);
    printf("\nEl costo total de los productos fabricados es $%d", tot);
}//Desarrollo de Funciones
//Carga de Datos
void CargaFabrica(int v[], int ce)
{
    int i, dato;
    for(i=0; i<ce; i++)
    {
        do{
            printf("\nCargar numero de fabrica, entre 1000 a 9999: ");
            scanf("%d", &dato);
        }while(dato<1000&&dato>9999);
        v[i]=dato;
    }
}
void CargaProduc(int v[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        v[i]=101+i;
    }
}
void CargaCosto(int v[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        printf("\nCargar costos por producto: ");
        scanf("%d", &v[i]);
    }
}
void CargaMat(int m[][10], int f, int c, int vPr[], int vFab[])
{
    int pos, posf, codf, codpr, cant;
    /*printf("\nIngrese codigo de fábrica: ");
    do{
        scanf("%d", &codf);
        posf=Busqueda(vFab, f, codf);
    }while(posf==-1);*/
    printf("\nIngrese codigo de producto, entre 101 a 110: ");
    codpr=IngrDatoVal(0, 9999);
    while(codpr!=0)
    {
        pos=Busqueda(vPr, c, codpr);
        if(pos!=-1)
        {
            printf("\nIngrese codigo de fábrica: ");
            do{
                scanf("%d", &codf);
                posf=Busqueda(vFab, f, codf);
            }while(posf==-1);
            do{
                printf("\nIngrese cantidad de ese producto fabricados: ");
                scanf("%d", &cant);
            }while(cant<=0);
            m[posf-1][pos]+=cant;
        }
        else
        {
            printf("\nNo existe este producto.");
        }
        codpr=IngrDatoVal(0, 9999);
    }
}
int Busqueda(int v[], int ce, int x)
{
    int i;
    while(v[i]!=x&&i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return i;
}
int IngrDatoVal(int cFin, int lim)
{
    int dato;
    do{
        scanf("%d", &dato);
    }while(EsDatoVal(dato, lim)==0&&dato!=cFin);
    return dato;
}
int EsDatoVal(int x, int lim)
{
    if(x<lim)
        return 1;
    else
        return 0;
}
//Mostrar
void MostrarVec(int v[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        printf("%d", v[i]);
    }
}
void MostrarMat(int m[][10], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
            printf("%d", m[i][j]);
    }
}
void MostrarIgualA(int vCant[], int f, int x, int vFab[])
{
    int i;
    for(i=0; i<f; i++)
    {
        if(vCant[i]==x)
            printf("%d", vFab[i]);
    }
}
//Sumar Fila/Columna en Vectores
void SumFilaEnVec(int v[], int m[][10], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
            v[i]+=m[i][j];
    }
}
void SumColEnVec(int v[], int m[][10], int f, int c)
{
    int i, j;
    for(j=0; j<c; j++)
    {
        for(i=0; i<f; i++)
            v[j]+=m[j][i];
    }
}
//Sacar Maximo
int Maximo(int v[], int f)
{
    int i, m;
    for(i=0; i<f; i++)
    {
        if(i==0||v[i]>m)
            v[i]=m;
    }
    return m;
}
//Sacar costo total
int CostxProd(int vCant[], int c, int vCosto[])
{
    int i, acum;
    for(i=0; i<c; i++)
    {
        acum+=vCant[i]*vCosto[i];
    }
    return acum;
}
