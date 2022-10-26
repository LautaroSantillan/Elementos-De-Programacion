/*Una empresa */0
#include <stdio.h>
void CargaVec(int[], int);
void CargaMat(int[], int[][10], int, int);
int Busqueda(int[], int, int);
int IngrDatoVal2(int, int);
int EsDatoVal(int, int);
void MostrarVec(int[], int);
void MostrarMat(int[][10], int, int);
int main()
{
    int Mat[24][10]={{0}}, Vart[10]={0};
    printf("Ingresar los codigos de los 10 articulos: ");
    CargaVec(Vart, 10);
    CargaMat(Vart, Mat, 24, 10);
    printf("\nHs/Art");
    MostrarVec(Vart, 10);
    MostrarMat(Mat, 24, 10);
}
void CargaVec(int V[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        scanf("%d", &V[i]);
    }
}
void CargaMat(int V[], int M[][10], int f, int c)
{
    int hora, art, pos, cant;
    printf("\nIngrese una hora: ");
    hora=IngrDatoVal2(0, f);
    while(hora!=0)
    {
        printf("\nIngrese un articulo: ");
        scanf("%d", &art);
        pos=Busqueda(V, c, art);
        if(pos!=-1)
        {
            do{
                printf("\nIngrese una cantidad: ");
                scanf("%d", &cant);
            }while(cant<=0);
            M[hora-1][pos]+=cant;
        }
        else
            printf("\nNo existe");
        printf("\nIngrese una hora: ");
        hora=IngrDatoVal2(0, f);
    }
}
int IngrDatoVal2(int cFin, int lim)
{
    int dato;
    do{
        scanf("%d", &dato);
    }while(EsDatoVal(dato, lim)==0 && dato!=cFin);
    return dato;
}
int EsDatoVal(int x, int lim)
{
    if(x<lim)
        return 1;
    else
        return 0;
}
int Busqueda(int V[], int ce, int x)
{
    int i=0;
    while(V[i]!=x&&i<ce)
        i++;
    if(i==ce)
        return -1;
    else
        return 1;
}
void MostrarVec(int V[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        printf("\t%d", V[i]);
}
void MostrarMat(int M[][10], int f, int c)
{
    int i, j;
    for(i=0; i<f; i++)
    {
        printf("\n%d", i+1);
        for(j=0; j<c; j++)
            printf("\t%d", M[i][j]);
    }
}
