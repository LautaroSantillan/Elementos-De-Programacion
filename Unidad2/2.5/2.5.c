// 2.5. Conociendo la cantidad de tarros de pintura que existe en un depósito de una pinturería y sabiendo que el
// 50% son tarros de 1Lt, el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la cantidad de tarros de
// 1Lt., 4Lts. Y 20 Lts.
#include <stdio.h>
int main()
{
    int cantIn = 80, cant1, cant4, cant20;
    cant1 = cantIn * 0.5;
    cant4 = (cantIn * 40)/100;
    cant20 = cantIn * 0.2;
    printf("En el deposito hay %d tarros de 1lt, %d de 4lts y %d de 20lts", cant1, cant4, cant20);
    return(0);
}