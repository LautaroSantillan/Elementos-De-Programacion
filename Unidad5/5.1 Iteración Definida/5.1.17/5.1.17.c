// 5.1.17 Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el código del artículo más caro y el
// precio del más barato. NOTA: todos los artículos tienen precios distintos.
#include <stdio.h>
int main ()
{
    int i, cantArt, codArt, precio, codArtMayor=0, codArtMenor=0, precioMayor=0, precioMenor=0;
    printf("Ingrese la cantidad de articulos: ");
    scanf("%d", &cantArt);
    for(i=1; i<=cantArt; i++)
    {
        printf("\nIngrese el codigo del articulo: ");
        scanf("%d", &codArt);
        printf("\nIngrese el precio del articulo: ");
        scanf("%d", &precio);
        if(precio>precioMayor)
        {
            precioMayor=precio;
            codArtMayor=codArt;
        }
        else
        {
            precioMenor=precio;
            codArtMenor=codArt;
        }
    }
    printf("\nEl articulo: %d, que vale: %d es el producto mas caro. \nEl articulo: %d, que vale: %d es el producto mas barato\n", codArtMayor, precioMayor, codArtMenor, precioMenor);
}