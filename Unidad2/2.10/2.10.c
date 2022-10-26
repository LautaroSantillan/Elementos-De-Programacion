// 2.10. Confeccionar un programa que solicite el ingreso del valor del radio (r) de un círculo y con dicho valor calcule
// la superficie del círculo, la longitud de la circunferencia (perímetro) y el volumen de la esfera.
// Superficie = πr2
// Perímetro = 2πr
// Volúmen = 4/3πr
#include <stdio.h>
int main ()
{
    float r;
    const float pi = 3.1416;
    printf("Ingrese el valor del radio de un circulo: ");
    scanf("%f" , &r);
    printf("\nSuperficie del circulo: %f", pi * r * r);
    printf("\nLongitud de la circunferencia o perimetro: %f", 2 * pi * r);
    printf("\nVolumen de la esfera: %f", 4/3 * pi * r);
    return(0);
}