// 4.10. Confeccionar un programa que permita convertir grados sexagesimales a radianes y 
// viceversa, según el valor de un código que se ingresa junto al valor. Si código = 1 se 
// ingresan grados, si es 2 se ingresan radianes.
// 1 radian = 180/π grados
// 1 grado = π/180 radianes
#include <stdio.h>
int main ()
{
    int cod; float val1, result;
    const float pi = 3.1416;
    printf("Ingrese un valor: ");
    scanf("%f", &val1);
    printf("\nIngrese un codigo, 1 o 2: ");
    scanf("%d", &cod);
    if(cod==1)
    {
        result=val1*180/pi;
        printf("\n%.2f grados", result);
    }
    else
    {
        if(cod==2)
        {
            result=val1*pi/180;
            printf("\n%.2f radianes", result);
        }
    }
}