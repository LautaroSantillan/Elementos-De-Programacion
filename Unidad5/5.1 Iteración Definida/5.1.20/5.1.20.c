// 5.1.20 Ingresar un número entero mayor a 0. Debe dibujar una pirámide con * con tantas filas como el número
// indicado. En cada fila se va incrementando la cantidad de asteriscos de 2 en 2.
// Por ejemplo, si se ingresa el número 5 debe mostrar en pantalla:
//           *
//          ***
//         *****
//        *******
//       *********
#include <stdio.h>
int main()
{
    int num, i, j,k;
    printf("Ingrese un numero entero mayor a 0: ");
    scanf("%d", &num);
    for(i=1; i<=num; i++)
    {
        for(j=1;j<=num-i;j++)
            printf(" ");
        for(k=1;k<=2*i-1;k++)
            printf("*");
        printf("\n");
    }
}