// 5.1.2 Confeccionar un programa para calcular el valor de la siguiente suma: 
// 100 + 95 + 90 + ... + 50.
#include <stdio.h>
int main()
{
    int i, suma = 0;
    for(i = 100; i >= 50; i+=-5)
    {
        suma += i;
    }
    printf("El resultado final es: %d",suma);
}