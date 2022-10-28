//ORDENAR DE MENOR A MAYOR "<"
//ORDENAR DE MAYOR A MENOR ">"
#include <stdio.h>
void ordenar(int[], int);
int main()
{
    int vNum[10]={0}, i, j;
    printf("Ingresar numeros al vector: ");
    for(i=0; i<10; i++)
        scanf("%d", &vNum[i]);
    ordenar(vNum, 10);
    for(j=0; j<10; j++)
        printf("\n%d", vNum[j]);
}
void ordenar(int v[], int ce)
{
    int i, j, indMenor, aux;
    for(i=0; i<ce; i++)
    {
        indMenor=i;
        for(j=i+1; j<ce; j++)
        {
            if(v[j]>v[indMenor])
                indMenor=j;
        }
        if(indMenor!=i)
        {
            aux=v[i];
            v[i]=v[indMenor];
            v[indMenor]=aux;
        }
    }
}
