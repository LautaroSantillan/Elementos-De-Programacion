// 4.4. Ingresar 3 valores reales y:
// a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”.
// b. Si los tres son iguales informar “TRES IGUALES .
// c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”.
#include <stdio.h>
int main()
{
    float num1, num2, num3;
    printf("Ingrese el primer numero real: ");
    scanf("%f", &num1);
    printf("\nIngrese el segundo numero real: ");
    scanf("%f", &num2);
    printf("\nIngrese el tercer numero real: ");
    scanf("%f", &num3);
    if(num1>num3&&num2>num3)
        printf("\nMAYORES AL TERCERO");
    else
    {
        if(num1==num2&&num2==num3)
            printf("\nTRES IGUALES");
        else
        {
            if(num1<num3||num2<num3)
                printf("\nALGUNO ES MENOR AL TERCERO");
        }
    }
}