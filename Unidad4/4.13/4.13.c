// 4.13. Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los
// números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Se desea
// confeccionar un programa al que informándole el número de catálogo indique si el artículo es o no
// defectuoso. Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar
// “FUERA DE CATALOGO”.
#include <stdio.h>
int main()
{
    int numcat;
    printf("Ingrese el numero del catalogo: ");
    scanf("%d", &numcat);
    if(numcat>=1200 && numcat<=90000)
    {
        if(12121<=numcat && numcat<=18081 || 30012<=numcat && numcat<=45565 || 67000<=numcat && numcat<=68000)
            printf("\nEl articulo es defectuoso\n");
        else
            printf("\nEl articulo no es defectuoso\n");
    }
    else
        printf("\nFUERA DE CATALOGO\n");
}