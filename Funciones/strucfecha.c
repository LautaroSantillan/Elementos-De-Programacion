#include <stdio.h>
typedef struct{
                int d;
                int m;
                int a;
              }Fecha;
Fecha leecontrol();
int control(int, int, int);
int main()
{
    Fecha fec;
    fec=leecontrol();
    printf("\nFECHA INGRESADA: %d/%d/%d", fec.d, fec.m, fec.a);
    printf("\n\n\n");
    return 0;
}
Fecha leecontrol()
{
    Fecha fe;
    do{
        printf("\nIngrese una fecha (dia - mes - anio): ");
        scanf("%d %d %d", &fe.d, &fe.m, &fe.a);
    }while(control(fe.d, 1, 30)==0 || control(fe.m, 1, 12)==0 ||
    control(fe.a, 2020, 2022)==0);
    return fe;
}
int control(int x, int lim1, int lim2)
{
    if(x>=lim1 && x<=lim2)
        return 1;
    else
        return 0;
}
