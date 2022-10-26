/*7.1.1 Ingresar un vector de 10 unidades reales mediante una funci�n llamada CARGA. Luego mediante una
segunda funci�n llamada INVERTIR, generar un segundo vector del mismo tama�o con los elementos ubicados
en el orden inverso al del vector original. Mostrar el vector invertido con una funci�n llamada MOSTRAR.*/
#include <stdio.h>
void CARGA (int[], int);
void INVERTIR (int[], int[], int);
void MOSTRAR (int[], int);
int main()
{
    int Vnumreal[10], Vinvertido[10];
    CARGA(Vnumreal, 10);
    INVERTIR(Vnumreal, Vinvertido, 10);
    MOSTRAR(Vinvertido, 10);
    return 0;
}
void CARGA (int V[], int ce){
    int i;
    printf("Ingrese un numero: ");
    for(i=0; i<ce; i++)
    {
        scanf("%d", &V[i]);
    }
    printf("\nCarga finalizada\n");
}
void INVERTIR (int Vnum[], int Vinv[], int ce){
    int i;
    for(i=0; i<ce; i++)
    {
        Vinv[ce-1-i]=Vnum[i];
    }
}
void MOSTRAR (int V[], int ce){
    int i;
    for(i=0; i<ce; i++)
    {
        printf("\n%d", V[i]);
    }
}
