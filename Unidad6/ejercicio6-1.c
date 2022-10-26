#include <stdio.h>
int MostrarMenu (int num1, int num2);
int IngresaDatoVal (int lim1, int lim2);
int main ()
{
    int num1, num2, opcion, dato;
    printf("Ingrese dos numeros enteros: ");
    printf("\nIngrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    opcion=MostrarMenu(num1,num2);
    while(opcion!=6)
    {
        switch(opcion)
        {
            case 1: printf("\nLa suma es = %d", num1+num2);
                    break;
            case 2: printf("\nLa resta es = %d", num1-num2);
                    break;
            case 3: printf("\nEl producto es = %d", num1*num2);
                    break;
            case 4: if(num1==0||num2==0)
                        printf("\nImposible dividir por 0");
                    else
                        printf("\nEl cociente es = %.2f", (float)num1/num2);
                    break;
            case 5: printf("\nIngrese dos numeros enteros: ");
                    printf("\nIngrese el primer numero: ");
                    scanf("%d", &num1);
                    printf("Ingrese el segundo numero: ");
                    scanf("%d", &num2);
        }
        opcion=MostrarMenu(num1,num2);
    }
}
int MostrarMenu (int num1, int num2){
    int opcion;
    printf("\nMenu de opciones");
    printf("\n------  --- ------");
    printf("\n1)Sumar \n2)Restar \n3)Multiplicar \n4)Dividir \n5)Ingresar nuevos numeros \n6)Salir");
    printf("\nIngrese la opcion: ");
    opcion=IngresaDatoVal(1,6);
    return opcion;
}
