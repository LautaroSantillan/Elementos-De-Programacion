#include <stdio.h>
void CargaMat(int[][12], int, int);
int IngrDatoValRango(int, int);
int EsDatoVal1 (int, int, int);
int IngrDatoVal(int);
int EsDatoVal(int, int);
void MostrarMatFila(int[][12], int, int);
void SumarFilaMatEnV(int[][12], int, int, int[]);
void MostrarVec(int[],int);
void SumarColMatEnV(int[][12], int, int, int[]);
int PosicionMax(int[], int);
void MostrarVecM(int[][12], int, int);
int Minimo(int[], int);
void MostrarIgualA(int[], int, int);
int ContarIgualA(int[], int, int);
int main() //Programa Principal
{
    int Mat[5][12]={{0}}, Vsuc[5]={0}, Vrub[12]={0}, posmay, min, sinvta;
    CargaMat(Mat, 5, 12);
    MostrarMatFila(Mat, 5, 12);
    SumarFilaMatEnV(Mat, 5, 12, Vsuc);
    printf("\nVentas por sucursal/es:");
    MostrarVec(Vsuc, 5);
    SumarColMatEnV(Mat, 5, 12, Vrub);
    printf("\nVentas por rubro/s:");
    MostrarVec(Vrub, 12);
    posmay=PosicionMax(Vrub, 12);
    printf("\nRubro más vendido: %d", posmay+1);
    MostrarVecM(Mat, 5, 7);
    min=Minimo(Vsuc, 5);
    printf("\nSucursal/es con menor venta:");
    MostrarIgualA(Vsuc, 5, min);
    sinvta=ContarIgualA(Vrub, 12, 0);
    printf("\nRubro/s sin ventas: %d", sinvta);
}//Funciones
//Cargar Matrices
void CargaMat(int M[][12], int f, int c)
{
    int suc, rub, cant;
    printf("\nIngrese una sucursal: ");
    suc=IngrDatoValRango(0, f);
    while(suc!=0)
    {
        printf("\nIngrese un rubro: ");
        rub=IngrDatoValRango(1, c);
        printf("\nIngrese una cantidad: ");
        cant=IngrDatoVal(-1);
        M[suc-1][rub-1]+=cant;
        printf("\nIngrese otra sucursal: ");
        suc=IngrDatoValRango(0, f);
    }
}
int IngrDatoValRango(int lim1, int lim2)
{
    int dato;
    do{
        scanf("%d", &dato);
    }while(EsDatoVal1(dato, lim1, lim2)==0);
    return dato;
}
int EsDatoVal1 (int x, int lim1, int lim2){
    if(x>=lim1&&x<=lim2)
        return 1;
    else
        return 0;
}
int IngrDatoVal(int lim)
{
    int dato;
    do{
        scanf("%d", &dato);
    }while(EsDatoVal(dato, lim)==0);
    return dato;
}
int EsDatoVal(int x, int lim)
{
    if(x>lim)
        return 1;
    else
        return 0;
}
//Mostrar Matriz Fila
void MostrarMatFila(int M[][12], int f, int c)
{
    int i, j;
    printf("\nSuc/Rub   1   2   3   4   5   6   7   8   9   10  11  12");
    for(i=0; i<f; i++)
    {
        printf("\n%d", i+1);
        for(j=0; j<c; j++)
            printf("\t%d", M[i][j]);
    }
}
//Sumar Matriz Fila
void SumarFilaMatEnV(int M[][12], int f, int c, int V[])
{
    int i, j;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
            V[i]+=M[i][j];
    }
}
//Mostrar Vector
void MostrarVec(int V[], int ce)
{
    int i;
    for(i=0; i<ce; i++)
        printf("\n%d\t%d", i+1, V[i]);
}
//Sumar Matriz Columna
void SumarColMatEnV(int M[][12], int f, int c, int V[])
{
    int i, j, sum;
    for(j=0; j<c; j++)
    {
        sum=0;
        for(i=0; i<f; i++)
            sum+=M[j][i];
        V[j]=sum;
    }
}
//Sacar posicion maxima
int PosicionMax(int V[], int ce)
{
    int i, M, p;
    for(i=0; i<ce; i++)
    {
        if(i==0||V[i]>M)
        {
            M=V[i];
            p=i;
        }
    }
    return p;
}
//Mostrar Vector Matriz de rubro 7
void MostrarVecM(int M[][12], int f, int x)
{
    printf("\nVentas en el rubro 7:");
    int i;
    for(i=0; i<f; i++)
        printf("\n%d\t%d", i+1, M[i][x-1]);
}
//Sacar posicion minima
int Minimo(int V[], int ce)
{
    int i, M;
    for(i=0; i<ce; i++)
    {
        if(i==0||V[i]<M)
            M=V[i];
    }
    return M;
}
//Mostrar Igual A
void MostrarIgualA(int V[], int ce, int x)
{
    int i;
    for(i=0; i<ce; i++)
    {
        if(V[i]==x)
            printf("\n%d", i+1);
    }
}
//Contar igual A
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
